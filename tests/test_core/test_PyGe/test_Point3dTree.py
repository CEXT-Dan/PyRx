from __future__ import annotations

from pyrx import Ge


class TestPoint2dTree:

    def test_knnSearch(self):
        pnts = Ge.Point2dArray()
        pnts.append(Ge.Point2d(0, 0))
        pnts.append(Ge.Point2d(10, 0))
        pnts.append(Ge.Point2d(10, 10))
        pnts.append(Ge.Point2d(0, 10))
        tree = Ge.Point2dTree(pnts)
        idxs, dists = tree.knnSearch(Ge.Point2d(9, 0), 1)
        assert len(idxs) == 1
        assert len(dists) == 1
        assert idxs[0] == 1
        assert dists[0] == 1

    def test_radiusSearch(self):
        pnts = Ge.Point2dArray()
        pnts.append(Ge.Point2d(0, 0))
        pnts.append(Ge.Point2d(10, 0))
        pnts.append(Ge.Point2d(10, 10))
        pnts.append(Ge.Point2d(0, 10))
        tree = Ge.Point2dTree(pnts)
        idxs, dists = tree.radiusSearch(Ge.Point2d(9, 0), 2)
        assert len(idxs) == 1
        assert len(dists) == 1
        assert idxs[0] == 1
        assert dists[0] == 1


class TestPoint3dTree:

    def test_knnSearch(self):
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(10, 0, 0))
        pnts.append(Ge.Point3d(10, 10, 0))
        pnts.append(Ge.Point3d(0, 10, 0))
        tree = Ge.Point3dTree(pnts)
        idxs, dists = tree.knnSearch(Ge.Point3d(9, 0, 0), 1)
        assert len(idxs) == 1
        assert len(dists) == 1
        assert idxs[0] == 1
        assert dists[0] == 1

    def test_radiusSearch(self):
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(10, 0, 0))
        pnts.append(Ge.Point3d(10, 10, 0))
        pnts.append(Ge.Point3d(0, 10, 0))
        tree = Ge.Point3dTree(pnts)
        idxs, dists = tree.radiusSearch(Ge.Point3d(9, 0, 0), 2)
        assert len(idxs) == 1
        assert len(dists) == 1
        assert idxs[0] == 1
        assert dists[0] == 1
