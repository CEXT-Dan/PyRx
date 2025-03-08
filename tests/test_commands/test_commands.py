import re
import subprocess
import typing as t
from pathlib import Path

import pytest

from pyrx import Ap, Ax, Ed
from pyrx.commands import command

BASE_DIR = Path(__file__).parent


class _CommandRow(t.NamedTuple):
    name: str
    local_name: str
    flags: Ap.CmdFlags


# region: test command decorator


def get_registered_commands():
    key = f"PY_{__name__.upper()}"
    all_commands = Ed.Core.getCommands()
    if key not in all_commands:
        return
    for cmd in all_commands[key]:
        yield _CommandRow(*cmd)


before_registered_commands = set(get_registered_commands())


@command
def cmd_test_1():
    return 1


@command(name="COMMAND_TEST_2")
def cmd_test_2():
    return 2


@command(flags=Ap.CmdFlags.SESSION)
def cmd_test_3():
    return 3


after_registered_commands = set(get_registered_commands())
diff_registered_commands = after_registered_commands - before_registered_commands
diff_registered_command_names = {cmd.name for cmd in diff_registered_commands}


class Test_command_decorator:
    def test_without_brackets(self):
        assert "CMD_TEST_1" in diff_registered_command_names
        for cmd in diff_registered_commands:
            if cmd.name == "CMD_TEST_1":
                assert cmd.flags == Ap.CmdFlags.MODAL
                break
        else:
            raise RuntimeError("Command not found")

    def test_with_brackets(self):
        assert "COMMAND_TEST_2" in diff_registered_command_names
        for cmd in diff_registered_commands:
            if cmd.name == "COMMAND_TEST_2":
                assert cmd.flags == Ap.CmdFlags.MODAL
                break
        else:
            raise RuntimeError("Command not found")

    def test_with_flags(self):
        assert "CMD_TEST_3" in diff_registered_command_names
        for cmd in diff_registered_commands:
            if cmd.name == "CMD_TEST_3":
                assert cmd.flags == Ap.CmdFlags.SESSION
                break
        else:
            raise RuntimeError("Command not found")

    def test_non_default_params_raise_TypeError(self):
        with pytest.raises(
            TypeError, match="Command function 'test_1' has a non-default parameter 'param_1'"
        ):

            @command
            def test_1(param_1, param_2=1):
                pass

    def test_func_called_directly(self):
        @command
        def test_2(a=1, b=2):
            return a + b

        res = test_2(3, 4)
        assert res == 7

        @command(name="test_3")
        def test_2():
            raise RuntimeError("Test 123")

        with pytest.raises(RuntimeError, match="Test 123"):
            test_2()

    @pytest.mark.slow
    def test_func_called_as_command(self, tmp_path: Path):
        host_exe = Ax.AcadApplication().fullName()
        pyrx_module_path = (
            Path(Ap.Application.getPyRxModulePath()) / Ap.Application.getPyRxModuleName()
        )
        python_module_path = BASE_DIR / "_test_commands.py"
        test_res_path = tmp_path / "test_res.txt"
        scr_content = (
            f'(adspyload "{python_module_path.as_posix()}")\n'
            # redirect STDOUT/STDERR
            "pycmdprompt\n"
            "import sys\n"
            f"sys.stdout = sys.stderr = open({test_res_path.as_posix()!r}, 'w', encoding='utf-8')\n"
            "quit\n"  # quit pycmdprompt
            "COMMAND_1\n"
            "CMD_2\n"
            "pycmdprompt\n"
            "sys.stdout.close()\n"
            "quit\n"  # quit pycmdprompt
            "_quit\n_yes\n"  # quit host
        )
        scr_file = tmp_path / "test.scr"
        scr_file.write_text(scr_content, encoding="ansi")
        process = subprocess.Popen(
            args=[host_exe, "/ld", str(pyrx_module_path), "/b", str(scr_file)],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        res = None
        TIMEOUT = 50
        try:
            process.wait(TIMEOUT)
        except subprocess.TimeoutExpired:
            process.terminate()
            raise
        res = test_res_path.read_text("utf-8")

        expected_patt = r"1\nTraceback \(most recent call last\):.*RuntimeError: Test cmd 2.*"
        assert re.match(expected_patt, res, re.DOTALL) is not None


# endregion: test command decorator
