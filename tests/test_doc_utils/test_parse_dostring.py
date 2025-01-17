from pathlib import Path

import pytest

from pyrx.doc_utils import get_base_signature

BASE_DIR = Path(__file__).parent
RESOURCES = BASE_DIR / "resources"
DOCSTRING_DIR = RESOURCES / "docstrings"


@pytest.fixture
def read_dostring():
    def run(filename: str):
        abs_path = DOCSTRING_DIR / filename
        if not abs_path.exists():
            raise FileNotFoundError(str(abs_path))
        return abs_path.read_text(encoding="utf-8")

    return run


@pytest.mark.parametrize(
    "docstring_file, expected",
    (
        pytest.param("Db.AbstractViewTableRecord.setUcs.txt", "self, ", id="001"),
        pytest.param(
            "Db.Database.readDwgFile.txt",
            "self, fileName: str, mode: DatabaseOpenMode=DatabaseOpenMode.kForReadAndReadShare, bAllowCPConversion:bool=False, password:str='empty'",
            id="002",
        ),
        pytest.param(
            "Db.Entity.setLayer.txt",
            "self, val: str|PyDb.ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False",
            id="003",
        ),
        pytest.param("Ed.Editor.entSel.txt", "/", id="004"),
        pytest.param("invalid.txt", None, id="005"),
    ),
)
def test_get_base_signature(docstring_file, expected, read_dostring):
    docstring = read_dostring(docstring_file)
    res = get_base_signature(docstring)
    assert res == expected


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
