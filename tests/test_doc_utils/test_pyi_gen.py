import re

import pytest

from pyrx.doc_utils.pyi_gen import Indent, write_docstring


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
            Indent(1.0)

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
            '''
        """
        line1
        line2
        line3
        """
''',
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
            '''
    """
    This class describes the interface that must be implemented by the (optional) NavTree
    Publisher. The NavTree publisher controls what will appear in the navigation tree in the
    Viewer.
    """
''',
            id="002",
        ),
    ),
)
def test_write_docstring(docstring: str, indent: int | Indent, line_length: int, expected: str):
    res = write_docstring(docstring, indent, line_length)
    assert res == expected.removeprefix("\n")


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
