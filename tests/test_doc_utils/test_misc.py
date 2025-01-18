import pytest

from pyrx.doc_utils.misc import DocstringRow, DocstringsManager


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


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
