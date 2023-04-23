/**
 * @file FileLock.hpp
 * @brief 
 * @author PetrFlajsingr
 */

#pragma once

#include <filesystem>

#ifdef _WIN32
#include <Windows.h>
#else// _WIN32
#include <sys/file.h>
#include <unistd.h>
#endif// _WIN32

namespace pf::meta_gen {

    class FileLock {
    public:
        explicit FileLock(std::filesystem::path file) : filePath(std::move(file)) {}

        bool lock() {
#ifdef _WIN32
            handle = CreateFileA(filePath.string().c_str(), GENERIC_WRITE, 0, nullptr, OPEN_ALWAYS, 0, nullptr);
            if (handle == INVALID_HANDLE_VALUE) { return false; }

            OVERLAPPED overlapped = { 0 };
            overlapped.Offset = 0;
            overlapped.OffsetHigh = 0xFFFFFFFF;
            if (!LockFileEx(handle, LOCKFILE_EXCLUSIVE_LOCK, 0, 0, 0xFFFFFFFF, &overlapped)) {
                CloseHandle(handle);
                return false;
            }
#else
            handle = open(filePath.string().c_str(), O_RDWR | O_CREAT, 0666);
            if (handle < 0) { return false; }
            if (flock(handle, LOCK_EX | LOCK_NB) != 0) {
                close(handle);
                handle = -1;
                return false;
            }
#endif
            return true;
        }

        bool unlock() {
#ifdef _WIN32
            OVERLAPPED overlapped = { 0 };
            overlapped.Offset = 0;
            overlapped.OffsetHigh = 0xFFFFFFFF;
            if (handle != INVALID_HANDLE_VALUE) {
                if (UnlockFileEx(handle, 0, 0, 0xFFFFFFFF, &overlapped)) {// unlock the entire file
                    CloseHandle(handle);
                    return true;
                }
                CloseHandle(handle);
            }
#else
            if (handle >= 0) {
                flock(handle, LOCK_UN);
                close(handle);
                return true;
            }
#endif
            return false;
        }

    private:
        std::filesystem::path filePath;

#ifdef _WIN32
        HANDLE handle = nullptr;
#else
        int handle = -1;
#endif
    };

    class FileLockGuard {
    public:
        explicit FileLockGuard(FileLock &l) : lock(l) {
            lock.lock();
        }
        ~FileLockGuard() {
            lock.unlock();
        }

    private:
        FileLock &lock;
    };

}// namespace pf::meta_gen