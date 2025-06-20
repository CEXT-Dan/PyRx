import traceback
from timeit import default_timer as timer

import wx

from pyrx import Ap, Db, Gs

host = Ap.Application.hostAPI()

# id image width, image height, scale factor, (optional)BKColor
# img: wx.Image = Gs.Core.getBlockImage(id, 64, 64, 1.0, [255, 255, 255])


def doSideDb(db: Db.Database):
    start = timer()
    bt = Db.BlockTable(db.blockTableId())
    cnt = 0
    for name, id in bt.toDict().items():
        btr = Db.BlockTableRecord(id)
        if btr.isLayout():
            continue
        if btr.isAnonymous():
            continue
        if name.startswith("A$"):
            continue

        img: wx.Image = Gs.Core.getBlockImage(id, 128, 128, 1.0)
        img.SaveFile("E:/temp/{}_{}_128.png".format(name, host), wx.BITMAP_TYPE_PNG)
        cnt += 1

    end = timer()
    print(cnt, end - start)


# side database
def PyRxCmd_doitsd():
    try:
        db = Db.Database(False, True)
        db.readDwgFile("M:/Dev/Projects/PyRxGit/PySamples/dwg/Floor Plan Sample.dwg ")
        db.closeInput(True)
        doSideDb(db)
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit64():
    try:
        start = timer()

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        cnt = 0
        for name, id in bt.toDict().items():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            if btr.isAnonymous():
                continue
            if name.startswith("A$"):
                continue
            img: wx.Image = Gs.Core.getBlockImage(id, 64, 64, 1.0)
            img.SaveFile("E:/temp/{}_{}_64.png".format(name, host), wx.BITMAP_TYPE_PNG)
            cnt += 1

        end = timer()
        print(cnt, end - start)

    except Exception as err:
        traceback.print_exception(err)


# SR176790 - AcGsView::getSnapShot differences
def PyRxCmd_doit64W():
    try:
        start = timer()

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        cnt = 0
        for name, id in bt.toDict().items():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            if btr.isAnonymous():
                continue
            if name.startswith("A$"):
                continue
            img: wx.Image = Gs.Core.getBlockImage(id, 64, 64, 1.0, [255, 255, 255])
            img.SaveFile("E:/temp/{}_{}_64.png".format(name, host), wx.BITMAP_TYPE_PNG)
            cnt += 1

        end = timer()
        print(cnt, end - start)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit64TR():
    try:
        start = timer()

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        cnt = 0
        for name, id in bt.toDict().items():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            if btr.isAnonymous():
                continue
            if name.startswith("A$"):
                continue
            img: wx.Image = Gs.Core.getBlockImage(id, 64, 64, 1.0, [0, 0, 0])
            img.SetMaskColour(0, 0, 0)
            img.SetMask(True)
            img.SaveFile("E:/temp/{}_{}_64.png".format(name, host), wx.BITMAP_TYPE_PNG)
            cnt += 1

        end = timer()
        print(cnt, end - start)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit128():
    try:
        start = timer()

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        cnt = 0
        for name, id in bt.toDict().items():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            if btr.isAnonymous():
                continue
            if name.startswith("A$"):
                continue
            img: wx.Image = Gs.Core.getBlockImage(id, 128, 128, 1.0)
            img.SaveFile("E:/temp/{}_{}_128.png".format(name, host), wx.BITMAP_TYPE_PNG)
            cnt += 1

        end = timer()
        print(cnt, end - start)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doit256():
    try:
        start = timer()

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())
        cnt = 0
        for name, id in bt.toDict().items():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            if btr.isAnonymous():
                continue
            if name.startswith("A$"):
                continue
            img: wx.Image = Gs.Core.getBlockImage(id, 256, 256, 1.2)
            img.SaveFile("E:/temp/{}_{}_256.png".format(name, host), wx.BITMAP_TYPE_PNG)
            cnt += 1

        end = timer()
        print(cnt, end - start)

    except Exception as err:
        traceback.print_exception(err)
