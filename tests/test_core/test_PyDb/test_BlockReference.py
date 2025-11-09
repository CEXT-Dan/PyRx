from __future__ import annotations

import math
import unittest

import pytest

from pyrx import Ap, Db, Ge

class TestDbBlockReference:

    def test_hasAttributes_1(self, db_06457: Db.Database):
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)
        assert r.hasAttributes() == True
        
    def test_hasAttributes_2(self, db_06457: Db.Database):
        objHnd = Db.Handle("54d2e")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)
        assert r.hasAttributes() == False


