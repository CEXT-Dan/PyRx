import os
import traceback

import wx

from pyrx import Ap, Db, Gs


# extract the image and save it
def extractThumbnailsFromDb(db: Db.Database, path: str, targetpath: str):
    path_without_extension, _ = os.path.splitext(path)
    dwgname = os.path.basename(path_without_extension)
    bt = Db.BlockTable(db.blockTableId())
    for name, id in bt.asDict().items():
        blk = Db.BlockTableRecord(id)
        if (
            blk.isLayout()
            or blk.isAnonymous()
            or blk.isFromExternalReference()
            or blk.isFromOverlayReference()
        ):
            continue
        img: wx.Image = Gs.Core.getBlockImage(id, 128, 128, 1.0, [0, 0, 0])
        img.SaveFile("{}/{}_{}_128.png".format(targetpath, dwgname, name), wx.BITMAP_TYPE_PNG)


# read the database in its own function so the database object
# gets disposed after the blocks (gc is fifo)
def extractThumbnails(path: str, targetpath: str):
    db = Db.Database(False, True)
    db.readDwgFile(path)
    db.closeInput(True)
    extractThumbnailsFromDb(db, path, targetpath)


# register a new command
# ensure the targetpath exists
@Ap.Command()
def doit():
    try:
        targetpath = "E:/temp/icons"
        os.makedirs(targetpath, exist_ok=True)
        for path in Ap.Application.listFilesInPath("E:\\temp", ".dwg"):
            extractThumbnails(path, targetpath)

    except Exception as err:
        traceback.print_exception(err)
