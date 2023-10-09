import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

import AxApp24 as AcadApp
import AxAppUtils24 as AcUtils

from Delaunator import Delaunator
from time import perf_counter
import traceback


print("command = pydelaunatorx")

app = AcUtils.getApp()

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

def PyRxCmd_pydelaunatorx():
    try:
        
        doc = app.ActiveDocument
        ss = doc.SelectionSets.Add('mysset')
        ss.SelectOnScreen(AcUtils.ssfilterType([0]),
                          AcUtils.ssfilterData(["POINT"]))
        
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)
        pnt2ds = get_2dpointd(pnt3ds)
        
        #doit
        t = Delaunator(pnt2ds).triangles
        
        model = doc.ModelSpace
        
        for i in range(0, len(t), 3):
            a = AcUtils.coords(pnt3ds[t[i]])
            b = AcUtils.coords(pnt3ds[t[i + 1]])
            c = AcUtils.coords(pnt3ds[t[i + 2]])
            
            model.Add3DFace(a,b,c,a)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop-t1_start))
    except Exception as err:
        traceback.print_exception(err)
    finally:
        ss.Delete()
        
def PyRxCmd_pydelaunatorx2():
    try:
        
        doc = app.ActiveDocument
        ss = doc.SelectionSets.Add('mysset')
        ss.SelectOnScreen(AcUtils.ssfilterType([0]),
                          AcUtils.ssfilterData(["POINT"]))
        
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
