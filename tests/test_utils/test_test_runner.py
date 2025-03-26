from pathlib import Path

import pytest

from pyrx import Ed
from pyrx.commands import command
from pyrx.utils.test_runner import CmdlineArgsTestRunner, FileArgsTestRunner


class TestFileArgsTestRunner:
    def test_get_test_args(self, tmp_path: Path, monkeypatch: pytest.MonkeyPatch):
        args_file = tmp_path / "test_args.txt"
        args_file.write_text("test1\ntest2\n", encoding="utf-8")
        monkeypatch.setattr(FileArgsTestRunner, "__abstractmethods__", set())
        runner = FileArgsTestRunner(modules_to_reload=(), test_args_file=str(args_file))
        assert runner.get_test_args() == ["test1", "test2"]


class TestCmdlineArgsTestRunner:
    def test_test_args(self, monkeypatch: pytest.MonkeyPatch):
        monkeypatch.setattr(CmdlineArgsTestRunner, "__abstractmethods__", set())
        runner = CmdlineArgsTestRunner(modules_to_reload=())
        command(runner.set_pytest_args_cmd, name="test_set_pytest_args_cmd")
        Ed.Core.cmdS("test_set_pytest_args_cmd")
        Ed.Core.cmdS("test1")
        Ed.Core.cmdS("test2")
        Ed.Core.cmdS("")
        assert runner.get_test_args() == ("test1", "test2")


if __name__ == "__main__":
    pytest.main([__file__])
