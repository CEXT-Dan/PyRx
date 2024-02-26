from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

import AxApp24 as AcadApp

from Delaunator import Delaunator
from time import perf_counter
import traceback


print("command = pydelaunatorx")

app = AcadApp.getApp()

def get_3dpointds(objs):
    pnts = []
    for ent in objs:
        p = AcadApp.IAcadPoint(ent)
        pnts.append(p.Coordinates)
    return pnts

def get_2dpointd(pnt3ds):
    pnts = []
    for p in pnt3ds:
        pnts.append([p[0],p[1]])
    return pnts

def PyRxCmd_pydelaunatorx() -> None:
    try:
        
        doc = app.ActiveDocument
        ss = doc.SelectionSets.Add('mysset')
        ss.SelectOnScreen([0], ["POINT"])
        
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)
        pnt2ds = get_2dpointd(pnt3ds)
        
        #doit
        t = Delaunator(pnt2ds).triangles
        
        model = doc.ModelSpace
        
        for i in range(0, len(t), 3):
            a = pnt3ds[t[i]]
            b = pnt3ds[t[i + 1]]
            c = pnt3ds[t[i + 2]]
            
            model.Add3DFace(a,b,c,a)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop-t1_start))
    except Exception as err:
        traceback.print_exception(err)
    finally:
        ss.Delete()
        

