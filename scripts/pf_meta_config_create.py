import argparse
from argparse import ArgumentParser
import json
from pathlib import Path

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-p', '--projectname', required=True)
    parser.add_argument('-r', '--projectroot', required=True)
    parser.add_argument('-o', '--outputdir', required=True)
    parser.add_argument('-I', '--includepaths', nargs='*', default=[])
    parser.add_argument('-H', '--headerfiles', nargs='*', default=[])
    parser.add_argument('-D', '--defines', nargs='*', default=[])
    parser.add_argument('-f', '--compilerflags', nargs=argparse.REMAINDER)
    args = parser.parse_args()

    if args.includepaths is None:
        args.includepaths = []
    if args.headerfiles is None:
        args.headerfiles = []
    if args.compilerflags is None:
        args.compilerflags = []
    output = {
        "project": args.projectname,
        "project_root": args.projectroot,
        "include_paths": list(set(args.includepaths)),
        "compiler_flags": list(set(args.compilerflags)),
        "defines": list(set(args.defines)),
        "header_paths": list(set(args.headerfiles))
    }
    out_path = Path(args.outputdir) / f'pf_meta_{args.projectname}_config.json'
    with open(out_path, 'w') as f:
        json.dump(output, indent=4, fp=f)
