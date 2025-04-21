import ctypes
from contextlib import (
    _RedirectStream,
    contextmanager,
    nullcontext,
    redirect_stderr,
    redirect_stdout,
)

import win32console  # type: ignore


class redirect_stdin(_RedirectStream):
    _stream = "stdin"


class ConsoleAlreadyExist(Exception):
    pass


@contextmanager
def console(allow_existing=True, stdout_redirect=True, stderr_redirect=True, stdin_redirect=True):
    """
    Create new console and redirect ``sys.stdout``, ``sys.stderr``,
    ``sys.stdin``. Use existing console if it exists and allow_existing
    is True, raise ConsoleAlreadyExist otherwise

    Raises:
        ConsoleAlreadyExist: If a console window already exists and allow_existing is False.
        OSError: If unable to allocate a new console window.

    Examples::

        >>> with console():
        >>>     print("This will be printed in the console window")
        >>>     input("Press Enter to continue...")
    """
    _redirect_stdout = redirect_stdout if stdout_redirect else nullcontext
    _redirect_stderr = redirect_stderr if stderr_redirect else nullcontext
    _redirect_stdin = redirect_stdin if stdin_redirect else nullcontext

    console_exists = win32console.GetConsoleWindow()
    if console_exists:
        if not allow_existing:
            raise ConsoleAlreadyExist(
                "Cannot access new console, only one console can be attached."
            )
    else:
        try:
            win32console.AllocConsole()
        except win32console.error as e:
            winerr = ctypes.WinError( # type: ignore[attr-defined]
                e.winerror,
                e.strerror,
            )
            winerr.add_note("Unable to allocate console")
            raise winerr from None
    with (
        open("CONOUT$", "w") as conout,
        open("CONIN$", "r") as conin,
        _redirect_stdout(conout),
        _redirect_stderr(conout),
        _redirect_stdin(conin),
    ):
        try:
            yield conin, conout
        finally:
            if not console_exists:
                print("You can close the console . . .", file=conout, flush=True)
                win32console.FreeConsole()
