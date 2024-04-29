from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
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
        tm.addTransient(dbl,Gi.TransientDrawingMode.kAcGiDirectShortTerm,128,vpids)
        Ed.Core.vportTableRecords2Vports()

    except Exception as err:
        traceback.print_exception(err)
        