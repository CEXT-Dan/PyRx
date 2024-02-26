import os

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command = pycreate_mtext")

def PyRxCmd_pycreate_mtext():
    try: 
        db = Ap.Application().docManager().curDocument().database()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        mtext = Db.MText()
        mtext.setDatabaseDefaults(db)
        mtext.setLocation(Ge.Point3d(100,100,0))
        mtext.setContents("This is a test")
        print(mtext.contents())
        print(mtext.textHeight())
        mtext.setRotation(1.5708)
        mtext.setAttachment(Db.MTextAttachmentPoint.kBottomCenter)
        model.appendAcDbEntity(mtext)
    except Exception as err:
        print(err)