import traceback

from pyrx import Ap, Db, Ed, Ge


@Ap.Command()
def convexHull() -> None:  # change me
    try:
        db = Db.curDb()

        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # get all the positions
        pnts = Ge.Point3dArray()
        pnts.extend([Db.Point(id).position() for id in ss.objectIdArray()])
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

        polyPoints = Ge.Point3dArray()
        for idx in pnts3d.convexHullIndexes():
            polyPoints.append(pnts3d[idx])

        hull = Db.Polyline(polyPoints)
        hull.setElevation(polyPoints[0].z)
        db.addToCurrentspace(hull)

    except Exception as err:
        traceback.print_exception(err)
