
import PyRx  # = Runtime runtime
import AcadApp24 as AcadApp
import AcadAppUtils24 as AcUtils

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
        t = Delaunator(pnt2ds).triangles
        
        model = doc.ModelSpace
        
        cnt = len(t)
        for i in range(0, cnt, 3):
            ca =  AcUtils.coords(pnt3ds[t[i]])   
            cb =  AcUtils.coords(pnt3ds[t[i + 1]])
            cc =  AcUtils.coords(pnt3ds[t[i + 2]]) 
                      
            model.Add3DFace(
                AcUtils.coords(ca),
                AcUtils.coords(cb),
                AcUtils.coords(cc),
                AcUtils.coords(ca))

        t1_stop = perf_counter()
        r = "Elapsed time: {t:.4f}".format(t=t1_stop-t1_start)
        print(r)
    except Exception as err:
        traceback.print_exception(err)
    finally:
        ss.Delete()
