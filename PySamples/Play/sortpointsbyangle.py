import traceback

import numpy as np

from pyrx import Db, Ed, Ge


def calcCentroid2d(pnts):
    polypnts = np.array(pnts, dtype=np.float64)
    polygon = np.roll(polypnts, -1, axis=0)
    signed_areas = 0.5 * np.cross(polypnts, polygon)
    centroids = (polypnts + polygon) / 3.0
    return np.average(centroids, axis=0, weights=signed_areas)
    
def PyRxCmd_doit():
    try:
        filter = [(Db.DxfCode.kDxfStart, "point")]
        ss = Ed.Editor.selectPrompt("\nSelect item", "\nRemove item",filter)
        if ss[0] != Ed.PromptStatus.eNormal:
            return
        
        pnts = []
        pntmap = { }
        for id in ss[1].objectIds():
            pt = Db.Point(id)
            p = pt.position()
            key = (p.x,p.y)
            pntmap[key] = p
            pnts.append(key)
            
        centroid = calcCentroid2d(pnts)

        def angle_to(point):
            pa = Ge.Point3d(point[0],point[1],0)
            pb = Ge.Point3d(centroid[0],centroid[1],0)
            res = (pa-pb).angleTo(Ge.Vector3d.kYAxis,Ge.Vector3d.kZAxis)
            return res
            
        sortedKeys = sorted(pnts, key=angle_to)
        
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        for idx, item in enumerate(sortedKeys):
            text = Db.Text(pntmap[item], '{}'.format(idx))
            model.appendAcDbEntity(text)

    except Exception as err:
        traceback.print_exception(err)
        

