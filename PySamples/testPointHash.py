import traceback

from pyrx import Ge


def PyRxCmd_testhash():
    try:
        pnts = []
        pnts.append(Ge.Point3d(-2000.11111111111111, 2000.11111111111111, 2000.11111111111111))
        pnts.append(Ge.Point3d(-2000.11111111112222, 2000.11111111112222, 2000.11111111112222))
        pnts.append(Ge.Point3d(-2000.11111111113333, 2000.11111111113333, 2000.11111111113333))
        pnts.append(Ge.Point3d(-2000.11111111114444, 2000.11111111114444, 2000.11111111114444))
        pnts.append(Ge.Point3d(-2000.11111111115555, 2000.11111111115555, 2000.11111111115555))
        pnts.append(Ge.Point3d(-2000.11111111116666, 2000.11111111116666, 2000.11111111116666))
        pnts.append(Ge.Point3d(-2000.11111111117777, 2000.11111111117777, 2000.11111111117777))
        pnts.append(Ge.Point3d(-2000.11111111118888, 2000.11111111118888, 2000.11111111118888))
        pnts.append(Ge.Point3d(-2000.11111111119999, 2000.11111111119999, 2000.11111111119999))

        pntSet = set()
        for p in pnts:
            pntSet.add(p)

        print(pntSet)

        basePoint = pnts[0]

        for idx, pnt in enumerate(pnts):
            if idx == 0:
                continue
            print(idx, basePoint == pnt)

        for idx, pnt in enumerate(pnts):
            if idx == 0:
                continue
            print(idx, basePoint.__hash__() == pnt.__hash__())

        print("New Base")
        basePoint2 = pnts[4]

        for idx, pnt in enumerate(pnts):
            if idx == 4:
                continue
            print(idx, basePoint2 == pnt)

        for idx, pnt in enumerate(pnts):
            if idx == 4:
                continue
            print(idx, basePoint2.__hash__() == pnt.__hash__())

    except Exception:
        print(traceback.format_exc())
