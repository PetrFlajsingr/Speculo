import argparse
import json
from argparse import ArgumentParser
from pathlib import Path
from typing import List, Any


def flatten_list(lst: List[Any]) -> List[Any]:
    return [item for sublist in lst for item in flatten_list(sublist)] if isinstance(lst, list) else [lst]


def process_arguments():
    parser = ArgumentParser()
    parser.add_argument('-p', '--projectname', required=True)
    parser.add_argument('-r', '--projectroot', required=True)
    parser.add_argument('-o', '--outputdir', required=True)
    parser.add_argument('-I', '--includepaths', action='append', nargs='*', default=[])
    parser.add_argument('-H', '--headerfiles', action='append', nargs='*', default=[])
    parser.add_argument('-D', '--defines', action='append', nargs='*', default=[])
    parser.add_argument('-f', '--compilerflags', nargs=argparse.REMAINDER, default=[])
    return parser.parse_args()


def save_output(output: dict, path: str):
    with open(path, 'w') as f:
        json.dump(output, indent=4, fp=f)


def main():
    args = process_arguments()

    def proc_list(lst):
        return sorted(set(flatten_list(lst)))

    if args.includepaths is None:
        args.includepaths = []
    if args.headerfiles is None:
        args.headerfiles = []
    if args.compilerflags is None:
        args.compilerflags = []

    include_paths = proc_list(args.includepaths)
    defines = proc_list(args.defines)
    header_paths = proc_list(args.headerfiles)
    compiler_flags = sorted(list(set(args.compilerflags)))

    output = {
        "project": args.projectname,
        "project_root": args.projectroot,
        "include_paths": include_paths,
        "compiler_flags": compiler_flags,
        "defines": defines,
        "header_paths": header_paths
    }
    out_path = Path(args.outputdir) / f'speculo_{args.projectname}_config.json'
    save_output(output, str(out_path))


if __name__ == '__main__':
    main()
