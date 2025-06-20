import traceback

from pyrx import Ap, Db, Ge

print("added command = pycreate_mtext")


def PyRxCmd_pycreate_mtext():
    try:
        db = Ap.Application().docManager().curDocument().database()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        mtext = Db.MText()
        mtext.setDatabaseDefaults(db)
        mtext.setLocation(Ge.Point3d(100, 100, 0))
        mtext.setContents("This is a test")
        print(mtext.contents())
        print(mtext.textHeight())
        mtext.setRotation(1.5708)
        mtext.setAttachment(Db.MTextAttachmentPoint.kBottomCenter)
        model.appendAcDbEntity(mtext)
    except Exception as err:
        traceback.print_exception(err)
