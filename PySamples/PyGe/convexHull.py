import traceback
from pyrx import Ap, Ax, Db, Ed, Ge, Gi, Rx

@Ap.Command()
def convexHull() -> None: # change me
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
