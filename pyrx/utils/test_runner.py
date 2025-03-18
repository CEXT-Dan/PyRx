from __future__ import annotations

import abc
import collections.abc as c
import typing as t
from pathlib import Path

import pytest

from pyrx import Ed

from .reload import Reloader

if t.TYPE_CHECKING:
    import _typeshed as _t


class TestRunnerBase(abc.ABC):
    def __init__(self, modules_to_reload: c.Iterable[str]):
        self.reload_modules = Reloader(*modules_to_reload, reload=False).reload_modules

    def start(self):
        test_args = self.get_test_args()
        self.reload_modules()
        return self.run_tests(test_args)

    @abc.abstractmethod
    def get_test_args(self) -> c.Iterable[str]: ...

    @abc.abstractmethod
    def run_tests(self, test_args: c.Iterable[str]): ...


class FileArgsTestRunner(TestRunnerBase):
    def __init__(
        self, modules_to_reload, test_args_file: _t.StrPath, test_args_file_encoding: str = "utf-8"
    ):
        super().__init__(modules_to_reload)
        self.test_args_file = Path(test_args_file)
        self.test_args_file_encoding = test_args_file_encoding

    def get_test_args(self) -> list[str]:
        file = self.test_args_file
        if not file.exists():
            raise FileNotFoundError(str(file))
        return file.read_text(self.test_args_file_encoding).splitlines(keepends=False)


class CmdlineArgsTestRunner(TestRunnerBase):
    def set_pytest_args_cmd(self):
        def test_args():
            while True:
                status, arg = Ed.Editor.getString(1, ">>> ")
                if not status == Ed.PromptStatus.eOk or not arg:
                    break
                yield arg

        self._test_args = tuple(test_args())

    def get_test_args(self) -> tuple[str, ...]:
        return getattr(self, "_test_args", ())


class PytestTestRunnerMixin:
    def run_tests(self, test_args):
        return pytest.main(list(test_args))


class PytestFileArgsTestRunner(PytestTestRunnerMixin, FileArgsTestRunner):
    pass


class PytestCmdlineArgsTestRunner(PytestTestRunnerMixin, CmdlineArgsTestRunner):
    pass
