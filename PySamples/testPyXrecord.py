import os

import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def PyRxCmd_pyxrecord():
    try: 
        db = PyDb.HostApplicationServices().workingDatabase()
        nod = PyDb.Dictionary(db.namedObjectsDictionaryId(), PyDb.OpenMode.kForRead)
        if not nod.has("AcadDim_CRX"):
            print("fail")
            return
        
        xid = nod.getAt("AcadDim_CRX")
        xrec = PyDb.Xrecord(xid, PyDb.OpenMode.kForRead)
        
        rbChain = xrec.rbChain()
        print(rbChain)
        
        rbChain[7] = (65, 0)# spline type
        xrec.upgradeOpen()
        xrec.setFromRbChain(rbChain)
        xrec.downgradeOpen()
        
        print(xrec.rbChain())
        
    except Exception as err:
         print(err)