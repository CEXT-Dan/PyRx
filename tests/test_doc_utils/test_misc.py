import pytest

from pyrx.doc_utils.misc import (
    DocstringRow,
    DocstringsManager,
    ReturnTypeRow,
    ReturnTypesManager,
)


class TestDocstringsManager:
    def test_from_json(self):
        obj = DocstringsManager.from_json()
        assert isinstance(obj, DocstringsManager)
        rows = obj.rows
        assert len(rows) > 100

        row1 = rows[0]
        assert isinstance(row1, DocstringRow)
        assert row1.id == 1
        assert row1.name == "ac3ddwfnavtreenode"
        assert row1.value.startswith("This class describes the interface that must be implemented")

        row4 = rows[3]
        assert row4.value == "Returns the name of the tree node. "  # \xa0 → " "

    @pytest.mark.parametrize(
        "key, expected",
        (
            pytest.param(4, "Returns the name of the tree node. ", id="001"),
            pytest.param(
                7, "Returns the graphic identifiers included in this tree node. ", id="002"
            ),
            pytest.param(20000, None, id="003"),
        ),
    )
    def test_get(self, key, expected, docstrings: DocstringsManager):
        res = docstrings.get(key)
        assert res == expected


class TestReturnTypesManager:
    def test_from_json(self):
        obj = ReturnTypesManager.from_json()
        assert isinstance(obj, ReturnTypesManager)
        rows = obj.rows
        assert len(rows) > 100

        row1 = rows[0]
        assert isinstance(row1, ReturnTypeRow)
        assert row1.module == "PyEd"
        assert row1.cls == "Editor"
        assert row1.func == "getKword"
        assert row1.value == "tuple[int, str]"

        row22 = rows[21]
        assert row22.module is None
        assert row22.cls is None
        assert row22.func == "objectIds"
        assert row22.value == "list[PyDb.ObjectId]"

        row32 = rows[31]
        assert row32.module == "PyDb"
        assert row32.cls is None
        assert row32.func == "explode"
        assert row32.value == "list[PyDb.Entity]"

    def test_rows_dict(self, return_types: ReturnTypesManager):
        dict_ = return_types.rows_dict
        assert dict_ is return_types.rows_dict

        assert dict_[("PyEd", "Editor", "getKword")] == "tuple[int, str]"
        assert dict_[("PyDb", None, "explode")] == "list[PyDb.Entity]"
        assert dict_[(None, None, "objectIds")] == "list[PyDb.ObjectId]"

    @pytest.mark.parametrize(
        "module, cls, func, expected",
        (
            pytest.param("PyEd", "Editor", "getKword", "tuple[int, str]", id="001"),
            pytest.param("PyDb", "Entity", "explode", "list[PyDb.Entity]", id="002"),
            pytest.param("PyDb", "BlockTableRecord", "objectIds", "list[PyDb.ObjectId]", id="003"),
            pytest.param("PyDb", "BlockTableRecord", "unknown_func", None, id="004"),
        ),
    )
    def test_get(self, module, cls, func, expected, return_types: ReturnTypesManager):
        res = return_types.get(module, cls, func)
        assert res == expected


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
