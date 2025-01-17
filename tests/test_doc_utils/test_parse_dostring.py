from pathlib import Path

import pytest

from pyrx.doc_utils import get_base_signature, get_overloads

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


@pytest.mark.parametrize(
    "docstring_file, expected",
    (
        pytest.param(
            "Db.AbstractViewTableRecord.setUcs.txt",
            """
    - origin: PyGe.Point3d, xAxis: PyGe.Vector3d, yAxis : PyGe.Vector3d
    - view: PyDb.OrthographicView
    - ucsId: PyDb.ObjectId
""",
            id="001",
        ),
        pytest.param(
            "Db.Entity.intersectWith.txt",
            """
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
""",
            id="002",
        ),
        pytest.param("Db.DbObject.wblockClone.txt", None, id="003"),
    ),
)
def test_get_overloads(docstring_file, expected, read_dostring):
    docstring = read_dostring(docstring_file)
    res = get_overloads(docstring)
    if res is None:
        assert res is expected
    else:  # isinstance(res, str)
        assert res.strip() == expected.strip()


if __name__ == "__main__":
    pytest.main([f"{__file__}"])
