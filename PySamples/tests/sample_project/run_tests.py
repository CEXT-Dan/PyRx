from contextlib import chdir
from pathlib import Path

from pyrx.commands import command
from pyrx.console import console
from pyrx.PyRxDebug import startListener as PyRxCmd_debug  # noqa
from pyrx.utils.test_runner import PytestCmdlineArgsTestRunner, PytestFileArgsTestRunner

BASE_DIR = Path(__file__).parent

file_test_runner = PytestFileArgsTestRunner(
    modules_to_reload=("package", "tests"), test_args_file=BASE_DIR / "test_args.txt"
)
cmd_test_runner = PytestCmdlineArgsTestRunner(modules_to_reload=("package", "tests"))


@command
def runtests_file():
    with chdir(BASE_DIR), console():
        file_test_runner.start()
        input("Press Enter to continue...")


@command
def runtests_cmd():
    with chdir(BASE_DIR), console():
        cmd_test_runner.start()
        input("Press Enter to continue...")


@command
def settestargs():
    cmd_test_runner.set_pytest_args_cmd()


# Command: RUNTESTS_FILE
# <output in the console>
#
# ============================= test session starts =============================
# platform win32 -- Python 3.12.7, pytest-8.3.4, pluggy-1.5.0 -- D:\Users\(...)\python.exe
# (...)
# Module package.module loaded at 2025-03-18 22:13:31.879325

# collected 2 items

# tests\test_1.py::test_func_a PASSED
# tests\test_1.py::test_func_b PASSED

# ============================== 2 passed in 0.14s ==============================
# Press Enter to continue...
#
# </output in the console>
#
# Command: SETTESTARGS
# >>> -s
# >>>
# Command: RUNTESTS_CMD
# <output in the console>
#
# ============================= test session starts =============================
# platform win32 -- Python 3.12.7, pytest-8.3.4, pluggy-1.5.0
# (...)
# collecting ...
# Module package.module loaded at 2025-03-18 22:15:24.681237

# collected 2 items

# tests\test_1.py ..

# ============================== 2 passed in 0.14s ==============================
# Press Enter to continue...
#
# </output in the console>
