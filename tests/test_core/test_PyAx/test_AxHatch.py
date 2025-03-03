from __future__ import annotations
from pyrx import Ap, Ge, Ax
import pytest


class TestAxHatch:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    @pytest.mark.known_failure_BRX
    def test_AppendLoops (self):
        axSpace = self.axDoc.modelSpace()
        outerloop = axSpace.addCircle(Ge.Point3d.kOrigin,10)
        innerloop = axSpace.addCircle(Ge.Point3d.kOrigin,5)
        hatch = axSpace.addHatch(1,"ANGLE",True)
        hatch.appendOuterLoop([outerloop])
        hatch.appendInnerLoop([innerloop])
        hatch.evaluate()
        assert hatch.numberOfLoops() == 2
        assert hatch.objectName() == "AcDbHatch"
        outerloops = hatch.loopAt(0)
        assert len(outerloops) == 1
        assert outerloops[0].objectName() == "AcDbCircle"
        innerloops = hatch.loopAt(1)
        assert len(innerloops) == 1
        assert innerloops[0].objectName() == "AcDbCircle"
        
    @pytest.mark.known_failure_BRX
    def test_Gradient (self):
        axSpace = self.axDoc.modelSpace()
        outerloop = axSpace.addCircle(Ge.Point3d.kOrigin,10)
        innerloop = axSpace.addCircle(Ge.Point3d.kOrigin,5)
        hatch = axSpace.addHatch(1,"ANGLE",True)
        hatch.setHatchObjectType(Ax.AcHatchObjectType.acGradientObject)
        hatch.appendOuterLoop([outerloop])
        hatch.appendInnerLoop([innerloop])
        hatch.setGradientColor1(Ax.AcadAcCmColor(255,0,0))
        hatch.setGradientColor2(Ax.AcadAcCmColor(0,255,0))
        hatch.evaluate()
        clr1 = hatch.gradientColor1()
        assert clr1.red() == 255
        assert clr1.green() == 0
        assert clr1.blue() == 0
        clr2 = hatch.gradientColor2()
        assert clr2.red() == 0
        assert clr2.green() == 255
        assert clr2.blue() == 0

        
        
        


