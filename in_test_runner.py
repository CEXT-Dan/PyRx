from __future__ import annotations

from pathlib import Path

from pyrx import command
from pyrx.console import console
from pyrx.utils.test_runner import PytestFileArgsTestRunner

BASE_DIR = Path(__file__).parent


runner = PytestFileArgsTestRunner(("pyrx", "tests"), BASE_DIR / "pytest_args.txt")


@command
def runtests():
    with console():
        runner.start()
        input("Press Enter to continue...")
