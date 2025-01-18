from __future__ import annotations

import typing as t


class Indent:
    def __init__(self, indent: int | Indent = 0, /):
        if isinstance(indent, Indent):
            self._indent = indent._indent
        elif isinstance(indent, int):
            self._indent = indent
        else:
            raise TypeError(f"arg must be of type int or Indent, not {type(indent).__name__}")

    def increase(self) -> t.Self:
        return type(self)(self._indent + 1)

    def decrease(self) -> t.Self:
        indent = self._indent - 1
        if indent < 0:
            raise ValueError("already zero")
        return type(self)(indent)

    def __add__(self, other) -> t.Self:
        if isinstance(other, int):
            return type(self)(self._indent + other)
        elif isinstance(other, Indent):
            return type(self)(self._indent + other._indent)
        else:
            return NotImplemented

    def __sub__(self, other) -> t.Self:
        if isinstance(other, int):
            indent = self._indent - other
        elif isinstance(other, Indent):
            indent = self._indent - other._indent
        else:
            return NotImplemented
        if indent < 0:
            raise ValueError(f"cannot be less that 0 ({indent})")
        return type(self)(indent)

    @property
    def len(self) -> int:
        return len(str(self))

    def __len__(self) -> int:
        return self.len

    def __str__(self):
        return "    " * self._indent
