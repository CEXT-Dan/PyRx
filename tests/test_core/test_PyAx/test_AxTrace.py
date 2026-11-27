from __future__ import annotations

from pyrx import Ap, Ax, Ge


# a 2D trace (AcDbTrace) is a closed shape created from a set of vertices
class TestAxTrace:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    @staticmethod
    def _trace_pnts() -> list[Ge.Point3d]:
        return [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]

    def test_create(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        assert ent.objectName() == "AcDbTrace"
        assert ent.entityType() == Ax.AcEntityName.acTrace

    def test_cast(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        trace = Ax.AcadTrace.cast(ent)
        assert trace is not None
        assert isinstance(trace, Ax.AcadTrace)

    def test_className(self):
        assert Ax.AcadTrace.className() == "AcadTrace"

    def test_coordinates(self):
        pnts = self._trace_pnts()
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(pnts)
        coords = ent.coordinates()
        # all four input vertices must be present in the returned coordinates
        assert len(coords) >= 4
        assert set(pnts) <= set(coords)

    def test_setCoordinates(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        new_pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(50, 0, 0),
            Ge.Point3d(50, 50, 0),
            Ge.Point3d(0, 50, 0),
        ]
        ent.setCoordinates(new_pnts)
        assert set(new_pnts) <= set(ent.coordinates())

    def test_normal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        # a trace lying in the XY plane has its normal parallel to the Z axis
        assert ent.normal().isParallelTo(Ge.Vector3d.kZAxis)

    def test_setNormal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        ent.setNormal(Ge.Vector3d.kYAxis)
        assert ent.normal().isParallelTo(Ge.Vector3d.kYAxis)

    def test_thickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        # a freshly created flat trace has zero thickness
        assert ent.thickness() == 0

    def test_setThickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTrace(self._trace_pnts())
        ent.setThickness(10)
        assert ent.thickness() == 10
