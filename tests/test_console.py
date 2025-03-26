import re
import sys

import pytest
import win32console  # type: ignore

from pyrx.console import ConsoleAlreadyExist, console


def test_alloc():
    assert not win32console.GetConsoleWindow(), "Unable to test console allocation"
    with console():
        assert win32console.GetConsoleWindow()
    assert not win32console.GetConsoleWindow()


def test_alloc_with_existing():
    if win32console.GetConsoleWindow():
        with console(allow_existing=True):
            assert win32console.GetConsoleWindow()
        assert win32console.GetConsoleWindow()

    else:
        with console():
            with console(allow_existing=True):
                assert win32console.GetConsoleWindow()
            assert win32console.GetConsoleWindow()
        assert not win32console.GetConsoleWindow()


def test_alloc_with_existing_raise_ConsoleAlreadyExist():
    with pytest.raises(
        ConsoleAlreadyExist,
        match=re.escape("Cannot access new console, only one console can be attached."),
    ):
        if win32console.GetConsoleWindow():
            with console(allow_existing=False):
                pass

        else:
            with console():
                with console(allow_existing=False):
                    pass


def test_redirect():
    old_stdin = sys.stdin
    with console(
        allow_existing=True, stdin_redirect=False, stdout_redirect=False, stderr_redirect=False
    ):
        new_stdin = sys.stdin

    assert old_stdin is new_stdin

    old_stdin = sys.stdin
    with console(
        allow_existing=True, stdin_redirect=True, stdout_redirect=False, stderr_redirect=False
    ):
        new_stdin = sys.stdin

    assert old_stdin is not new_stdin

    old_stdout = sys.stdout
    with console(
        allow_existing=True, stdin_redirect=False, stdout_redirect=False, stderr_redirect=False
    ):
        new_stdout = sys.stdout

    assert old_stdout is new_stdout

    old_stdout = sys.stdout
    with console(
        allow_existing=True, stdin_redirect=False, stdout_redirect=True, stderr_redirect=False
    ):
        new_stdout = sys.stdout

    assert old_stdout is not new_stdout

    old_stderr = sys.stderr
    with console(
        allow_existing=True, stdin_redirect=False, stdout_redirect=False, stderr_redirect=False
    ):
        new_stderr = sys.stderr

    assert old_stderr is new_stderr

    old_stderr = sys.stderr
    with console(
        allow_existing=True, stdin_redirect=False, stdout_redirect=False, stderr_redirect=True
    ):
        new_stderr = sys.stderr

    assert old_stderr is not new_stderr
