from __future__ import annotations

import typing as t
from pathlib import Path

import pytest

from pyrx import Db

if t.TYPE_CHECKING:
    import _typeshed as _t

BASE_DIR = Path(__file__).parent
MEDIA_DIR = BASE_DIR / "media"


def _load_db(path: _t.StrPath):
    """
    Attributes:
        path: absolute or relative path to media directory
    """
    path = Path(path)
    if not path.is_absolute():
        path = MEDIA_DIR / path
    if not path.exists():
        raise FileNotFoundError(str(path))
    db = Db.Database(False, True)
    db.readDwgFile(str(path))
    db.closeInput(True)
    return db


@pytest.fixture(scope="session")
def db_06457():
    db = _load_db("06457.dwg")
    yield db
