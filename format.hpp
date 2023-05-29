//
// Created by xflajs00 on 14.03.2023.
//

#ifndef PF_META_FORMAT_H
#define PF_META_FORMAT_H

#include <boost/config.hpp>

#if defined(BOOST_GCC)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Basic/Version.h>
#include <clang/Format/Format.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Rewrite/Core/Rewriter.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/Process.h>

#if defined(BOOST_GCC)
#pragma GCC diagnostic pop
#endif

inline const char *getInValidBOM(llvm::StringRef BufStr) {
    // Check to see if the buffer has a UTF Byte Order Mark (BOM).
    // We only support UTF-8 with and without a BOM right now.  See
    // https://en.wikipedia.org/wiki/Byte_order_mark#Byte_order_marks_by_encoding
    // for more information.
    const char *InvalidBOM = llvm::StringSwitch<const char *>(BufStr)
                                     .StartsWith(llvm::StringLiteral::withInnerNUL("\x00\x00\xFE\xFF"), "UTF-32 (BE)")
                                     .StartsWith(llvm::StringLiteral::withInnerNUL("\xFF\xFE\x00\x00"), "UTF-32 (LE)")
                                     .StartsWith("\xFE\xFF", "UTF-16 (BE)")
                                     .StartsWith("\xFF\xFE", "UTF-16 (LE)")
                                     .StartsWith("\x2B\x2F\x76", "UTF-7")
                                     .StartsWith("\xF7\x64\x4C", "UTF-1")
                                     .StartsWith("\xDD\x73\x66\x73", "UTF-EBCDIC")
                                     .StartsWith("\x0E\xFE\xFF", "SCSU")
                                     .StartsWith("\xFB\xEE\x28", "BOCU-1")
                                     .StartsWith("\x84\x31\x95\x33", "GB-18030")
                                     .Default(nullptr);
    return InvalidBOM;
}

inline clang::FileID createInMemoryFile(llvm::StringRef FileName, llvm::MemoryBuffer *Source, clang::SourceManager &Sources,
                                        clang::FileManager &Files, llvm::vfs::InMemoryFileSystem *MemFS) {
    MemFS->addFileNoOwn(FileName, 0, *Source);
    auto File = Files.getFile(FileName);
    return Sources.createFileID(File ? *File : nullptr, clang::SourceLocation(), clang::SrcMgr::C_User);
}

inline bool fillRanges(llvm::MemoryBuffer *Code, std::vector<clang::tooling::Range> &Ranges) {
    llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem(new llvm::vfs::InMemoryFileSystem);
    clang::FileManager Files(clang::FileSystemOptions(), InMemoryFileSystem);
    clang::DiagnosticsEngine Diagnostics(llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs>(new clang::DiagnosticIDs),
                                         new clang::DiagnosticOptions);
    clang::SourceManager Sources(Diagnostics, Files);
    clang::FileID ID = createInMemoryFile("<irrelevant>", Code, Sources, Files, InMemoryFileSystem.get());

    auto End = Sources.getLocForEndOfFile(ID);
    unsigned Length = Sources.getFileOffset(End);
    Ranges.emplace_back(0, Length);

    return false;
}

inline bool format(llvm::StringRef FileName) {
    // On Windows, overwriting a file with an open file mapping doesn't work,
    // so read the whole file into memory when formatting in-place.
    llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> CodeOrErr = llvm::MemoryBuffer::getFileAsStream(FileName);
    if (std::error_code EC = CodeOrErr.getError()) {
        llvm::errs() << EC.message() << "\n";
        return true;
    }
    std::unique_ptr<llvm::MemoryBuffer> Code = std::move(CodeOrErr.get());
    if (Code->getBufferSize() == 0) return false;// Empty files are formatted correctly.

    llvm::StringRef BufStr = Code->getBuffer();

    const char *InvalidBOM = getInValidBOM(BufStr);

    if (InvalidBOM) {
        llvm::errs() << "error: encoding with unsupported byte order mark \"" << InvalidBOM << "\" detected";
        if (FileName != "-") llvm::errs() << " in file '" << FileName << "'";
        llvm::errs() << ".\n";
        return true;
    }

    std::vector<clang::tooling::Range> Ranges;
    if (fillRanges(Code.get(), Ranges)) return true;
    llvm::StringRef AssumedFileName = FileName;

    llvm::Expected<clang::format::FormatStyle> FormatStyle = clang::format::getLLVMStyle();
    if (!FormatStyle) {
        llvm::errs() << llvm::toString(FormatStyle.takeError()) << "\n";
        return true;
    }
    FormatStyle->ColumnLimit = 120;

    unsigned CursorPosition = 0;
    clang::tooling::Replacements Replaces = sortIncludes(*FormatStyle, Code->getBuffer(), Ranges, AssumedFileName, &CursorPosition);
    auto ChangedCode = clang::tooling::applyAllReplacements(Code->getBuffer(), Replaces);
    if (!ChangedCode) {
        llvm::errs() << llvm::toString(ChangedCode.takeError()) << "\n";
        return true;
    }
    // Get new affected ranges after sorting `#includes`.
    Ranges = clang::tooling::calculateRangesAfterReplacements(Replaces, Ranges);
    clang::format::FormattingAttemptStatus Status;
    clang::tooling::Replacements FormatChanges = reformat(*FormatStyle, *ChangedCode, Ranges, AssumedFileName, &Status);
    Replaces = Replaces.merge(FormatChanges);

    llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem(new llvm::vfs::InMemoryFileSystem);
    clang::FileManager Files(clang::FileSystemOptions(), InMemoryFileSystem);
    clang::DiagnosticsEngine Diagnostics(clang::IntrusiveRefCntPtr<clang::DiagnosticIDs>(new clang::DiagnosticIDs), new clang::DiagnosticOptions);
    clang::SourceManager Sources(Diagnostics, Files);
    clang::Rewriter Rewrite(Sources, clang::LangOptions());
    clang::tooling::applyAllReplacements(Replaces, Rewrite);

    if (Rewrite.overwriteChangedFiles()) return true;
    return false;
}

#endif//PF_META_FORMAT_H
