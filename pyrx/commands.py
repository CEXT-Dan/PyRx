from __future__ import annotations

import inspect
import traceback
import typing as t
from collections import defaultdict
from contextlib import chdir
from pathlib import Path

from . import Ap
from .ed.prompt import PromptExceptionCancel, PromptExceptionNone, PromptExceptionRejected

_commands: dict[str, dict[str, t.Callable[..., None]]] = defaultdict(dict)


def command(
    func: t.Callable[..., None] | None = None,
    *,
    name: str | None = None,
    flags: Ap.CmdFlags | None = None,
    change_cwd: bool = True,
):
    """
    A decorator to register a function as a command in the application.

    The decorated function must have all parameters with default values.

    Parameters:
        func: The function to be registered as a command.
        name: The name of the command. If None, the function's name is used.
        flags: The flags for the command. If None, Ap.CmdFlags.MODAL is used.
        change_cwd: Whether to change the current working directory to
            the module directory when the command is executed. Defaults to True.

    Raises:
        TypeError: If the function has parameters without default values.

    Examples::

        @command
        def my_command():
            print("Command executed")

        @command(name="CUSTOM_COMMAND")
        def another_command():
            print("Another command executed")

        @command(flags=Ap.CmdFlags.SESSION)
        def session_command():
            print("Session command executed")
    """

    def decorator(f: t.Callable[..., None]) -> t.Callable[..., None]:
        for param_name, param in inspect.signature(f).parameters.items():
            if param.default is inspect.Parameter.empty:
                raise TypeError(
                    f"Command function {f.__name__!r} has a non-default parameter {param_name!r}"
                )

        nonlocal name, flags
        if name is None:
            name = f.__name__.lstrip("_")
        if flags is None:
            flags = Ap.CmdFlags.MODAL

        def wrapper(*args, **kwargs):
            try:
                if change_cwd:
                    working_dir: str = str(Path(f.__globals__["__file__"]).parent)
                    with chdir(working_dir):
                        f(*args, **kwargs)
                else:
                    f(*args, **kwargs)
            except (PromptExceptionNone, PromptExceptionRejected, PromptExceptionCancel):
                pass
            except Exception as e:
                if e.__traceback__ is None:
                    traceback.print_exception(e)
                else:
                    traceback.print_exception(e.with_traceback(e.__traceback__.tb_next))

        Ap.Application.regCommand(f.__globals__["__file__"], f.__module__, name, wrapper, flags)
        _commands[f.__module__][name] = wrapper  # prevent garbage collection

        return f

    if func is not None:
        return decorator(func)
    else:
        return decorator
