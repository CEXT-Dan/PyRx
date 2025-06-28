# /*
# This file contains a partial definition of the PyRx interface. When
# generating *.pyi files, the definitions contained in this file are
# inserted instead of the automatically generated ones.
# The definition of a given function/method/attribute must be complete
# (signature with type annotations and docstring). The class definition
# must contain a complete header (class name with base classes and
# possible docstring), and definitions of only selected
# methods/attributes.
# The header of this file, terminated by the marker
# ``# pyrx-marker: HEADER_END`` is inserted at the beginning of the
# file, but after the header inserted by the generator.
# Comments, like this one, wrapped in ``# /* ... # */`` are ignored by
# the generator.
# */

from __future__ import annotations

import collections.abc as c
from typing import TypeAlias, TypeVar, overload

from pyrx import Ap as PyAp

T = TypeVar("T")

# pyrx-marker: HEADER_END

_CommandDecorator: TypeAlias = c.Callable[[T], T]

@overload
def Command() -> _CommandDecorator: ...
@overload
def Command(commandName: str, /) -> _CommandDecorator: ...
@overload
def Command(commandName: str, CmdFlags: PyAp.CmdFlags, /) -> _CommandDecorator:
    """
    Decorator to register a command.

    Examples::

        import traceback
        from pyrx import Ap

        @Ap.Command()
        def my_command() -> None:
            try:
                # do something
            except Exception:
                traceback.print_exc()
    """

_LispFunctionDecorator: TypeAlias = c.Callable[[T], T]

@overload
def LispFunction() -> _LispFunctionDecorator: ...
@overload
def LispFunction(defunName: str, /) -> _LispFunctionDecorator:
    """
    Decorator to register a lisp function.

    Examples::

        import traceback
        from pyrx import Ap

        @Ap.LispFunction()
        def mylisp(args):
            try:
                return args
            except Exception as err:
                print(err)
    """
