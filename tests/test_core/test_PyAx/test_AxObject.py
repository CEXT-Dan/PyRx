from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxObject:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        self.axDoc.registeredApplications().add("PYRX_TESTXD")

    def test_xdata(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        xdin = [
            (1001, "PYRX_TESTXD"),
            (1000, "This is a test for xdata"),
            (1003, "0"),
            (1040, 1.23479),
            (1041, 1237324938.0),
            (1070, 32767),
            (1071, 32767),
            (1042, 10.0),
            (1010, Ge.Point3d(1.00000000000000, 2.00000000000000, 3.00000000000000)),
            (1011, Ge.Point3d(4.00000000000000, 5.00000000000000, 6.00000000000000)),
        ]
        ent.setXdata(xdin)
        assert xdin == ent.xdata("PYRX_TESTXD")

    def test_extensionDictionary(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        data = [
            (1, "PYRX_XREC_VALUE"),
            (10, Ge.Point3d(4.00000000000000, 5.00000000000000, 6.00000000000000)),
        ]
        xdict = ent.extensionDictionary()
        xrec = xdict.addXRecord("PYRX_XREC_KEY")
        xrec.setXRecordData(data)
        xrecout = Ax.AcadXRecord.cast(xdict.object("PYRX_XREC_KEY"))
        assert xrecout.xrecordData() == data
