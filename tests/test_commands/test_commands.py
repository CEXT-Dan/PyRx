import re
import typing as t
from pathlib import Path

import pytest

from pyrx import Ap, Ed
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


@command
def cmd_test_4(a=1):
    print(a)


@command(name="cmd_5")
def cmd_test_5():
    raise RuntimeError("Test cmd 5")


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

    def test_func_called_as_command_success(self, capsys: pytest.CaptureFixture[str]):
        res = Ed.Core.cmdS("CMD_TEST_4")
        assert res is True
        assert capsys.readouterr().out == "1\n"

    def test_func_called_as_command_exception(self, capsys: pytest.CaptureFixture[str]):
        res = Ed.Core.cmdS("CMD_5")
        assert res is True
        stderr = capsys.readouterr().err
        expected_patt = r"Traceback \(most recent call last\):.*RuntimeError: Test cmd 5.*"
        assert re.match(expected_patt, stderr, re.DOTALL) is not None


# endregion: test command decorator
