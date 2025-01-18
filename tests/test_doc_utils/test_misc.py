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
        assert row4.value == " Returns the name of the tree node. "  # skip \xa0


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


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
