from __future__ import annotations

from pyrx import Ap, Db, Ge


class TestSortentsTable:
    def test_getinstance(self):
        db = Db.curDb()
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()
        axEnt1 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        axEnt2 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        id1 = axEnt1.objectId()
        id2 = axEnt2.objectId()

        model = Db.BlockTableRecord(db.modelSpaceId())
        sortEnts = model.getSortentsTable(Db.OpenMode.kForWrite, True)

        sortEnts.moveToTop([id1])
        sortEnts.moveToBottom([id2])
        assert sortEnts.firstEntityIsDrawnBeforeSecond(id1, id2) == False

        sortEnts.swapOrder(id1, id2)
        assert sortEnts.firstEntityIsDrawnBeforeSecond(id1, id2) == True

        sortEnts.moveToTop([id1])
        sortEnts.moveToBottom([id2])
        assert sortEnts.firstEntityIsDrawnBeforeSecond(id1, id2) == False

        sortEnts.moveToTop([id2])
        sortEnts.moveToBottom([id1])
        assert sortEnts.firstEntityIsDrawnBeforeSecond(id1, id2) == True
