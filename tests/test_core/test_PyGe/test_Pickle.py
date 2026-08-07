from __future__ import annotations

import math
import pickle


from pyrx import Ge


class TestGePickle:

    def test_Scale2d(self):
        original = Ge.Scale2d(10, 100)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Point2d(self):
        original = Ge.Point2d(10, 100)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Vector2d(self):
        original = Ge.Vector2d(10, 100)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Matrix2d(self):
        original = Ge.Matrix2d()
        original.setToRotation(math.radians(45))
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Scale3d(self):
        original = Ge.Scale3d(10, 100, 1000)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Point3d(self):
        original = Ge.Point3d(10, 100, 1000)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Vector3d(self):
        original = Ge.Vector3d(10, 100, 1000)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Matrix3d(self):
        original = Ge.Matrix3d()
        original.setToRotation(math.radians(45), Ge.Vector3d.kZAxis)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert original == restored

    def test_Plane(self):
        origin = Ge.Point3d(1.0, 2.0, 3.0)
        u_axis = Ge.Vector3d(1.0, 0.0, 0.0)
        v_axis = Ge.Vector3d(0.0, 1.0, 0.0)
        original = Ge.Plane(origin, u_axis, v_axis)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        restored.get() == original.get()

    def test_BoundedPlane(self):
        origin = Ge.Point3d(0, 0, 0)
        u_axis = Ge.Point3d(100, 0, 0) - origin
        v_axis = Ge.Point3d(0, 100, 0) - origin
        original = Ge.BoundedPlane(origin, u_axis, v_axis)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        restored.get() == original.get()

    def test_closed_circle(self):
        center = Ge.Point3d(0.0, 0.0, 0.0)
        normal = Ge.Vector3d(0.0, 0.0, 1.0)
        ref_vec = Ge.Vector3d(1.0, 0.0, 0.0)
        radius = 5.0
        start_ang = 0.0
        end_ang = 2 * math.pi

        original = Ge.CircArc3d(center, normal, ref_vec, radius, start_ang, end_ang)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)

        assert restored.center() == original.center()
        assert restored.normal() == original.normal()
        assert restored.refVec() == original.refVec()
        assert math.isclose(restored.radius(), original.radius())
        assert math.isclose(restored.startAng(), original.startAng())
        assert math.isclose(restored.endAng(), original.endAng())

    def test_partial_arc(self):
        center = Ge.Point3d(10.0, -5.0, 2.5)
        normal = Ge.Vector3d(0.0, 1.0, 0.0)
        ref_vec = Ge.Vector3d(0.0, 0.0, 1.0)
        radius = 12.34
        start_ang = math.pi / 4.0  # 45 degrees
        end_ang = math.pi / 2.0  # 90 degrees

        original = Ge.CircArc3d(center, normal, ref_vec, radius, start_ang, end_ang)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)

        assert restored.center() == original.center()
        assert restored.normal() == original.normal()
        assert restored.refVec() == original.refVec()
        assert math.isclose(restored.radius(), original.radius())
        assert math.isclose(restored.startAng(), original.startAng())
        assert math.isclose(restored.endAng(), original.endAng())

    def test_LineSeg3d(self):
        start_point = Ge.Point3d(1.0, 2.0, 3.0)
        end_point = Ge.Point3d(11.0, 22.0, 33.0)
        original = Ge.LineSeg3d(start_point, end_point)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        assert restored.startPoint() == original.startPoint()
        assert restored.endPoint() == original.endPoint()

    def test_composite_curve_constructor(self):
        # 1. Create sub-curves
        p1 = Ge.Point3d(0.0, 0.0, 0.0)
        p2 = Ge.Point3d(10.0, 0.0, 0.0)
        line_seg = Ge.LineSeg3d(p1, p2)
        
        center = Ge.Point3d(10.0, 5.0, 0.0)
        normal = Ge.Vector3d(0.0, 0.0, 1.0)
        ref_vec = Ge.Vector3d(0.0, -1.0, 0.0)
        radius = 5.0
        arc = Ge.CircArc3d(center, normal, ref_vec, radius, 0.0, math.pi / 2.0)
        sub_curves = [line_seg, arc]
        
        # 2. Instantiate and pickle
        original = Ge.CompositeCurve3d(sub_curves)
        payload = pickle.dumps(original)
        restored = pickle.loads(payload)
        
        # 3. Extract the unpickled raw base curve list
        restored_curves = restored.getCurveList()
        assert len(restored_curves) == 2
        
        # Element 0: Verify it's a LineSeg3d under the hood
        assert restored_curves[0].type() == Ge.EntityId.kLineSeg3d
        restored_line = Ge.LineSeg3d.cast(restored_curves[0]) 
        
        # Element 1: Verify it's a CircArc3d under the hood
        assert restored_curves[1].type() == Ge.EntityId.kCircArc3d
        restored_arc = Ge.CircArc3d.cast(restored_curves[1])
        
        # 5. Perform the geometric assertions on the casted instances
        assert restored_line.startPoint() == line_seg.startPoint()
        assert restored_line.endPoint() == line_seg.endPoint()
        
        assert restored_arc.center() == arc.center()
        assert math.isclose(restored_arc.radius(), arc.radius())
