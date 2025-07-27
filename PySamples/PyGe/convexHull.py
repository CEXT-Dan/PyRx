import traceback
from pyrx import Ap, Ax, Db, Ed, Ge, Gi, Rx


@Ap.Command()
def convexHull() -> None:  # change me
    try:
        db = Db.curDb()

        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # get all the positions
        pnts = Ge.Point2dArray()
        pnts.extend([Db.Point(id).position().to2d() for id in ss.objectIdArray()])
        pnts.convexHull()

        hull = Db.Polyline(pnts.convexHull())
        db.addToCurrentspace(hull)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def convexHull2() -> None:  # change me
    try:
        db = Db.curDb()

        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # get all the positions
        pnts3d = Ge.Point3dArray()
        pnts3d.extend([Db.Point(id).position() for id in ss.objectIdArray()])

        # only 2d has the hull, but we can use the indexs
        pnts2d = pnts3d.to2d()

        polyPoints = Ge.Point3dArray()
        for idx in pnts2d.convexHullIndexes():
            polyPoints.append(pnts3d[idx])

        hull = Db.Polyline(polyPoints)
        hull.setElevation(polyPoints[0].z)
        db.addToCurrentspace(hull)

    except Exception as err:
        traceback.print_exception(err)
