from __future__ import annotations

import argparse
import enum
import importlib
import importlib.util
import logging
import os
import subprocess
import tempfile
import threading
import typing as t
from pathlib import Path

from .config import TestConfig

if t.TYPE_CHECKING:
    import _typeshed as _t

logger = logging.getLogger("test_runner")

BASE_DIR = Path(__file__).parent  # tests
MAIN_DIR = BASE_DIR.parent  # git repo dir


ACAD_EXE = os.getenv("ACAD_EXE", None)
BCAD_EXE = os.getenv("BCAD_EXE", None)
GCAD_EXE = os.getenv("GCAD_EXE", None)
ZCAD_EXE = os.getenv("ZCAD_EXE", None)


class Host(str, enum.Enum):
    exe: Path | None

    def __new__(cls, value: str, exe: _t.StrPath | None):
        obj = str.__new__(cls, value)
        obj._value_ = value
        obj.exe = Path(exe) if exe is not None else None
        return obj

    ACAD = "AutoCAD", ACAD_EXE
    BCAD = "BricsCAD", BCAD_EXE
    GCAD = "GstarCAD", GCAD_EXE
    ZCAD = "ZwCAD", ZCAD_EXE


def get_cad_scr(cfg_path: Path, debug=False):
    host_runner_spec = importlib.util.find_spec("tests.host_runner")
    assert host_runner_spec is not None
    host_runner_file = host_runner_spec.origin
    assert host_runner_file is not None
    s = (
        # fix sys.path
        "PYCMDPROMPT\n"
        + "import sys\n"
        + f"sys.path.insert(0, {str(MAIN_DIR)!r})\n"
        + "quit\n"  # end PYCMDPROMPT
        # load python module
        + f'(adspyload "{Path(host_runner_file).as_posix()}")\n'
        + ("DEBUG\n" if debug else "")
        # run tests
        + f"RUN_TESTS\n{cfg_path.as_posix()}\n"
        # quit app
        + ("_QUIT\n" if not debug else "")
    )
    return s


def start_host(host: Host, scr_path: Path):
    try:
        res = subprocess.run([str(host.exe), "/b", str(scr_path)], text=True, capture_output=True)
    except Exception:
        logger.exception(host.value)
    else:
        stdout = res.stdout
        stderr = res.stderr
        s = (
            f"{host.value:-^20}"
            + f"\nReturn code: {res.returncode}"
            + (f"\nSTDOUT:\n{stdout}" if stdout else "")
            + (f"\nSTDERR:\n{stderr}" if stderr else "")
        )
        print(s)


def run_tests(cfg: TestConfig, hosts: tuple[Host] | None = None, debug: bool = False):
    if not hosts:
        hosts = Host
    with tempfile.TemporaryDirectory(prefix="pyrx_tests") as temp_dir:
        temp_dir = Path(temp_dir)
        cfg_file = temp_dir / "config"
        cfg.dump(cfg_file)  # dumped config is loaded in host
        scr_file = temp_dir / "test.scr"
        scr_content = get_cad_scr(cfg_file, debug=debug)
        scr_file.write_text(scr_content, encoding="ansi")

        threads: list[threading.Thread] = []
        for host in hosts:
            if host.exe is None:
                logger.warning(f"{host.value} executable path is not defined")
                continue
            if not host.exe.exists():
                logger.error(f"{host.value} executable does not exist: {host.exe}")
                continue
            host_thread = threading.Thread(
                target=start_host, name=host.name, kwargs=dict(host=host, scr_path=scr_file)
            )
            host_thread.start()
            threads.append(host_thread)

        for thread in threads:
            thread.join()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--no-slow", action="store_true", default=False, help="skip slow tests")
    parser.add_argument(
        "--known-failures", action="store_true", default=False, help="also test known failures"
    )
    parser.add_argument(
        "--hosts",
        nargs="*",
        choices=tuple(i.name.lower() for i in Host),
        help="hosts to test, default all",
    )
    parser.add_argument("--debug", action="store_true", default=False, help="enable debug mode")
    args = parser.parse_args()

    cfg = TestConfig(
        slow_tests=(not args.no_slow),
        known_failures=args.known_failures,
    )
    hosts = (
        tuple(getattr(Host, host_name.upper()) for host_name in args.hosts) if args.hosts else None
    )

    run_tests(cfg=cfg, hosts=hosts, debug=args.debug)


if __name__ == "__main__":
    main()
