from __future__ import annotations

import collections.abc as c
import enum
import inspect
import logging
import textwrap
import types
import typing as t

from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm

from .misc import DocstringsManager, ReturnTypesManager
from .parse_docstring import (
    get_base_signature,
    get_docstring_id,
    get_overloads,
    get_return_type,
    get_text_signatures,
)

logger = logging.getLogger(__name__)

LINE_LENGTH = 99
BoostPythonInstance: t.TypeAlias = Db.Database.__base__.__base__
BoostPythonStaticProperty = type(Ge.Point3d.__dict__["kOrigin"])


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
            break_on_hyphens=False,
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
        s = s.strip(" ,/")
        if s:
            s += ", /"
        return s

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


class _ClsMemberData(t.NamedTuple):
    signatures: tuple[str] | None = None
    return_type: str | None = None
    docstring: str | None = None


class _BoostPythonInstanceClassPyiGenerator:
    def __init__(
        self,
        docstrings: DocstringsManager,
        return_types: ReturnTypesManager,
        indent: Indent | int = 0,
        line_length=LINE_LENGTH,
    ):
        self.docstrings = docstrings
        self.return_types = return_types
        self.indent = Indent(indent)
        self.line_length = line_length

    def gen(self, cls: BoostPythonInstance, module_name: str):
        indent = self.indent
        chunks = []
        cls_name = cls.__name__
        chunks.append(f"{indent}class {cls_name}")
        bases = ", ".join(
            base.__name__ for base in cls.__bases__ if base is not BoostPythonInstance
        )
        if bases:
            chunks.append(f"({bases})")
        chunks.append(":\n")
        cls_dict = cls.__dict__
        for cls_member_name, cls_member in inspect.getmembers(cls):
            if cls_member_name not in cls_dict:  # skip methods inherited from base classes
                continue
            if inspect.ismethoddescriptor(cls_member):  # method or staticmethod
                s = self._write_method(
                    meth_name=cls_member_name,
                    meth_obj=cls_member,
                    cls_obj=cls,
                    module_name=module_name,
                    indent=indent + 1,
                )
            elif inspect.isdatadescriptor(cls_member):  # @property
                s = self._write_property(
                    meth_name=cls_member_name,
                    meth_obj=cls_member,
                    cls_obj=cls,
                    module_name=module_name,
                    indent=indent + 1,
                )
            elif isinstance(cls.__dict__[cls_member_name], BoostPythonStaticProperty):
                s = self._write_static_property(cls_member_name, cls_member)
            else:
                logger.warning(
                    f"Skipping a member of the {module_name}.{cls_name} class:\n"
                    f"\tname: {cls_member_name}\n"
                    f"\trepr: {repr(cls_member)}"
                )
                continue
            chunks.append(s)

        return "".join(chunks)

    def _write_method(self, meth_name, meth_obj, cls_obj, module_name, indent):
        is_static = isinstance(cls_obj.__dict__[meth_name], staticmethod)
        meth_data = self._get_cls_member_data(meth_obj, meth_name, cls_obj.__name__, module_name)
        signatures = meth_data.signatures
        if signatures is None:
            signatures = ("",) if is_static else ("self",)
        docstring = meth_data.docstring
        if docstring is not None:
            docstring = wrap_docstring(
                docstring=docstring, indent=indent + 1, line_length=self.line_length
            )
        return write_method(
            name=meth_name,
            signatures=signatures,
            return_type=meth_data.return_type,
            docstring=docstring,
            is_static=is_static,
            is_property=False,
            indent=indent,
        )

    def _write_property(self, meth_name, meth_obj, cls_obj, module_name, indent):
        meth_data = self._get_cls_member_data(meth_obj, meth_name, cls_obj.__name__, module_name)
        docstring = meth_data.docstring
        if docstring is not None:
            docstring = wrap_docstring(
                docstring=docstring, indent=indent + 1, line_length=self.line_length
            )
        return write_method(
            name=meth_name,
            signatures=("self",),
            return_type=meth_data.return_type,
            docstring=docstring,
            is_static=False,
            is_property=True,
            indent=indent,
        )

    def _write_static_property(self, name, obj):
        indent = self.indent + 1
        obj_type = type(obj)
        type_module = obj_type.__module__
        return f"{indent}{name}: {type_module}.{obj_type.__name__}\n"

    def _get_cls_member_data(
        self, cls_member, cls_member_name, cls_name, module_name
    ) -> _ClsMemberData:
        raw_docstring = getattr(cls_member, "__doc__", None)
        if raw_docstring is None:
            return _ClsMemberData()
        base_signature = get_base_signature(raw_docstring)
        overloads = get_overloads(raw_docstring)
        docstring_id = get_docstring_id(raw_docstring)
        return_type = get_return_type(raw_docstring)

        signatures = (
            tuple(get_text_signatures(base_signature, overloads))
            if base_signature is not None
            else None
        )
        docstring = self.docstrings.get(int(docstring_id)) if docstring_id is not None else None
        return_type = self.return_types.get(module_name, cls_name, cls_member_name) or return_type

        return _ClsMemberData(signatures, return_type, docstring)


class _PyRxModule(str, enum.Enum):
    module: types.ModuleType
    module_name: str
    orig_module_name: str

    def __new__(cls, module_name: str, module: types.ModuleType, orig_module_name: str):
        obj = str.__new__(cls)
        obj._value_ = module_name
        obj.module_name = module_name
        obj.module = module
        obj.orig_module_name = orig_module_name
        return obj

    Ap = "Ap", Ap, "PyAp"
    Br = "Br", Br, "PyBr"
    Db = "Db", Db, "PyDb"
    Ed = "Ed", Ed, "PyEd"
    Ge = "Ge", Ge, "PyGe"
    Gi = "Gi", Gi, "PyGi"
    Gs = "Gs", Gs, "PyGs"
    Pl = "Pl", Pl, "PyPl"
    Rx = "Rx", Rx, "PyRx"
    Sm = "Sm", Sm, "PySm"
    Ax = "Ax", Ax, "PyAx"

    @classmethod
    def _missing_(cls, value):
        for item in cls:
            if value in (item.orig_module_name, item.module):
                return item


class _ModulePyiGenerator:
    def __init__(
        self,
        all_modules: tuple[_PyRxModule | str, ...],
        docstrings: DocstringsManager,
        return_types: ReturnTypesManager,
        line_length=LINE_LENGTH,
    ):
        self.all_modules = tuple(_PyRxModule(i) for i in all_modules)
        self.docstrings = docstrings
        self.return_types = return_types
        self.line_length = line_length

    def _write_module_header(self):
        chunks: list[str] = []
        chunks.append("from typing import overload\n")
        chunks.append(self._write_pyrx_import())
        return "".join(chunks)

    def _write_pyrx_import(self):
        return (
            "\n".join(
                f"from pyrx import {module.module_name} as {module.orig_module_name}"
                for module in self.all_modules
            )
            + "\n"
        )
