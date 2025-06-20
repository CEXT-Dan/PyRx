from __future__ import annotations

import pytest

from pyrx import Ap, Ge


class TestAx3DSolid:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_checkInterference(self):
        axSpace = self.axDoc.modelSpace()
        ent1 = axSpace.addBox(Ge.Point3d(0, 0, 0), 100, 200, 300)
        ent2 = axSpace.addBox(Ge.Point3d(10, 10, 10), 100, 200, 300)
        assert ent1.objectName() == "AcDb3dSolid"
        assert ent2.objectName() == "AcDb3dSolid"
        inter, ent3 = ent1.checkInterference(ent2,True)
        assert ent3.objectName() == "AcDb3dSolid"
        assert inter == True
