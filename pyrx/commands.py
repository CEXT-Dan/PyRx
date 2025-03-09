from __future__ import annotations

import inspect
import traceback
import typing as t
from collections import defaultdict

from pyrx import Ap

if t.TYPE_CHECKING:
    import types

_commands = defaultdict(dict)


def command(
    func: types.FunctionType | None = None,
    *,
    name: str | None = None,
    flags: Ap.CmdFlags | None = None,
):
    """
    A decorator to register a function as a command in the application.

    The decorated function must have all parameters with default values.

    Parameters:
        func: The function to be registered as a command.
        name: The name of the command. If None, the function's name is used.
        flags: The flags for the command. If None, Ap.CmdFlags.MODAL is used.

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

    def decorator(func: types.FunctionType):
        for param_name, param in inspect.signature(func).parameters.items():
            if param.default is inspect.Parameter.empty:
                raise TypeError(
                    f"Command function {func.__name__!r} has a non-default parameter {param_name!r}"
                )

        nonlocal name, flags
        if name is None:
            name = func.__name__.lstrip("_")
        if flags is None:
            flags = Ap.CmdFlags.MODAL

        def wrapper(*args, **kwargs):
            try:
                func(*args, **kwargs)
            except Exception as e:
                traceback.print_exception(e.with_traceback(e.__traceback__.tb_next))

        Ap.Application.regCommand(
            func.__globals__["__file__"], func.__module__, name, wrapper, flags
        )
        _commands[func.__module__][name] = wrapper  # prevent garbage collection

        return func

    if func is not None:
        return decorator(func)
    else:
        return decorator
