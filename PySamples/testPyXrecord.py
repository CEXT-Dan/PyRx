from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command = pyxrecord")

def PyRxCmd_pyxrecord():
    try: 
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)
        if not nod.has("AcadDim_CRX"):
            print("fail")
            return
        
        xid = nod.getAt("AcadDim_CRX")
        xrec = Db.Xrecord(xid, Db.OpenMode.kForRead)
        
        rbChain = xrec.rbChain()
        print(rbChain)
        
        rbChain[7] = (65, 0)# spline type
        xrec.upgradeOpen()
        xrec.setFromRbChain(rbChain)
        xrec.downgradeOpen()
        
        print(xrec.rbChain())
        
    except Exception as err:
         print(err)