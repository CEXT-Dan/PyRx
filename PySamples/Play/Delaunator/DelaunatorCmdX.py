import traceback
from time import perf_counter

from Delaunator import Delaunator

from pyrx import Ap, Ax

print("command = pydelaunatorx")

xapp = Ax.AcadApplication()

def get_3dpointds(objs):
    pnts = []
    for ent in objs:
        p = Ax.AcadPoint.cast(ent)
        pnts.append(p.coordinates())
    return pnts

def get_2dpointd(pnt3ds):
    pnts = []
    for p in pnt3ds:
        pnts.append([p[0],p[1]])
    return pnts

def PyRxCmd_pydelaunatorx() -> None:
    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axSets = axDoc.selectionSets()
        axSet = axSets.add("mysset")
        axSet.selectOnScreen([(0, "POINT")])
        
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(axSet)
        pnt2ds = get_2dpointd(pnt3ds)
        
        #doit
        t = Delaunator(pnt2ds).triangles
        
        model = axDoc.modelSpace()
        
        for i in range(0, len(t), 3):
            a = pnt3ds[t[i]]
            b = pnt3ds[t[i + 1]]
            c = pnt3ds[t[i + 2]]
            
            model.add3DFace(a,b,c,a)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop-t1_start))
    except Exception as err:
        traceback.print_exception(err)
    finally:
        axSet.delete()
        

