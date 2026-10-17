#!/usr/bin/env python3
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path


def snippet_paths() -> list[Path]:
    override = os.environ.get("VSCODE_CPP_SNIPPET")
    if override:
        return [Path(override).expanduser()]

    if sys.platform == "darwin":
        return [Path.home() / "Library/Application Support/Code/User/snippets/cpp.json"]
    if os.name == "nt":
        appdata = os.environ.get("APPDATA")
        return [Path(appdata) / "Code/User/snippets/cpp.json"] if appdata else []

    config_home = Path(os.environ.get("XDG_CONFIG_HOME", Path.home() / ".config"))
    return [config_home / "Code/User/snippets/cpp.json"]


def load_include_snippet() -> str:
    paths = snippet_paths()
    snippet_path = next((path for path in paths if path.is_file()), None)
    if snippet_path is None:
        expected = paths[0] if paths else "the VS Code user snippets directory"
        raise FileNotFoundError(
            f"VS Code C++ snippets were not found at {expected}. "
            "Set VSCODE_CPP_SNIPPET to the path of cpp.json."
        )

    try:
        snippets = json.loads(snippet_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        raise ValueError(f"Could not read VS Code snippets from {snippet_path}: {error}") from error
    if not isinstance(snippets, dict):
        raise ValueError(f"VS Code snippets in {snippet_path} must be a JSON object.")

    for snippet in snippets.values():
        if not isinstance(snippet, dict):
            continue
        prefix = snippet.get("prefix")
        if prefix != "include" and not (
            isinstance(prefix, list) and "include" in prefix
        ):
            continue

        body = snippet.get("body")
        if isinstance(body, str):
            return body.rstrip("\n") + "\n"
        if isinstance(body, list) and all(isinstance(line, str) for line in body):
            return "\n".join(body) + "\n"
        raise ValueError(f"The 'include' snippet in {snippet_path} has an invalid body.")

    raise ValueError(f"No snippet with the prefix 'include' was found in {snippet_path}.")


def vscode_cli() -> list[str] | None:
    executable = shutil.which("code")
    if executable:
        return [executable]

    if sys.platform == "darwin":
        app_paths = (
            Path("/Applications/Visual Studio Code.app"),
            Path.home() / "Applications/Visual Studio Code.app",
        )
        for app_path in app_paths:
            cli = app_path / "Contents/Resources/app/bin/code"
            if cli.is_file():
                return [str(cli)]

    return None


def main() -> int:
    import argparse

    parser = argparse.ArgumentParser(
        description="Create ABC A-E C++ files from the VS Code 'include' snippet."
    )
    parser.add_argument("contest", help="ABC contest number, for example 480")
    parser.add_argument(
        "--no-open",
        action="store_true",
        help="Create the files without opening them in VS Code.",
    )
    args = parser.parse_args()

    if (
        not args.contest.isascii()
        or not args.contest.isdecimal()
        or not args.contest.lstrip("0")
    ):
        parser.error("contest must be a positive integer, for example 480")
    contest = args.contest.lstrip("0")

    work_dir = Path(__file__).resolve().parent
    files = [work_dir / f"abc{contest}{letter}.cpp" for letter in "abcde"]
    existing = [path for path in files if path.exists()]
    if existing:
        print("Files already exist; nothing was overwritten:", file=sys.stderr)
        for path in existing:
            print(f"  {path}", file=sys.stderr)
        return 1

    try:
        template = load_include_snippet()
    except (FileNotFoundError, ValueError) as error:
        print(error, file=sys.stderr)
        return 1

    created: list[Path] = []
    try:
        for path in files:
            with path.open("x", encoding="utf-8", newline="\n") as output:
                created.append(path)
                output.write(template)
    except OSError as error:
        cleanup_errors = []
        for path in created:
            try:
                path.unlink(missing_ok=True)
            except OSError as cleanup_error:
                cleanup_errors.append(f"{path}: {cleanup_error}")
        print(f"Could not create the files: {error}", file=sys.stderr)
        for cleanup_error in cleanup_errors:
            print(f"Could not remove a partially created file: {cleanup_error}", file=sys.stderr)
        return 1

    print(f"Created {len(files)} files in {work_dir}:")
    for path in files:
        print(f"  {path.name}")

    if args.no_open:
        return 0

    cli = vscode_cli()
    if cli is None:
        print(
            "Files were created, but the VS Code CLI ('code') was not found. "
            "Install the CLI or rerun with --no-open.",
            file=sys.stderr,
        )
        return 1

    try:
        subprocess.run(
            [*cli, "--reuse-window", *(str(path) for path in files)],
            check=True,
        )
    except (OSError, subprocess.CalledProcessError) as error:
        print(f"Files were created, but VS Code could not open them: {error}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
