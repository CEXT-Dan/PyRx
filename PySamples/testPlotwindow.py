import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyPl as Pl

#port of
#https://through-the-interface.typepad.com/through_the_interface/2007/10/plotting-a-wind.html

import traceback

def PyRxCmd_doit():
    try:
        db = Db.curDb()
        
        ppr = Ed.Editor.getPoint("\nSelect first corner of plot area: ")
        if ppr[0] != Ed.PromptStatus.eOk:
            return
        
        pcr = Ed.Editor.getCorner(ppr[1],"\nSelect second corner of plot area: ")
        if pcr[0] != Ed.PromptStatus.eOk:
            return
        
        rbfrom = [(5003, 1)]
        rbto= [(5003, 2)]
        
        p1 = Ed.Core.trans(ppr[1],rbfrom,rbto,0)
        p2 = Ed.Core.trans(pcr[1],rbfrom,rbto,0)
                
        ext = Db.Extents2d()
        ext.addPoint(Ge.Point2d(p1.x,p1.y))
        ext.addPoint(Ge.Point2d(p2.x,p2.y))
        
        btr = Db.BlockTableRecord(db.currentSpaceId())
        layout = Db.Layout(btr.getLayoutId())
        
        pi = Pl.PlotInfo()
        pi.setLayout(layout.objectId())
        
        ps = Pl.
        

    except Exception as err:
        print(traceback.format_exc())
