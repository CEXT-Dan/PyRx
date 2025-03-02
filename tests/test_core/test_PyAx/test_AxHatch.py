from __future__ import annotations
from pyrx import Ap, Ge, Ax


class TestAxHatch:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_AppendLoops (self):
        axSpace = self.axDoc.modelSpace()
        outerloop = axSpace.addCircle(Ge.Point3d.kOrigin,10)
        innerloop = axSpace.addCircle(Ge.Point3d.kOrigin,5)
        hatch = axSpace.addHatch(0,"ANGLE",True)
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
        
        


        


