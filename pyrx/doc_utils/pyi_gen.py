from __future__ import annotations

import collections.abc as c
import enum
import inspect
import logging
import textwrap
import types
import typing as t

__isbrx__ = False
from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm

if "BRX" in Ap.Application.hostAPI():
    from pyrx import Bim, Brx, Cv

    __isbrx__ = True

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
BoostPythonEnum: t.TypeAlias = Db.OpenMode.__base__
BoostPythonInstance: t.TypeAlias = Db.Database.__base__.__base__
BoostPythonFunction = type(Db.curDb)
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
        type_fixer: TypeFixer,
        indent: Indent | int = 0,
        line_length=LINE_LENGTH,
    ):
        self.docstrings = docstrings
        self.return_types = return_types
        self.indent = Indent(indent)
        self.line_length = line_length
        self.type_fixer = type_fixer

    def _skip_member(self, name, obj):
        if name in {
            "__repr__",
            "__str__",
            "__eq__",
            "__bool__",
            "__doc__",
            "__module__",
            "__instance_size__",
            "__safe_for_unpickling__",
        }:
            return True
        return False

    def gen(self, cls: BoostPythonInstance, module_name: str):
        indent = self.indent
        chunks = []
        cls_name = cls.__name__
        chunks.append(f"{indent}class {cls_name}")
        bases = ", ".join(
            f"{base.__module__}.{base.__name__}"
            for base in cls.__bases__
            if base is not BoostPythonInstance
        )
        if bases:
            chunks.append(f"({bases})")
        chunks.append(":\n")
        cls_dict = cls.__dict__
        for cls_member_name, cls_member in inspect.getmembers(cls):
            if cls_member_name not in cls_dict:  # skip methods inherited from base classes
                continue
            if self._skip_member(cls_member_name, cls_member):
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
            elif cls_member_name == "__init__":
                s = self._write_builtin_init()
            else:
                logger.warning(
                    f"Skipping a member of the {module_name}.{cls_name} class:\n"
                    f"\tname: {cls_member_name}\n"
                    f"\trepr: {cls_member!r}"
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
        type_name = (
            obj_type.__name__
            if type_module == "builtins"
            else f"{type_module}.{obj_type.__name__}"
        )
        return f"{indent}{name}: {type_name}\n"

    def _write_builtin_init(self):
        indent = self.indent + 1
        indent_2 = indent + 1
        return (
            f"{indent}def __init__(self):\n"
            f'{indent_2}"""\n'
            f"{indent_2}Raises an exception.\n"
            f"{indent_2}This class cannot be instantiated from Python.\n"
            f'{indent_2}"""\n'
        )

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
        try:
            return_type = self.type_fixer(return_type)
        except ValueError as e:
            logger.error(str(e))

        signatures = (
            tuple(get_text_signatures(base_signature, overloads))
            if base_signature is not None
            else None
        )
        docstring = self.docstrings.get(int(docstring_id)) if docstring_id is not None else None
        return_type = self.return_types.get(module_name, cls_name, cls_member_name) or return_type
        if return_type and return_type.strip() in ("tuple", "list", "dict"):
            logger.warning(
                "not fully resolved return type: "
                f"{module_name}::{cls_name}::{cls_member_name} "
                f"-> {return_type}"
            )

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
    if __isbrx__:
        Cv = "Cv", Cv, "PyBrxCv"
        Bim = "Bim", Bim, "PyBrxBim"
        Brx = "Brx", Brx, "PyBrx"

    @classmethod
    def _missing_(cls, value):
        for item in cls:
            if value in (item.orig_module_name, item.module):
                return item


_BoostPythonEnum_source = """
T = TypeVar("T")

class _BoostPythonEnumMeta(type):
    # This is not a real class, it is just for better type hints

    def __call__(cls: type[T], value: int) -> T: ...

class _BoostPythonEnum(int, metaclass=_BoostPythonEnumMeta):
    # This is not a real class, it is just for better type hints

    values: ClassVar[dict[int, Self]]
    names: ClassVar[dict[str, Self]]

    name: str
"""


class _ModulePyiGenerator:
    def __init__(
        self,
        module: types.ModuleType,
        all_modules: tuple[_PyRxModule | str | types.ModuleType, ...],
        docstrings: DocstringsManager,
        return_types: ReturnTypesManager,
        line_length=LINE_LENGTH,
    ):
        self.module = module
        self.all_modules = tuple(_PyRxModule(i) for i in all_modules)
        self.docstrings = docstrings
        self.return_types = return_types
        self.line_length = line_length
        self.type_fixer = TypeFixer(module=self.module, all_modules=self.all_modules)
        self._boost_python_instance_class_generator = _BoostPythonInstanceClassPyiGenerator(
            docstrings=self.docstrings,
            return_types=self.return_types,
            type_fixer=self.type_fixer,
            indent=Indent(0),
            line_length=self.line_length,
        )

    def _write_module_header(self, enums: bool):
        chunks: list[str] = ["from __future__ import annotations\n"]
        chunks.append("from typing import *\n")
        chunks.append(self._write_pyrx_import())
        chunks.append("import wx\n")
        if enums:
            chunks.append(self._write_boost_python_enum_source())
        return "".join(chunks)

    def _write_pyrx_import(self):
        return (
            "\n".join(
                f"from pyrx import {module.module_name} as {module.orig_module_name}"
                for module in self.all_modules
            )
            + "\n"
        )

    def _write_boost_python_enum_source(self):
        return _BoostPythonEnum_source

    def _skip_member(self, name: str, obj):
        if name.startswith("__") and name.endswith("__"):
            return True
        return False

    def gen(self):
        module = self.module
        module_name = module.__name__
        classes: list[tuple[str, type]] = []
        functions: list[tuple[str, types.FunctionType]] = []
        global_enum_members: list[tuple[str, BoostPythonEnum]] = []
        for member_name, member in inspect.getmembers(module):
            if self._skip_member(member_name, member):
                continue
            if inspect.isclass(member):
                classes.append((member_name, member))
            elif isinstance(member, BoostPythonEnum):
                global_enum_members.append((member_name, member))
            elif isinstance(member, BoostPythonFunction):
                functions.append((member_name, member))
            else:
                logger.error(
                    f"Unknown member (class) of module {module_name}:\n"
                    f"\tname: {member_name}\n"
                    f"\trepr: {member!r}"
                )

        chunks: list[str] = []

        chunks.append(
            self._write_module_header(
                enums=any(issubclass(cls, BoostPythonEnum) for _, cls in classes)
            )
        )

        for enum_name, enum_obj in global_enum_members:
            chunks.append(self._write_global_enum_member(enum_name, enum_obj))

        for cls_name, cls in classes:
            if issubclass(cls, BoostPythonInstance):
                chunks.append(self._write_boost_python_instance_class(cls_name, cls, module_name))
            elif issubclass(cls, BoostPythonEnum):
                chunks.append(self._write_boost_python_enum_class(cls_name, cls))
            else:
                logger.warning(
                    f"Skipping a member of the {module_name} module:\n"
                    f"\tname: {cls_name}\n"
                    f"\trepr: {cls!r}"
                )

        for func_name, func in functions:
            chunks.append(self._write_boost_python_function(func_name, func))

        return "".join(chunks)

    def _write_global_enum_member(self, enum_name, enum_obj):
        return f"{enum_name}: {type(enum_obj).__name__}  # {int(enum_obj)}\n"

    def _write_boost_python_enum_class(self, cls_name: str, cls_obj: BoostPythonEnum):
        indent = Indent()
        member_indent = indent + 1
        chunks: list[str] = []
        chunks.append(f"class {cls_name}(_BoostPythonEnum):\n")
        for member_name, member in cls_obj.names.items():
            chunks.append(f"{member_indent}{member_name}: ClassVar[Self]  # {int(member)}\n")
        return "".join(chunks)

    def _write_boost_python_instance_class(self, cls_name, cls, module_name):
        return self._boost_python_instance_class_generator.gen(cls=cls, module_name=module_name)

    def _write_boost_python_function(self, func_name, func_obj):
        indent = Indent(0)
        indent_2 = indent + 1
        # TODO: combine with _BoostPythonInstanceClassPyiGenerator._get_cls_member_data
        docstring = getattr(func_obj, "__doc__", None)
        if docstring is not None:
            return_type = get_return_type(docstring)
        else:
            return_type = None
        try:
            return_type = self.type_fixer(return_type)
        except ValueError as e:
            logger.error(str(e))
        else:
            if return_type and return_type.strip() in ("tuple", "list", "dict"):
                logger.warning(
                    "not fully resolved return type: "
                    f"{self.module.__name__}::{func_name} "
                    f"-> {return_type}"
                )

        chunks: list[str] = []
        chunks.append(f"{indent}def {func_name}(*args)")
        if return_type:
            chunks.append(f" -> {return_type}")
        chunks.append(":\n")
        if docstring:
            chunks.append(f'{indent_2}"""\n{indent_2}{docstring.strip()}\n{indent_2}"""\n')
        else:
            chunks.append(f"{indent_2}...\n")
        return "".join(chunks)


_all_modules = [Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm]
if "BRX" in Ap.Application.hostAPI():
    _all_modules.extend([Cv, Bim, Brx])


class TypeFixer:
    def __init__(
        self,
        module: types.ModuleType,
        all_modules: c.Iterable[_PyRxModule] = (_PyRxModule(m) for m in _all_modules),
    ):
        self.module = module
        self.all_modules = tuple(all_modules)

    def __call__(self, type_str: str | None):
        if type_str is None:
            return None
        try:
            eval(type_str, self.module.__dict__)
        except NameError:
            pass
        else:
            return type_str

        for module in self.all_modules:
            try:
                eval(type_str, module.module.__dict__)
            except NameError:
                pass
            else:
                return f"{module.orig_module_name}.{type_str}"

        raise ValueError(f"Unknown type: {type_str}")


def gen_pyi(
    module: types.ModuleType,
    all_modules: tuple[_PyRxModule | str | types.ModuleType, ...],
    docstrings: DocstringsManager,
    return_types: ReturnTypesManager,
    line_length=LINE_LENGTH,
):
    return _ModulePyiGenerator(
        module=module,
        all_modules=all_modules,
        docstrings=docstrings,
        return_types=return_types,
        line_length=line_length,
    )
