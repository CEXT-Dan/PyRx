from __future__ import annotations

from pytest import approx

from pyrx import Ap, Ax


class TestAxUtility:
    
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        
    def test_angleToReal(self):
        axUt = self.axDoc.utility()
        val = axUt.angleToReal("45", Ax.AcAngleUnits.acDegrees )
        assert val == approx(0.785398)
        

