import os

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def PyRxCmd_pycreate_mtext():
    try: 
        db = PyAp.Application().docManager().curDocument().database()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        mtext = PyDb.MText()
        mtext.setLocation(PyGe.Point3d(100,100,0))
        mtext.setContents("This is a test")
        print(mtext.contents())
        print(mtext.textHeight())
        mtext.setRotation(1.5708)
        #mtext.setAttachment(PyDb.MText.kBottomCenter)
        mtext.setAttachment(PyDb.MText.AttachmentPoint.kBottomCenter)
        model.appendAcDbEntity(mtext)
    except Exception as err:
        PyRxApp.Printf(err)