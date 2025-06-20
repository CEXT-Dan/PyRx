from time import perf_counter

from Delaunator import Delaunator

from pyrx import Db, Ed

# PySamples\dwg\TestPoints.dwg
print("added command pydelaunator")


def do_select():
    filter = [(Db.DxfCode.kDxfStart, "POINT")]
    ss = Ed.Editor.selectPrompt("\nSelect points: ", "\nRemove points: ", filter)
    if ss[0] == Ed.PromptStatus.eNormal:
        return ss[1]


def get_3dpointds(objs):
    pnts = []
    for id in objs:
        p = Db.Point(id)
        pnts.append(p.position())
    return pnts


def get_2dpointd(pnt3ds):
    pnts = []
    for p in pnt3ds:
        pnts.append([p.x, p.y])
    return pnts


def PyRxCmd_pydelaunator():
    try:
        ss = do_select()
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss.toList())
        pnt2ds = get_2dpointd(pnt3ds)

        # doit
        t = Delaunator(pnt2ds).triangles

        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        for i in range(0, len(t), 3):
            f = Db.Face(pnt3ds[t[i]], pnt3ds[t[i + 1]], pnt3ds[t[i + 2]])

            model.appendAcDbEntity(f)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))
    except Exception as err:
        print(err)
