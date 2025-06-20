from __future__ import annotations

import pytest
import wx

from pyrx import Db, Gs


class TestGsCore:
    @pytest.mark.known_failure_GRX
    def test_gs_getBlockImage(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("36f")
        objId = db_dynblock.getObjectId(False, objHnd)
        img: wx.Image = Gs.Core.getBlockImage(objId, 32, 32, 1.0, [0, 0, 0])
        assert img.IsOk() == True
        assert img.GetHeight() == 32
        assert img.GetWidth() == 32
