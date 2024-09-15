import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx, Bim
import wx

_guid = "{ABE15A35-A99F-4C28-9E12-BEF2713D1451}"
_desc = "MyIfcImportReactor"


class IfcImportReactor(Bim.IfcImportReactor):
    def __init__(self,desc,guid):
       Bim.IfcImportReactor.__init__(self,desc,guid)
       
reactor = IfcImportReactor(_desc,_guid)

def PyRxCmd_doit1():
    try:
        reactor.onStart
    except Exception:
        traceback.print_exc()
        
def PyRxCmd_doit2():
    try:
        print(wx.version())
    except Exception:
        traceback.print_exc()