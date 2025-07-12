import random
import traceback

from pyrx import Ap, Db, Ge


@Ap.Command()
def doit():
    try:
        db = Db.curDb()
    
        segs = [
            Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0)),
            Ge.LineSeg3d(Ge.Point3d(10, 0, 0), Ge.Point3d(20, 0, 0)),
            Ge.LineSeg3d(Ge.Point3d(20, 0, 0), Ge.Point3d(30, 0, 0)),
            Ge.LineSeg3d(Ge.Point3d(30, 0, 0), Ge.Point3d(40, 0, 0)),
            Ge.LineSeg3d(Ge.Point3d(40, 0, 0), Ge.Point3d(50, 0, 0)),
        ]

        for i , seg in enumerate(segs):
            print(segs[i].startPoint(), segs[i].endPoint())

        results = Ge.CompositeCurve3d.createFromLineSeg3dArray(segs)

        for item in results:
            dbo = Db.Core.convertGelibCurveToAcDbCurve(item)
            db.addToModelspace(dbo)

        # shuffle
        print("shuffled")
        shuffled_list = random.sample(segs, len(segs))
        for seg in shuffled_list:
            print(seg.startPoint(), seg.endPoint())

        results_shuffled = Ge.CompositeCurve3d.createFromLineSeg3dArray(shuffled_list)

        for item in results_shuffled:
            dbo = Db.Core.convertGelibCurveToAcDbCurve(item)
            db.addToModelspace(dbo)

    except Exception as err:
        traceback.print_exception(err)
