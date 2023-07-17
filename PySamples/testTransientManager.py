import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback

vpids = []
markers = []

def clear():
    tm = Gi.TransientManager.current()
    for marker in markers:
        tm.eraseTransient(marker,vpids)
    vpids.clear()
    markers.clear()
        
def PyRxCmd_pydoit(CmdFlags=Ap.CmdFlags.TRANSPARENT):
    try:
        clear()
        
        vpids.append(Ed.Core.getVar("CVPORT"))
        
        dbl = Db.Line(Ge.Point3d(0,0,0),Ge.Point3d(100,100,0))
        dbl.setDatabaseDefaults()
        dbl.setColorIndex(1)
        markers.append(dbl)

        tm = Gi.TransientManager.current()
        tm.addTransient(dbl,Gi.AcGiTransientDrawingMode.kAcGiDirectShortTerm,128,vpids)
        Ed.Core.vportTableRecords2Vports()

    except Exception as err:
        traceback.print_exception(err)
        