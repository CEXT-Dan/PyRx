from __future__ import annotations

import collections.abc as c
import textwrap
import typing as t

LINE_LENGTH = 99


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


class DocstringTextWrapper(textwrap.TextWrapper):
    def __init__(
        self,
        indent: int | Indent,
        width=LINE_LENGTH,
    ):
        indent = str(Indent(indent))
        super().__init__(
            width,
            initial_indent=indent,
            subsequent_indent=indent,
            expand_tabs=False,
            replace_whitespace=False,
            break_long_words=False,
            drop_whitespace=True,
            tabsize=4,
            max_lines=None,
        )


def wrap_docstring(
    docstring: str,
    indent: int | Indent = 0,
    line_length: int = LINE_LENGTH,
):
    indent = Indent(indent)
    text_wrapper = DocstringTextWrapper(indent=indent, width=line_length)
    wrapped_docstring = "\n".join(text_wrapper.wrap(docstring))
    return wrapped_docstring


class _MethodWriter:
    def __init__(
        self,
        name: str,
        signatures: c.Iterable[str],
        return_type: str | None = None,
        docstring: str | None = None,
        is_static: bool = False,
        is_property: bool = False,
        indent: int = 1,
    ):
        if is_static and is_property:
            raise ValueError("cannot be both a static method and a property")
        self.name = name
        self.signatures = tuple(self._fix_signature(s, is_static) for s in signatures)
        self.return_type = return_type
        self.docstring = docstring
        self.is_static = is_static
        self.is_property = is_property
        self.indent = Indent(indent)

    @classmethod
    def _fix_signature(cls, signature: str, is_static: bool):
        s = signature.strip(" ()")
        if is_static:
            s = s.removeprefix("self")
        return s.strip(" ,/") + ", /"

    def _write_method(self, signature: str, is_overload: bool):
        if is_overload and self.is_property:
            raise ValueError("cannot be both a overload and a property")
        chunks = []
        if is_overload:
            chunks.append(f"{self.indent}@overload\n")
        if self.is_static:
            chunks.append(f"{self.indent}@staticmethod\n")
        if self.is_property:
            chunks.append(f"{self.indent}@property\n")
        chunks.append(f"{self.indent}def {self.name}({signature})")
        if self.return_type is not None:
            chunks.append(f" -> {self.return_type}")
        chunks.append(":")
        if is_overload:
            chunks.append(" ...\n")
        elif self.docstring is not None:
            indent = self.indent + 1
            docstring = f'\n{indent}"""\n{self.docstring}\n{indent}"""\n'
            chunks.append(docstring)
        else:
            chunks.append(f"\n{self.indent + 1}pass\n")
        return "".join(chunks)

    def write(self):
        signatures = list(self.signatures)
        if len(signatures) > 1:  # has overloads
            signatures.append("self, *args" if not self.is_static else "*args")
        chunks = []
        for signature in signatures[:-1]:
            s = self._write_method(signature, is_overload=True)
            chunks.append(s)
        s = self._write_method(signatures[-1], is_overload=False)
        chunks.append(s)
        return "".join(chunks)


def write_method(
    name: str,
    signatures: c.Iterable[str],
    return_type: str | None = None,
    docstring: str | None = None,
    is_static: bool = False,
    is_property: bool = False,
    indent: int = 1,
):
    return _MethodWriter(
        name=name,
        signatures=signatures,
        return_type=return_type,
        docstring=docstring,
        is_static=is_static,
        is_property=is_property,
        indent=indent,
    ).write()
