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

class DynBlockReferenceProperty:
    def setValue(self, val: PyDb.EvalVariant, /) -> None:
        """
        Sets the current value of the property on the block.

        **Note**:
        No error is raised if the specified property value could not be set. For example, if the
        property has a list of allowable values or a minimum-maximum range and the value provided
        is not in the list or is out of range, the method succeeds and no error is raised.
        """

class ErrorStatusException(RuntimeError):
    code: PyDb.ErrorStatus
    message: str
    fullmessage: str
