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


class TestArgsProvider(abc.ABC):
    @abc.abstractmethod
    def get_test_args(self) -> c.Iterable[str]: ...


T = t.TypeVar("T", bound=TestArgsProvider)


class TestRunner(abc.ABC, t.Generic[T]):
    def __init__(self, modules_to_reload: c.Iterable[str], test_args_provider: T) -> None:
        self.test_args_provider: T = test_args_provider
        self.reload_modules = Reloader(*modules_to_reload, reload=False).reload_modules

    def start(self) -> None:
        test_args = self.test_args_provider.get_test_args()
        self.reload_modules()
        self.run_tests(test_args)

    @abc.abstractmethod
    def run_tests(self, test_args: c.Iterable[str]) -> None: ...


class FileTestArgsProvider(TestArgsProvider):
    def __init__(
        self, test_args_file: _t.StrPath, test_args_file_encoding: str = "utf-8"
    ) -> None:
        self.test_args_file = Path(test_args_file)
        self.test_args_file_encoding = test_args_file_encoding

    def get_test_args(self) -> list[str]:
        file = self.test_args_file
        if not file.exists():
            raise FileNotFoundError(str(file))
        return file.read_text(self.test_args_file_encoding).splitlines(keepends=False)


class CmdlineTestArgsProvider(TestArgsProvider):
    def __init__(self) -> None:
        self._test_args: tuple[str, ...] = ()

    def set_pytest_args_cmd(self):
        def test_args():
            while True:
                status, arg = Ed.Editor.getString(1, ">>> ")
                if not status == Ed.PromptStatus.eOk or not arg:
                    break
                yield arg

        self._test_args = tuple(test_args())

    def get_test_args(self) -> tuple[str, ...]:
        return self._test_args


class PytestTestRunner(TestRunner[T]):
    def run_tests(self, test_args: c.Iterable[str]) -> None:
        pytest.main(list(test_args))
