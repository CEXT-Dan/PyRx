import os

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

from Delaunator import Delaunator
from time import perf_counter

def OnPyInitApp():
    PyRxApp.Printf("\nOnPyInitApp")

def OnPyUnloadApp():
   PyRxApp.Printf("\nOnPyUnloadApp")

def OnPyLoadDwg():
   PyRxApp.Printf("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")


def do_select():
    filter = [(PyDb.DxfCode.kDxfStart, "POINT")]
    ed = PyAp.Application().docManager().curDocument().editor()
    ss = ed.select("\nSelect points: ", "\nRemove points: ", filter)
    if (ss[0] == PyEd.PromptStatus.eNormal):
        return ss[1]

def get_3dpointd(objs):
    pnts = []
    for id in objs:
        p = PyDb.Point(id, PyDb.OpenMode.kForRead)
        pnts.append(p.position())
    return pnts

def get_2dpointd(pnt3ds):
    pnts = []
    for p in pnt3ds:
        pnts.append([p.x, p.y])
    return pnts

def PyRxCmd_pydoit():
    try:
        ss = do_select()
        t1_start = perf_counter()
        pnt3ds = get_3dpointd(ss)
        pnt2ds = get_2dpointd(pnt3ds)
        t = Delaunator(pnt2ds).triangles
        
        db = PyAp.Application().docManager().curDocument().database()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        cnt = len(t)
        for i in range(0, cnt, 3):
            a = pnt3ds[t[i]]
            b = pnt3ds[t[i + 1]]
            c = pnt3ds[t[i + 2]]
            f = PyDb.Face(a, b, c)
            model.appendAcDbEntity(f)

        t1_stop = perf_counter()
        r = "Elapsed time: {t:.4f}".format(t=t1_stop-t1_start)
        print(r)
    except Exception as err:
        PyRxApp.Printf(err)
