from pathlib import Path

import pytest

from pyrx import Ed, Rx
from pyrx.commands import command
from pyrx.utils.test_runner import CmdlineTestArgsProvider, FileTestArgsProvider


class TestFileArgsTestRunner:
    def test_get_test_args(self, tmp_path: Path, monkeypatch: pytest.MonkeyPatch):
        args_file = tmp_path / "test_args.txt"
        args_file.write_text("test1\ntest2\n", encoding="utf-8")
        args_provider = FileTestArgsProvider(test_args_file=str(args_file))
        assert args_provider.get_test_args() == ["test1", "test2"]


class TestCmdlineArgsTestRunner:
    def test_test_args(self, monkeypatch: pytest.MonkeyPatch):
        args_provider = CmdlineTestArgsProvider()
        command(args_provider.set_pytest_args_cmd, name="test_set_pytest_args_cmd")
        resbuf = [
            (Rx.LispType.kText, "test_set_pytest_args_cmd"),
            (Rx.LispType.kText, "test1"),
            (Rx.LispType.kText, "test2"),
            (Rx.LispType.kText, ""),
            (Rx.LispType.kNone, 0),
        ]
        Ed.Core.cmdS(resbuf)
        assert args_provider.get_test_args() == ("test1", "test2")


if __name__ == "__main__":
    pytest.main([__file__])
