from __future__ import annotations

import collections.abc as c
import inspect
import logging
import textwrap
import types
import typing as t
from pathlib import Path
from typing import NamedTuple

from .boost_meta import _BoostPythonEnum
from .misc import DocstringsManager, ReturnTypesManager
from .parse_docstring import (
    get_base_signature,
    get_docstring_id,
    get_overloads,
    get_return_type,
    get_text_signatures,
)
from .stubs.base import Node, StubSrcManager

logger = logging.getLogger(__name__)

LINE_LENGTH = 99

BASE_DIR = Path(__file__).parent


class BoostPythonEnum(_BoostPythonEnum): ...


class BoostPythonInstance(t.Protocol): ...


class BoostPythonFunction(t.Protocol):
    def __call__(self, *args, **kwargs) -> t.Any: ...


class BoostPythonStaticProperty(t.Protocol): ...


class BoostPythonTypes(t.NamedTuple):
    enum: t.Type[BoostPythonEnum] = BoostPythonEnum
    instance: t.Type[BoostPythonInstance] = object
    function: t.Type[BoostPythonFunction] = types.FunctionType
    static_property: t.Type[BoostPythonStaticProperty] = property


class Indent:
    def __init__(self, indent: int | Indent = 0, /):
        if isinstance(indent, Indent):
            self._indent: int = indent._indent
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
        indent_str = str(Indent(indent))
        super().__init__(
            width,
            initial_indent=indent_str,
            subsequent_indent=indent_str,
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
        indent: Indent | int = 1,
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

    def _write_method(
        self, signature: str, is_overload: bool, write_docstring: bool = True
    ) -> str:
        if is_overload and self.is_property:
            raise ValueError("cannot be both a overload and a property")
        chunks = []
        if is_overload:
            chunks.append(f"{self.indent}@overload\n")
        if self.is_static:
            chunks.append(f"{self.indent}@staticmethod\n")
        if self.is_property:
            chunks.append(f"{self.indent}@property\n")
        return_type = "Any" if self.return_type is None else self.return_type
        chunks.append(f"{self.indent}def {self.name}({signature}) -> {return_type}:")
        if self.docstring is None or not write_docstring:
            chunks.append(" ...\n")
        else:
            indent = self.indent + 1
            docstring = f'\n{indent}"""\n{self.docstring}\n{indent}"""\n'
            chunks.append(docstring)
        return "".join(chunks)

    def write(self) -> str:
        signatures = list(self.signatures)
        chunks = []
        if len(signatures) == 1:  # no overloads
            chunks.append(self._write_method(signatures[0], is_overload=False))
        else:
            chunks.extend(
                self._write_method(signature, is_overload=True, write_docstring=True)
                for signature in signatures
            )
            chunks.append(
                self._write_method(
                    "self, *args" if not self.is_static else "*args", is_overload=True
                )
            )
        return "".join(chunks)


def write_method(
    name: str,
    signatures: c.Iterable[str],
    return_type: str | None = None,
    docstring: str | None = None,
    is_static: bool = False,
    is_property: bool = False,
    indent: Indent | int = 1,
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
    signatures: tuple[str, ...] | None = None
    return_type: str | None = None
    docstring: str | None = None


class _BoostPythonInstanceClassPyiGenerator:
    def __init__(
        self,
        docstrings: DocstringsManager,
        return_types: ReturnTypesManager,
        indent: Indent | int = 0,
        line_length=LINE_LENGTH,
        boost_types: BoostPythonTypes = BoostPythonTypes(),
    ):
        self.docstrings = docstrings
        self.return_types = return_types
        self.indent = Indent(indent)
        self.line_length = line_length
        self.boost_types = boost_types

    _MEMBERS_TO_SKIP = {
        "__repr__",
        "__str__",
        "__eq__",
        "__bool__",
        "__doc__",
        "__module__",
        "__instance_size__",
        "__safe_for_unpickling__",
    }

    def get_chunks(
        self, cls: t.Type[BoostPythonInstance], module_name: str, node: Node | None
    ) -> c.Generator[str | Node, None, None]:
        indent = self.indent
        if node is None:
            chunks = []
            cls_name = cls.__name__
            chunks.append(f"{indent}class {cls_name}")
            bases = ", ".join(
                f"{base.__module__}.{base.__name__}"
                for base in cls.__bases__
                if base is not self.boost_types.instance
            )
            if bases:
                chunks.append(f"({bases})")
            chunks.append(":\n")
            yield "".join(chunks)
            chunks.clear()
        cls_dict = cls.__dict__
        stub_nodes = {node.name: node for node in node.children} if node else {}
        for cls_member_name, cls_member in inspect.getmembers(cls):
            try:
                stub_node = stub_nodes.pop(cls_member_name)
            except KeyError:
                pass
            else:
                yield stub_node
                continue
            if cls_member_name not in cls_dict:  # skip methods inherited from base classes
                continue
            if cls_member_name in self._MEMBERS_TO_SKIP:
                continue
            if inspect.ismethoddescriptor(cls_member):  # method or staticmethod
                yield self._write_method(
                    meth_name=cls_member_name,
                    meth_obj=cls_member,
                    cls_obj=cls,
                    module_name=module_name,
                    indent=indent + 1,
                )
            elif inspect.isdatadescriptor(cls_member):  # @property
                yield self._write_property(
                    meth_name=cls_member_name,
                    meth_obj=cls_member,
                    cls_obj=cls,
                    module_name=module_name,
                    indent=indent + 1,
                )
            elif isinstance(cls.__dict__[cls_member_name], self.boost_types.static_property):
                yield self._write_static_property(cls_member_name, cls_member)
            elif cls_member_name == "__init__":
                yield self._write_builtin_init()
            else:
                logger.warning(
                    f"Skipping a member of the {module_name}.{cls_name} class:\n"
                    f"\tname: {cls_member_name}\n"
                    f"\trepr: {cls_member!r}"
                )

    def gen(
        self, cls: t.Type[BoostPythonInstance], module_name: str, node: Node | None
    ) -> c.Generator[range | str, None, None]:
        chunks = tuple(self.get_chunks(cls, module_name, node))
        if node is not None:
            prev_range_stop = node.range.start - 1

        for chunk in chunks:
            if isinstance(chunk, Node):
                child_node = chunk
                child_range = child_node.range
                if not child_range.start > prev_range_stop:
                    # We assume that the order of the stubs file should
                    # be the same as when generated - alphabetically in
                    # groups
                    raise ValueError(f"The order of nodes is incorrect: {child_node.name}")
                # in addition to the current node's line, we also return
                # everything from the end of the previous (detected)
                # node, these can be e.g. overloads, TypeVar
                # definitions, etc.
                yield range(prev_range_stop + 1, child_range.stop)
                prev_range_stop = child_range.stop
            else:  # str
                yield chunk

        if node is not None:
            # return all lines until the end of class
            yield range(prev_range_stop + 1, node.range.stop)

    def _write_method(
        self,
        meth_name: str,
        meth_obj: types.MethodDescriptorType,
        cls_obj: t.Type[BoostPythonInstance],
        module_name: str,
        indent: Indent,
    ) -> str:
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

    def _write_property(
        self, meth_name: str, meth_obj, cls_obj, module_name: str, indent: Indent
    ) -> str:
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

    def _write_static_property(self, name: str, obj: object) -> str:
        indent = self.indent + 1
        obj_type = type(obj)
        type_module = obj_type.__module__
        type_name = (
            obj_type.__name__
            if type_module == "builtins"
            else f"{type_module}.{obj_type.__name__}"
        )
        return f"{indent}{name}: {type_name}\n"

    def _write_builtin_init(self) -> str:
        indent = self.indent + 1
        indent_2 = indent + 1
        return (
            f"{indent}def __init__(self) -> None:\n"
            f'{indent_2}"""\n'
            f"{indent_2}Raises an exception.\n"
            f"{indent_2}This class cannot be instantiated from Python.\n"
            f'{indent_2}"""\n'
        )

    def _get_cls_member_data(
        self,
        cls_member: types.MethodDescriptorType,
        cls_member_name: str,
        cls_name: str,
        module_name: str,
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
        if return_type and return_type.strip() in ("tuple", "list", "dict"):
            logger.warning(
                "not fully resolved return type: "
                f"{module_name}::{cls_name}::{cls_member_name} "
                f"-> {return_type}"
            )

        return _ClsMemberData(signatures, return_type, docstring)


class PyBoostModule(NamedTuple):
    name: str
    orig_name: str


class _ModulePyiGenerator:
    def __init__(
        self,
        module: types.ModuleType,
        all_modules: t.Iterable[PyBoostModule],
        docstrings: DocstringsManager,
        return_types: ReturnTypesManager,
        line_length=LINE_LENGTH,
        boost_types: BoostPythonTypes = BoostPythonTypes(),
    ):
        self.module = module
        self.all_modules = list(all_modules)
        self.docstrings = docstrings
        self.return_types = return_types
        self.line_length = line_length
        self.boost_types = boost_types
        self._boost_python_instance_class_generator = _BoostPythonInstanceClassPyiGenerator(
            docstrings=self.docstrings,
            return_types=self.return_types,
            indent=Indent(0),
            line_length=self.line_length,
            boost_types=self.boost_types,
        )
        self.stub_src = StubSrcManager.for_module(module)

    def _write_module_header(self, enums: bool):
        chunks: list[str] = ["from __future__ import annotations\n"]
        chunks.append("from typing import Any, ClassVar, Collection, Iterator, Self, overload\n")
        chunks.append(self._write_pyrx_import())
        chunks.append("import wx\n")
        if enums:
            chunks.append("from pyrx.doc_utils.boost_meta import _BoostPythonEnum\n")
        return "".join(chunks)

    def _write_pyrx_import(self) -> str:
        return (
            "\n".join(
                f"from pyrx import {module.name} as {module.orig_name}"
                for module in self.all_modules
            )
            + "\n"
        )

    def _skip_member(self, name: str, obj) -> bool:
        if name.startswith("__") and name.endswith("__"):
            return True
        return False

    def get_chunks(self) -> c.Generator[range | str, None, None]:
        module = self.module
        module_name = module.__name__
        classes: list[tuple[str, type, Node | None]] = []
        functions: list[tuple[str, BoostPythonFunction, Node | None]] = []
        global_enum_members: list[tuple[str, BoostPythonEnum]] = []
        if self.stub_src is not None:
            stub_nodes = {node.name: node for node in self.stub_src.tree.children}
        else:
            stub_nodes = {}
        for member_name, member in inspect.getmembers(module):
            try:
                stub_node = stub_nodes.pop(member_name)
            except KeyError:
                stub_node = None
            if stub_node is not None and self._skip_member(member_name, member):
                continue
            if inspect.isclass(member):
                classes.append((member_name, member, stub_node))
            elif isinstance(member, self.boost_types.enum):
                if stub_node is not None:
                    raise NotImplementedError(
                        f"stub node for enum member {module_name}::{member_name}"
                    )
                global_enum_members.append((member_name, member))
            elif isinstance(member, self.boost_types.function):
                functions.append((member_name, member, stub_node))
            else:
                logger.error(
                    f"Unknown member (class) of module {module_name}:\n"
                    f"\tname: {member_name}\n"
                    f"\trepr: {member!r}"
                )

        yield (
            self._write_module_header(
                enums=any(issubclass(cls, self.boost_types.enum) for _, cls, _ in classes)
            )
        )
        if self.stub_src is not None and self.stub_src.header is not None:
            yield self.stub_src.header

        for enum_name, enum_obj in global_enum_members:
            yield (self._write_global_enum_member(enum_name, enum_obj))

        for cls_name, cls, node in classes:
            if issubclass(cls, self.boost_types.instance):
                yield from self._write_boost_python_instance_class(
                    cls_name, cls, module_name, node
                )
            elif issubclass(cls, self.boost_types.enum):
                if node is not None:
                    raise NotImplementedError(
                        f"stub node for enum class {module_name}::{cls_name}"
                    )
                yield (self._write_boost_python_enum_class(cls_name, cls))

            elif cls_name == "ErrorStatusException":  # special case
                if node is not None:
                    yield node.range
            else:
                logger.warning(
                    f"Skipping a member of the {module_name} module:\n"
                    f"\tname: {cls_name}\n"
                    f"\trepr: {cls!r}"
                )

        for func_name, func, node in functions:
            if node is not None:
                yield node.range
            else:
                yield (self._write_boost_python_function(func_name, func))

    def gen_iter(self) -> c.Generator[str, None, None]:
        chunks = tuple(self.get_chunks())
        stub_src = self.stub_src

        if stub_src is not None:
            prev_range_stop = 0

        for chunk in chunks:
            if isinstance(chunk, range):
                child_range = chunk
                if not child_range.start > prev_range_stop:
                    # We assume that the order of the stubs file should
                    # be the same as when generated - alphabetically in
                    # groups
                    raise ValueError(
                        f"The order of stub nodes is incorrect: "
                        f"{self.module.__name__}:{child_range.start}-{child_range.stop}"
                    )
                # in addition to the current node's line, we also return
                # everything from the end of the previous (detected)
                # node, these can be e.g. overloads, TypeVar
                # definitions, etc.
                assert stub_src is not None
                yield stub_src.get_body_range(prev_range_stop + 1, child_range.stop)
                prev_range_stop = child_range.stop
            else:
                yield chunk

        if stub_src is not None:
            # return all lines until the end of file
            yield stub_src.get_body_range(prev_range_stop + 1, None)

    def gen(self) -> str:
        return "".join(self.gen_iter())

    def _write_global_enum_member(self, enum_name: str, enum_obj: BoostPythonEnum) -> str:
        return f"{enum_name}: {type(enum_obj).__name__}  # {int(enum_obj)}\n"

    def _write_boost_python_enum_class(
        self, cls_name: str, cls_obj: t.Type[BoostPythonEnum]
    ) -> str:
        indent = Indent()
        member_indent = indent + 1
        chunks: list[str] = []
        chunks.append(f"class {cls_name}(_BoostPythonEnum):\n")
        for member_name, member in cls_obj.names.items():
            chunks.append(f"{member_indent}{member_name}: ClassVar[Self]  # {int(member)}\n")
        return "".join(chunks)

    def _write_boost_python_instance_class(
        self, cls_name: str, cls: t.Type[BoostPythonInstance], module_name: str, node: Node | None
    ) -> c.Generator[range | str, None, None]:
        return self._boost_python_instance_class_generator.gen(
            cls=cls, module_name=module_name, node=node
        )

    def _write_boost_python_function(self, func_name: str, func_obj: BoostPythonFunction) -> str:
        indent = Indent(0)
        indent_2 = indent + 1
        # TODO: combine with _BoostPythonInstanceClassPyiGenerator._get_cls_member_data
        docstring = getattr(func_obj, "__doc__", None)
        if docstring is not None:
            return_type = get_return_type(docstring)
        else:
            return_type = None
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


def gen_pyi(
    module: types.ModuleType,
    all_modules: t.Iterable[PyBoostModule],
    docstrings: DocstringsManager,
    return_types: ReturnTypesManager,
    line_length=LINE_LENGTH,
    boost_types: BoostPythonTypes = BoostPythonTypes(),
):
    return _ModulePyiGenerator(
        module=module,
        all_modules=all_modules,
        docstrings=docstrings,
        return_types=return_types,
        line_length=line_length,
        boost_types=boost_types,
    )
