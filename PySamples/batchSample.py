import traceback

import wx

from pyrx import Ap, Db

print("added command pybatch")

def addLayer(sidedb: Db.Database, name: str):
    lt = Db.LayerTable(sidedb.layerTableId())
    if lt.has(name):
        return lt.getAt(name)
    clr = Db.Color()
    clr.setColorIndex(255)
    layer = Db.LayerTableRecord()
    layer.setName(name)
    layer.setColor(clr)
    lt.upgradeOpen()
    return lt.add(layer)


def moveModelSpaceEntsToLayer(sidedb: Db.Database, lid: Db.ObjectId):
    model = Db.BlockTableRecord(sidedb.modelSpaceId())
    for id in model.objectIds():
        ent = Db.Entity(id, Db.OpenMode.kForWrite)
        ent.setLayer(lid)


def moveBlockEntsToZeroLayer(sidedb: Db.Database):
    bt = Db.BlockTable(sidedb.blockTableId())
    for _name, id in bt.toDict().items():
        block = Db.BlockTableRecord(id)
        # skip a name if you want
        if block.isLayout():
            continue
        if block.isFromExternalReference():
            continue
        for id in block.objectIds():
            ent = Db.Entity(id, Db.OpenMode.kForWrite)
            ent.setColorIndex(256)  # by layer
            ent.setLayer("0")


def removeLayersExcept(sidedb: Db.Database, keep: list[str]):
    lt = Db.LayerTable(sidedb.layerTableId())
    for name, id in lt.asDict().items():
        if name in keep:
            continue
        layer = Db.LayerTableRecord(id, Db.OpenMode.kForWrite)
        try:
            layer.erase()
        except Exception:
            print("cannot delete {}".format(name))


# do some stuff
def worker(sidedb: Db.Database):
    lid = addLayer(sidedb, "800")
    moveModelSpaceEntsToLayer(sidedb, lid)
    moveBlockEntsToZeroLayer(sidedb)
    removeLayersExcept(sidedb, ["0", "800"])


# reads the .dwg can calls a worker function and provides a scope
def openSideDatabase(path, worker):
    sideDb = Db.Database(False, True)  # no doc
    sideDb.readDwgFile(path)
    sideDb.closeInput(True)
    worker(sideDb)
    #uncomment to save
    #sideDb.saveAs(path)


# get dwg paths from dir (top level only)
def getDwgFiles():
    dlg = wx.DirDialog(None, "Choose directory", "", wx.DD_DIR_MUST_EXIST)
    if dlg.ShowModal() != wx.ID_OK:
        print("You Cancelled The Dialog!")
        return []
    return Ap.Application.listFilesInPath(dlg.GetPath(), ".dwg")


@Ap.Command()
def pybatch() -> None:
    try:
        for _item in getDwgFiles():
            print("\nProccessing {}".format(_item))
            openSideDatabase(_item, worker)
        print("done")
    except Exception as err:
        traceback.print_exception(err)
