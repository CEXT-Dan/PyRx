from __future__ import annotations

from pyrx import Ge


class TestPoint3d:
    def test_repr(self):
        val = Ge.Point3d(1.2, 2.3, 4.5)
        assert val.__repr__() == "PyGe.Point3d(1.20000000000000,2.30000000000000,4.50000000000000)"

    def test_point3d_len(self):
        pO = Ge.Point3d(0, 0, 0)
        assert len(pO) == 3

    def test_point3d_toVec(self):
        pO = Ge.Point3d(0, 0, 0)
        p1 = Ge.Point3d(0, 100, 0)
        v1 = p1 - pO
        assert v1.length() == 100
        assert v1.isParallelTo(Ge.Vector3d.kYAxis) == True

    def test_point3d_arg_ctor(self):
        point = Ge.Point3d(100, 100, 0)
        assert point == Ge.Point3d(100, 100, 0)
        point2 = Ge.Point3d([300, 400])
        assert point2 == Ge.Point3d(300, 400, 0)
        point3 = Ge.Point3d((400, 500))
        assert point3 == Ge.Point3d(400, 500, 0)
        point4 = Ge.Point3d([300, 400, 500])
        assert point4 == Ge.Point3d(300, 400, 500)
        point5 = Ge.Point3d((400, 500, 600))
        assert point5 == Ge.Point3d(400, 500, 600)
        point6 = Ge.Point3d([300, 400, 500, 900])
        assert point6 == Ge.Point3d(300, 400, 500)
        point7 = Ge.Point3d((400, 500, 600, 900))
        assert point7 == Ge.Point3d(400, 500, 600)

    def test_point3d_getset(self):
        pO = Ge.Point3d(1, 2, 3)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_point3dlist_getset(self):
        iterable = [1, 2, 3]
        pO = Ge.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_point3dtuple_getset(self):
        iterable = (1, 2, 3)
        pO = Ge.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_Point3dArray_sort(self):
        pnts = Ge.Point3dArray()
        for i in range(5, 0, -1):
            pnts.append(Ge.Point3d(i, i, i))
        assert pnts[0] != Ge.Point3d(1, 1, 1)
        pnts.sortByDistFrom(Ge.Point3d(0, 0, 0))
        assert pnts[0] == Ge.Point3d(1, 1, 1)
        
    def test_Point3dTree_knn(self):
        pnts = Ge.Point3dArray()
        for x in range(10):
            for y in range(10):
                for z in range(10):
                    pnts.append(Ge.Point3d(x, y, z))
                    
        tree = Ge.Point3dTree(pnts)
        idxs , _ = tree.knnSearch(Ge.Point3d(0.4, 0.4, 0.4),1) 
        assert pnts[0] == pnts[idxs[0]]
        
        idxs , _ = tree.knnSearch(Ge.Point3d(10.4, 10.4, 10.4),1) 
        assert pnts[999] == pnts[idxs[0]]
                   
    