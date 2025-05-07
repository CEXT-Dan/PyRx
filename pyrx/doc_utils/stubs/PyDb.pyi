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

from pyrx import Db as PyDb

# pyrx-marker: HEADER_END

class ErrorStatusException(RuntimeError):
    code: PyDb.ErrorStatus
    message: str
    fullmessage: str
