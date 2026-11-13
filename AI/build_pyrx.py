# ruff: noqa
"""Build the latest PyRx ARX/BRX/ZRX/GRX module + RxLoader for the CAD hosts.

One command per host (or all at once). Resolves MSBuild via vswhere (or a
known VS 2022/2019 path), builds ``PyRxCore/<core>.vcxproj`` and then
``PyRxLoader/<loader>.vcxproj`` with ``-p:SolutionDir`` set (required for the
``$(SolutionDir)\\Bin\\...`` output layout), and finally verifies the expected
``.arx``/``.brx``/``.zrx``/``.grx`` files landed in ``Bin/<core>/x64/<Config>/``.

Hosts (latest version of each CAD on this machine):
    acad  AutoCAD 2027   PyRx26.0   + RxLoader26.0   (.arx)  needs env ARX2027
    bcad  BricsCAD V27   PyRxV27.0  + RxLoaderV27.0  (.brx)  needs env BRX27
    zcad  ZWCAD 2027     PyRxZ27.0  + RxLoaderZ27.0  (.zrx)  needs env ZRX2027
    gcad  GstarCAD 2027  PyRxG27.0  + RxLoaderG27.0  (.grx)  needs env GRX27

Usage (run from anywhere; paths resolve relative to this file):
    python AI/build_pyrx.py                 # build ALL hosts, Debug|x64
    python AI/build_pyrx.py acad            # AutoCAD 2027 only
    python AI/build_pyrx.py bcad zcad       # any subset
    python AI/build_pyrx.py acad --config Release
    python AI/build_pyrx.py acad --rebuild  # clean + rebuild
    python AI/build_pyrx.py acad --dry-run  # print the commands only
    python AI/build_pyrx.py --msbuild "C:\\...\\MSBuild.exe" -j 8

Notes:
- Builds are incremental: if no headers changed, a rebuild finishes in seconds.
- MSBuild output streams live to the console.
- Exit code: 0 = every requested host built and its outputs were verified;
  1 = build failed or outputs missing; 2 = environment problem (MSBuild/env var).
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO_ROOT = HERE.parent

HOSTS: dict[str, dict] = {
    "acad": dict(label="AutoCAD 2027", core="PyRx26.0", loader="RxLoader26.0", ext=".arx", sdk_env="ARX2027"),
    "bcad": dict(label="BricsCAD V27", core="PyRxV27.0", loader="RxLoaderV27.0", ext=".brx", sdk_env="BRX27"),
    "zcad": dict(label="ZWCAD 2027", core="PyRxZ27.0", loader="RxLoaderZ27.0", ext=".zrx", sdk_env="ZRX2027"),
    "gcad": dict(label="GstarCAD 2027", core="PyRxG27.0", loader="RxLoaderG27.0", ext=".grx", sdk_env="GRX27"),
}

VS_EDITIONS = ("Community", "Professional", "Enterprise", "BuildTools")
VS_INSTALL_ROOTS = (
    Path(r"C:\Program Files\Microsoft Visual Studio"),
    Path(r"C:\Program Files (x86)\Microsoft Visual Studio"),
)


def _msbuild_candidate(installation_path: str) -> Path | None:
    candidate = Path(installation_path) / "MSBuild" / "Current" / "Bin" / "AMd64" / "MSBuild.exe"
    return candidate if candidate.is_file() else None


def find_msbuild(cli_path: str | None) -> Path:
    """Locate MSBuild.exe: explicit --msbuild, then vswhere, then known VS paths.

    Prefers VS 2022 (v17): the projects pin PlatformToolset v143. Newer VS
    (e.g. v18) also ships v143 but 2022 is the safe default for this repo.
    """
    if cli_path:
        p = Path(cli_path).expanduser()
        if not p.is_file():
            raise SystemExit(f"--msbuild not found: {p}")
        return p

    # 1) vswhere: list all instances with the VC++ workload, prefer v17 (VS 2022).
    vswhere = Path(r"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe")
    if vswhere.is_file():
        try:
            out = subprocess.run(
                [
                    str(vswhere),
                    "-all",
                    "-products", "*",
                    "-requires", "Microsoft.VisualStudio.Component.VC.Tools.x86.x64",
                    "-property", "installationPath",
                    "-property", "installationVersion",
                    "-format", "json",
                ],
                capture_output=True,
                text=True,
                timeout=30,
                check=True,
            ).stdout
            instances = json.loads(out or "[]")

            # Order: VS 2022 (17.x) first, then VS 2026 (18.x), then VS 2019 (16.x).
            def rank(i: dict) -> tuple:
                v = i.get("installationVersion", "0")
                major = int(v.split(".")[0]) if v else 0
                group = {17: 0, 18: 1, 16: 2}.get(major, 3)
                return (group, v)

            instances.sort(key=rank)
            for inst in instances:
                mb = _msbuild_candidate(inst.get("installationPath", ""))
                if mb:
                    return mb
        except (subprocess.SubprocessError, OSError, ValueError):
            pass

    # 2) Known install locations, 2022 first (v143 toolset), then 2019.
    for root in VS_INSTALL_ROOTS:
        for year in ("2022", "2019"):
            for edition in VS_EDITIONS:
                mb = _msbuild_candidate(str(root / year / edition))
                if mb:
                    return mb

    raise SystemExit(
        "Could not find MSBuild.exe (Visual Studio 2022/2019 with the C++ workload).\n"
        "Install the 'Desktop development with C++' workload or pass --msbuild <path>."
    )


def build_command(msbuild: Path, host: dict, proj_dir: str, config: str, platform: str,
                  rebuild: bool, jobs: int | None) -> list[str]:
    """MSBuild invocation for one vcxproj. SolutionDir MUST be absolute + trailing \\."""
    cmd = [
        str(msbuild),
        str(REPO_ROOT / proj_dir),
        "-p:Configuration=" + config,
        "-p:Platform=" + platform,
        "-p:SolutionDir=" + REPO_ROOT.as_posix().replace("/", "\\") + "\\",
        "-m" if jobs is None else f"-maxcpucount:{jobs}",
        "-v:m",
        "-nologo",
    ]
    if rebuild:
        cmd.append("-t:Rebuild")
    return cmd


def run_project(msbuild: Path, host_key: str, host: dict, proj_dir: str, args: argparse.Namespace) -> int:
    cmd = build_command(
        msbuild, host, proj_dir, args.config, args.platform,
        rebuild=args.rebuild, jobs=args.jobs,
    )
    print(f"\n>>> [{host_key}] {proj_dir}  ({args.config}|{args.platform})")
    print("    " + " ".join(f'"{c}"' if " " in c else c for c in cmd))
    if args.dry_run:
        return 0
    t0 = time.time()
    proc = subprocess.run(cmd, cwd=str(REPO_ROOT))  # stream output live to the console
    print(f"    [{host_key}] {proj_dir} finished in {time.time() - t0:.1f}s (exit {proc.returncode})")
    return proc.returncode


def verify_outputs(host_key: str, host: dict, config: str, platform: str) -> list[Path]:
    out_dir = REPO_ROOT / "Bin" / host["core"] / platform / config
    expected = [
        out_dir / (host["core"] + host["ext"]),
        out_dir / (host["loader"] + host["ext"]),
    ]
    missing = [p for p in expected if not p.is_file()]
    if missing:
        print(f"    [{host_key}] MISSING expected outputs:")
        for p in missing:
            print(f"        {p}")
        return expected
    print(f"    [{host_key}] OK -> {out_dir}")
    for p in expected:
        st = p.stat()
        age = time.time() - st.st_mtime
        print(f"        {p.name}  ({st.st_size/1024:.0f} KB, {age:.0f}s old)")
    return expected


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Build the latest PyRx module + RxLoader for the CAD hosts.",
        epilog="Hosts: " + ", ".join(f"{k}={v['label']}" for k, v in HOSTS.items()),
    )
    parser.add_argument("hosts", nargs="*", type=lambda s: s.lower(), choices=sorted(HOSTS),
                        help="which CAD(s) to build, case-insensitive (default: all)")
    parser.add_argument("--config", choices=["Debug", "Release"], default="Debug",
                        help="build configuration (default: Debug)")
    parser.add_argument("--platform", default="x64", help="platform (default: x64)")
    parser.add_argument("--rebuild", action="store_true",
                        help="clean + rebuild instead of incremental build")
    parser.add_argument("--msbuild", default=None, help="explicit path to MSBuild.exe")
    parser.add_argument("-j", "--jobs", type=int, default=None,
                        help="max MSBuild parallelism (default: auto)")
    parser.add_argument("--dry-run", action="store_true", help="print commands, build nothing")
    args = parser.parse_args(argv)

    hosts = args.hosts if args.hosts else list(HOSTS)

    msbuild = find_msbuild(args.msbuild)
    print(f"MSBuild : {msbuild}")
    print(f"Repo    : {REPO_ROOT}")
    print("Hosts   : " + ", ".join(h + " (" + HOSTS[h]["label"] + ")" for h in hosts))
    print(f"Config  : {args.config}|{args.platform}{'  [rebuild]' if args.rebuild else ''}")

    # Pre-check SDK env vars so failures are obvious instead of a cryptic compile error.
    env_problems = []
    for h in hosts:
        sdk = HOSTS[h]["sdk_env"]
        val = os.environ.get(sdk)
        if args.dry_run:
            continue
        if not val:
            env_problems.append(f"    {h}: env var {sdk} is not set")
        elif not Path(val).is_dir():
            env_problems.append(f"    {h}: {sdk}={val} does not exist")
    if env_problems:
        print("\nERROR: SDK environment not ready:")
        print("\n".join(env_problems))
        print("Set them (see BUILDENV.txt) and re-run.")
        return 2

    failures = []
    for h in hosts:
        host = HOSTS[h]
        print(f"\n=== {h}: {host['label']} -> {host['core']}{host['ext']} + {host['loader']}{host['ext']} ===")
        rc = run_project(msbuild, h, host, f"PyRxCore\\{host['core']}.vcxproj", args)
        if rc != 0:
            failures.append(h)
            print(f"    [{h}] BUILD FAILED (core project); skipping loader + verification.")
            continue
        rc = run_project(msbuild, h, host, f"PyRxLoader\\{host['loader']}.vcxproj", args)
        if rc != 0:
            failures.append(h)
            print(f"    [{h}] BUILD FAILED (loader project).")
            continue
        if not args.dry_run:
            verify_outputs(h, host, args.config, args.platform)

    print("\n" + "=" * 60)
    if failures:
        print(f"FAILED : {', '.join(sorted(set(failures)))}")
        return 1
    print(f"SUCCESS: built {len(hosts)} host(s): {', '.join(hosts)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
