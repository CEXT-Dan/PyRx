import logging
import re
from difflib import SequenceMatcher
from pathlib import Path

import pytest

if True:
    pytest.skip(allow_module_level=True,reason ="invalid inherited docstring #216")

from pyrx import Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm  # noqa
from pyrx.doc_utils.misc import DocstringsManager, ReturnTypesManager
from pyrx.doc_utils.pyi_gen import (
    Indent,
    _BoostPythonInstanceClassPyiGenerator,
    _ModulePyiGenerator,
    wrap_docstring,
    write_method,
)
from pyrx.doc_utils.rx_meta import RX_BOOST_TYPES, build_py_boost_modules

logger = logging.getLogger(__name__)


class TestIndent:
    def test_init(self):
        indent = Indent()
        assert indent._indent == 0

        indent = Indent(2)
        assert indent._indent == 2

        indent = Indent(3)
        new_indent = Indent(indent)
        assert new_indent is not indent
        assert new_indent._indent == 3

        with pytest.raises(TypeError, match="arg must be of type int or Indent, not float"):
            Indent(1.0)  # type: ignore[arg-type]

    def test_increase(self):
        indent = Indent()
        new_indent = indent.increase()
        assert new_indent is not indent
        assert indent._indent == 0
        assert new_indent._indent == 1

    def test_decrease(self):
        indent = Indent(1)
        new_indent = indent.decrease()
        assert new_indent is not indent
        assert indent._indent == 1
        assert new_indent._indent == 0

        with pytest.raises(ValueError, match="already zero"):
            new_indent.decrease()

    def test_add_int(self):
        indent = Indent(1)
        new_indent = indent + 2
        assert new_indent is not indent
        assert new_indent._indent == 3

    def test_add_indent(self):
        indent1 = Indent(1)
        indent2 = Indent(2)
        new_indent = indent1 + indent2
        assert new_indent is not indent1 and new_indent is not indent2
        assert new_indent._indent == 3

    def test_add_other(self):
        with pytest.raises(TypeError):
            Indent() + 1.0

    def test_sub_int(self):
        indent = Indent(3)
        new_indent = indent - 2
        assert new_indent is not indent
        assert new_indent._indent == 1

    def test_sub_indent(self):
        indent1 = Indent(3)
        indent2 = Indent(2)
        new_indent = indent1 - indent2
        assert new_indent is not indent1 and new_indent is not indent2
        assert new_indent._indent == 1

    def test_sub_other(self):
        with pytest.raises(TypeError):
            Indent() - 1.0

    def test_sub_less_that_zero(self):
        with pytest.raises(ValueError, match=re.escape("cannot be less that 0 (-2)")):
            Indent() - 2

    def test_len(self):
        indent1 = Indent()
        assert indent1.len == len(indent1) == 0

        indent2 = Indent(2)
        assert indent2.len == len(indent2) == 8

    def test_str(self):
        assert str(Indent()) == ""
        assert str(Indent(1)) == "    "
        assert str(Indent(2)) == "        "


@pytest.mark.parametrize(
    "docstring, indent, line_length, expected",
    (
        pytest.param(
            "line1  line2  line3",
            2,
            14,
            (
                "        line1\n"  # noqa
                "        line2\n"  # noqa
                "        line3"  # noqa
            ),
            id="001",
        ),
        pytest.param(
            (
                "This class describes the interface that must be implemented by the (optional) "
                "NavTree Publisher. The NavTree publisher controls what will appear in the "
                "navigation tree in the Viewer. "
            ),
            Indent(1),
            99,
            (
                "    This class describes the interface that must be implemented by the (optional) NavTree\n"
                "    Publisher. The NavTree publisher controls what will appear in the navigation tree in the\n"
                "    Viewer."
            ),
            id="002",
        ),
    ),
)
def test_wrap_docstring(docstring: str, indent: int | Indent, line_length: int, expected: str):
    res = wrap_docstring(docstring, indent, line_length)
    assert res == expected.removeprefix("\n")


@pytest.mark.parametrize(
    "name, signatures, return_type, docstring, is_static, is_property, indent, expected",
    (
        pytest.param(
            "setUcs",
            (
                "self, origin: PyGe.Point3d, xAxis: PyGe.Vector3d, yAxis : PyGe.Vector3d, ",
                "self, view: PyDb.OrthographicView, /",
                "self, ucsId: PyDb.ObjectId, /",
            ),
            "None",
            (
                "        This function sets the UCS for the view or\n"
                "        viewport table record. The new UCS will be\n"
                "        unnamed and is defined by origin, xAxis, and yAxis."
            ),
            False,
            False,
            1,
            '''    @overload
    def setUcs(self, origin: PyGe.Point3d, xAxis: PyGe.Vector3d, yAxis : PyGe.Vector3d, /) -> None: ...
    @overload
    def setUcs(self, view: PyDb.OrthographicView, /) -> None: ...
    @overload
    def setUcs(self, ucsId: PyDb.ObjectId, /) -> None: ...
    @overload
    def setUcs(self, *args) -> None:
        """
        This function sets the UCS for the view or
        viewport table record. The new UCS will be
        unnamed and is defined by origin, xAxis, and yAxis.
        """
''',
            id="001",
        ),
        pytest.param(
            "entSel",
            ("self",),
            None,
            None,
            False,
            False,
            2,
            """        def entSel(self, /) -> Any: ...
""",
            id="002",
        ),
        pytest.param(
            "intersectWith",
            (
                " ( self, entity: PyDb.Entity, intType : PyDb.Intersect, /) ",
                "self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int",
            ),
            "list[PyGe.Point3d]",
            None,
            True,
            False,
            1,
            """    @overload
    @staticmethod
    def intersectWith(entity: PyDb.Entity, intType : PyDb.Intersect, /) -> list[PyGe.Point3d]: ...
    @overload
    @staticmethod
    def intersectWith(entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int, /) -> list[PyGe.Point3d]: ...
    @overload
    @staticmethod
    def intersectWith(*args) -> list[PyGe.Point3d]: ...
""",
            id="003",
        ),
        pytest.param(
            "sx",
            ("self",),
            None,
            None,
            False,
            True,
            1,
            """    @property
    def sx(self, /) -> Any: ...
""",
            id="004",
        ),
    ),
)
def test_write_method(
    name, signatures, return_type, docstring, is_static, is_property, indent, expected
):
    res = write_method(name, signatures, return_type, docstring, is_static, is_property, indent)
    assert res == expected, f"{res} != {expected}"


EXPECTED_DATA_SEPARATOR = "# (...) #"

BOOST_PYTHON_INSTANCE_CLASS_EXPECTED_DIR = (
    Path(__file__).parent / "resources/test_pyi_gen/BoostPythonInstanceClassPyiGenerator"
)


def _get_expected_BoostPythonInstanceClassPyi(filename: str) -> list[str]:
    abs_filename = BOOST_PYTHON_INSTANCE_CLASS_EXPECTED_DIR / filename
    assert abs_filename.exists()
    return abs_filename.read_text("utf-8").split(EXPECTED_DATA_SEPARATOR)


@pytest.mark.parametrize(
    "cls, module, module_name, indent, line_length, expected",
    (
        pytest.param(
            Ed.Editor,
            Ed,
            "PyEd",
            0,
            99,
            _get_expected_BoostPythonInstanceClassPyi("Ed.Editor.txt"),
            id="001",
        ),
        pytest.param(
            Db.AbstractViewTableRecord,
            Db,
            "PyDb",
            1,
            99,
            _get_expected_BoostPythonInstanceClassPyi("Db.AbstractViewTableRecord.txt"),
            id="002",
        ),
        pytest.param(
            Ge.Point3d,
            Ge,
            "PyGe",
            0,
            40,
            _get_expected_BoostPythonInstanceClassPyi("Ge.Point3d.txt"),
            id="003",
        ),
        pytest.param(
            Ap.CmdFlags,
            Ap,
            "PyAp",
            0,
            99,
            _get_expected_BoostPythonInstanceClassPyi("Ap.CmdFlags.txt"),
            id="004",
        ),
        pytest.param(
            Gi.CommonDraw,
            Gi,
            "PyGi",
            0,
            99,
            _get_expected_BoostPythonInstanceClassPyi("Gi.CommonDraw.txt"),
            id="005",
        ),
    ),
)
def test_BoostPythonInstanceClassPyiGenerator(
    cls,
    module,
    module_name,
    indent,
    line_length,
    expected,
    docstrings: DocstringsManager,
    return_types: ReturnTypesManager,
):
    obj = _BoostPythonInstanceClassPyiGenerator(
        docstrings=docstrings,
        return_types=return_types,
        indent=indent,
        line_length=line_length,
        boost_types=RX_BOOST_TYPES,
    )
    res = "".join(
        chunk
        for chunk in obj.gen(cls=cls, module_name=module_name, node=None)
        if isinstance(chunk, str)
    )
    for expected_chunk in expected:
        try:
            assert expected_chunk in res
        except AssertionError:
            logger.error(f"RESULT:\n{res}\nEXPECTED:\n{expected_chunk}")
            raise


MODULE_PYI_GENERATOR_EXPECTED_DIR = (
    Path(__file__).parent / "resources/test_pyi_gen/ModulePyiGenerator"
)


def _get_expected_ModulePyiGenerator(filename: str) -> list[str]:
    abs_filename = MODULE_PYI_GENERATOR_EXPECTED_DIR / filename
    assert abs_filename.exists()
    return abs_filename.read_text("utf-8").split(EXPECTED_DATA_SEPARATOR)


class Test_ModulePyiGenerator:
    @pytest.mark.parametrize(
        "cls_name, cls_obj, expected",
        (
            pytest.param(
                "OpenMode",
                Db.OpenMode,
                _get_expected_ModulePyiGenerator("Db.OpenMode.txt"),
                id="001",
            ),
        ),
    )
    def test_write_boost_python_enum_class(
        self, cls_name, cls_obj, expected, docstrings, return_types
    ):
        obj = _ModulePyiGenerator(
            module=Db,
            all_modules=(),
            docstrings=docstrings,
            return_types=return_types,
            line_length=99,
            boost_types=RX_BOOST_TYPES,
        )
        res = obj._write_boost_python_enum_class(cls_name, cls_obj)
        for expected_chunk in expected:
            try:
                assert expected_chunk in res
            except AssertionError:
                logger.error(f"\nRESULT:\n{res}\nEXPECTED:\n{expected_chunk}")
                raise

    @pytest.mark.parametrize(
        "module, enum_name, enum_obj, expected",
        (
            pytest.param(
                Db,
                "kForReadAndAllShare",
                Db.kForReadAndAllShare,
                _get_expected_ModulePyiGenerator("Db.kForReadAndAllShare.txt"),
                id="001",
            ),
        ),
    )
    def test_write_global_enum_member(
        self, module, enum_name, enum_obj, expected, docstrings, return_types
    ):
        obj = _ModulePyiGenerator(
            module=module,
            all_modules=(),
            docstrings=docstrings,
            return_types=return_types,
            line_length=99,
            boost_types=RX_BOOST_TYPES,
        )
        res = obj._write_global_enum_member(enum_name, enum_obj)
        for expected_chunk in expected:
            try:
                assert expected_chunk in res
            except AssertionError:
                logger.error(f"\nRESULT:\n{res}\nEXPECTED:\n{expected_chunk}")
                raise

    @pytest.mark.parametrize(
        "module, expected",
        (
            pytest.param(
                Db,
                _get_expected_ModulePyiGenerator("Db.txt"),
                id="001",
            ),
            pytest.param(
                Ap,
                _get_expected_ModulePyiGenerator("Ap.txt"),
                id="002",
            ),
        ),
    )
    def test_gen(self, module, expected, docstrings, return_types):
        modules = (Ap, Ax, Br, Db, Ed, Ge, Gi, Gs, Pl, Rx, Sm)
        boost_modules = build_py_boost_modules(modules)
        obj = _ModulePyiGenerator(
            module=module,
            all_modules=boost_modules,
            docstrings=docstrings,
            return_types=return_types,
            line_length=99,
            boost_types=RX_BOOST_TYPES,
        )
        res = obj.gen()
        for expected_chunk in expected:
            try:
                assert expected_chunk in res
            except AssertionError:
                pass
            else:
                continue
            pytest.fail(
                "*** NOT FOUND: ***\n\n"
                f"{expected_chunk}\n\n"
                "*** BEST MATCH: ***\n\n"
                f"{find_best_match(res, expected_chunk)}\n\n"
                f"*** RESULT: ***\n{res}\n\n",
                pytrace=False,
            )


def find_best_match(text: str, query: str):
    m = SequenceMatcher(None, text, query, autojunk=False).find_longest_match()
    if m.size == 0:
        return None
    start = m.b
    end = m.b + m.size
    return query[start:end]


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
