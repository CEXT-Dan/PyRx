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


