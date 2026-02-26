from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestALeader:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        
    def test_create(self):
        axSpace = self.axDoc.modelSpace()
        mtextObj = axSpace.addMText(Ge.Point3d(10,10,0),2,"PyRx ActiveX Leader")
        leaderPoints = [
            Ge.Point3d(0.0, 0.0, 0.0),    # Arrowhead point
            Ge.Point3d(4.0, 4.0, 0.0),    # Elbow point
            Ge.Point3d(10.0, 10.0, 0.0)   # Connection to text
        ]
        leaderObj = axSpace.addLeader(leaderPoints, mtextObj, Ax.AcLeaderType.acLineWithArrow)
        leaderObj.update()
        mt = leaderObj.annotation()
        assert mt.objectId() == mtextObj.objectId()
        assert len(leaderObj.coordinates()) ==len(leaderPoints)
        assert leaderObj.coordinate(0) == leaderPoints[0]
        assert leaderObj.coordinate(1) == leaderPoints[1]
        assert leaderObj.leaderType() == Ax.AcLeaderType.acLineWithArrow
