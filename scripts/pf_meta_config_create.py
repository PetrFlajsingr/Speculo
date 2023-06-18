import argparse
from argparse import ArgumentParser
import json
from pathlib import Path


def flatten_list(lst) -> list:
    result = []
    for item in lst:
        if isinstance(item, list):
            result.extend(flatten_list(item))
        else:
            result.append(item)
    return result


if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-p', '--projectname', required=True)
    parser.add_argument('-r', '--projectroot', required=True)
    parser.add_argument('-o', '--outputdir', required=True)
    parser.add_argument('-I', '--includepaths', action='append', nargs='*', default=[])
    parser.add_argument('-H', '--headerfiles', action='append', nargs='*', default=[])
    parser.add_argument('-D', '--defines', action='append', nargs='*', default=[])
    parser.add_argument('-f', '--compilerflags', nargs=argparse.REMAINDER)
    args = parser.parse_args()

    if args.includepaths is None:
        args.includepaths = []
    if args.headerfiles is None:
        args.headerfiles = []
    if args.compilerflags is None:
        args.compilerflags = []

    include_paths = list(set(flatten_list(args.includepaths)))
    defines = list(set(flatten_list(args.defines)))
    header_paths = list(set(flatten_list(args.headerfiles)))
    compiler_flags = list(set(args.compilerflags))

    include_paths.sort()
    compiler_flags.sort()
    defines.sort()
    header_paths.sort()

    output = {
        "project": args.projectname,
        "project_root": args.projectroot,
        "include_paths": include_paths,
        "compiler_flags": compiler_flags,
        "defines": defines,
        "header_paths": header_paths
    }
    out_path = Path(args.outputdir) / f'pf_meta_{args.projectname}_config.json'
    with open(out_path, 'w') as f:
        json.dump(output, indent=4, fp=f)
