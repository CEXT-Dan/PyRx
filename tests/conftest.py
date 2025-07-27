from __future__ import annotations

import typing as t
from pathlib import Path

import pytest

from pyrx import Db
from tests import MEDIA_DIR

if t.TYPE_CHECKING:
    import _typeshed as _t


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
    db.readDwgFile(str(path), Db.DatabaseOpenMode.kForReadAndAllShare, False, "")
    db.closeInput(True)
    return db


@pytest.fixture(scope="session")
def db_subentpe():
    db = _load_db("subentpe.dwg")
    yield db


@pytest.fixture(scope="session")
def db_06457():
    db = _load_db("06457.dwg")
    yield db


@pytest.fixture(scope="session")
def db_brep():
    db = _load_db("TestBrep.dwg")
    yield db


@pytest.fixture(scope="session")
def db_dynblock():
    db = _load_db("DynBlock.dwg")
    yield db


@pytest.fixture(scope="session")
def db_geo():
    db = _load_db("geomarker.dwg")
    yield db


@pytest.fixture(scope="session")
def db_points():
    db = _load_db("TestPoints.dwg")
    yield db


@pytest.fixture(scope="session")
def db_brcivil():
    db = _load_db("BCADCIVIL1.dwg")
    yield db


@pytest.fixture(scope="session")
def db_block_reference():
    db = _load_db("block_reference.dwg")
    return db

@pytest.fixture(scope="session")
def db_xrefGraph():
    db = _load_db("XrefGraph.dwg")
    return db

@pytest.fixture(scope="session")
def db_dyn_block_ref():
    db = _load_db("dyn_block_ref.dwg")
    return db