from __future__ import annotations

from pathlib import Path

from pyrx import command
from pyrx.console import console
from pyrx.utils.test_runner import FileTestArgsProvider, PytestTestRunner

BASE_DIR = Path(__file__).parent


runner = PytestTestRunner(("pyrx", "tests"), FileTestArgsProvider(BASE_DIR / "pytest_args.txt"))


@command
def runtests() -> None:
    with console():
        runner.start()
        input("Press Enter to continue...")
