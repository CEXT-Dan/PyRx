from pathlib import Path
from typing import NamedTuple

import wx
from wx import xrc

from pyrx import Ap, Db, Ed, Ge, Gs

print("added command wxblockman")


class BlockInfo(NamedTuple):
    id: int
    name: str
    image: wx.Image


# helpers
def getBlockInfos(db: Db.Database):
    ids = []
    infos: list[BlockInfo] = []
    for name, id in db.blockTable():
        rec = Db.BlockTableRecord(id)
        if rec.isLayout() or rec.isAnonymous():
            continue
        if rec.isFromExternalReference() or rec.isFromOverlayReference():
            continue
        infos.append(BlockInfo(id, name, None))
        ids.append(id)
    for idx, image in enumerate(Gs.Core.getBlockImages(ids, 64, 64, 1.0, [25, 25, 25])):
        infos[idx] = infos[idx]._replace(image=image)
    return infos


def insertDwg(db: Db.Database, scale: float, rotation: float):
    if not db:
        raise Db.ErrorStatusException(Db.ErrorStatus.eNoDatabase)
    srcBlockId = db.currentSpaceId()
    blockName = db.getFilename()
    flag, point = moveEnt(srcBlockId, scale, rotation)
    if flag:
        if insertBlockViaActiveX(blockName, point, scale, rotation):
            return Db.ErrorStatus.eOk
        raise Db.ErrorStatusException(Db.ErrorStatus.eInvalidInput)
    return Db.ErrorStatus.eOk


def insertBlockTableRecord(
    sourceDb: Db.Database, blockName: str, scale: float, rotation: float
) -> Db.ErrorStatus:

    # Check if the block is already inserted
    pDestDb = Db.workingDb()
    if not pDestDb:
        raise Db.ErrorStatusException(Db.ErrorStatus.eNoDatabase)

    pDestBlockTable = Db.BlockTable(pDestDb.blockTableId())
    bBlockExists = pDestBlockTable.has(blockName)

    if bBlockExists:
        srcBlockId = pDestBlockTable.getAt(blockName)
        pDestBlockTable.close()
        flag, point = moveEnt(srcBlockId, scale, rotation)
        if flag:
            if insertBlockViaActiveX(blockName, point, scale, rotation):
                return Db.ErrorStatus.eOk
            raise RuntimeError("insertBlockViaActiveX Failed")
    else:
        pDestBlockTable.close()

    # Else clone it
    if not sourceDb:
        print("\nDrawing was closed: ")
        return Db.ErrorStatus.eNoDatabase

    pSrcBlockTable = Db.BlockTable(sourceDb.blockTableId())
    if not pSrcBlockTable.has(blockName):
        pSrcBlockTable.close()
        return Db.ErrorStatus.eInvalidInput

    srcBlockId = pSrcBlockTable.getAt(blockName)
    pSrcBlockTable.close()
    pTmpDb = sourceDb.wblock(srcBlockId)

    blkId = Db.ObjectId()
    pDestDb.insert(blkId, blockName, pTmpDb, True)
    flag, point = moveEnt(srcBlockId, scale, rotation)
    pTmpDb = None
    if flag:
        if not insertBlockViaActiveX(blockName, point, scale, rotation):
            raise RuntimeError("insertBlockViaActiveX Failed")
    return Db.ErrorStatus.eOk


def moveEnt(blockId: Db.ObjectId, scale: float, rotation: float) -> bool:
    jig = BlockJig(blockId, scale, rotation)
    if jig.drag() == Ed.DragStatus.eNormal:
        point = jig.getPoint()
        return True, point
    return False, point


# use Ax to do the actual insert as it handles attributes, dynamic
def insertBlockViaActiveX(blkname: str, point: Ge.Point3d, scale: float, rot: float) -> bool:
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    db = Db.workingDb()
    if db.tilemode():
        space = axDoc.modelSpace()
    else:
        space = axDoc.paperSpace()
    ref = space.insertBlock(point, blkname, Ge.Scale3d(scale), rot)
    return ref is not None


class PalettePanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        self.imageDict = {}
        self.db = None

    def init_members(self):
        self.previewctrl = xrc.XRCCTRL(self, "ID_STATIC_PREVIEW")
        self.choicectrl: wx.Choice = xrc.XRCCTRL(self, "ID_CHOICE")
        self.add_buttonctrl: wx.Button = xrc.XRCCTRL(self, "ID_ADD_BUTTON")
        self.rot_textctrl = xrc.XRCCTRL(self, "ID_ROTATION_TEXTCTRL")
        self.scale_txtctrl = xrc.XRCCTRL(self, "ID_SCALE_TEXTCTRL")
        self.dirctrl: wx.GenericDirCtrl = xrc.XRCCTRL(self, "ID_DIRCTRL")
        self.listctrl: wx.ListCtrl = xrc.XRCCTRL(self, "ID_LISTCTRL")

    # todo handle previewctrl,choicectrl and add_buttonctrl
    def bind_events(self):
        self.Bind(wx.EVT_SIZE, self.OnSize)
        # ctrl events
        self.dirctrl.Bind(wx.EVT_DIRCTRL_SELECTIONCHANGED, self.OnDirCtrlSelectionChanged)
        self.listctrl.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragInit)
        self.previewctrl.Bind(wx.EVT_LEFT_DCLICK, self.OnPreviewLeftDClick)
        self.add_buttonctrl.Bind(wx.EVT_BUTTON, self.OnAddButtonClick)
        self.choicectrl.Bind(wx.EVT_CHOICE, self.OnChoiceSelected)

    # import the .XRC file and init the controls
    def OnShow(self, event):
        __annotations__res = Ap.ResourceOverride()
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource("./BlockMan.xrc")
        self.childpanel = self.res.LoadPanel(self, "wxID_BLOCKMAN")
        if not self.childpanel:
            raise Exception("failed to find xrc file")

        # # create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel, 1, wx.ALL | wx.EXPAND)
        self.SetSizerAndFit(sizer)
        self.Layout()
        self.init_members()
        self.bind_events()

    def OnAddButtonClick(self, event):
        default_path = self.dirctrl.GetPath()
        style = wx.DD_DEFAULT_STYLE | wx.DD_DIR_MUST_EXIST
        with wx.DirDialog(
            self, "Choose a Folder", defaultPath=default_path, style=style
        ) as dirDlg:
            if dirDlg.ShowModal() == wx.ID_OK:
                result = dirDlg.GetPath()
                existingIndex = self.choicectrl.FindString(result)
                if existingIndex == wx.NOT_FOUND:
                    newIndex = self.choicectrl.Append(result)
                    self.choicectrl.SetSelection(newIndex)
                else:
                    self.choicectrl.SetSelection(existingIndex)
                self.NavigateToFolder(result)

    def OnChoiceSelected(self, event):
        selected_path = event.GetString()
        self.NavigateToFolder(selected_path)

    def NavigateToFolder(self, folder: str):
        if not Path(folder).is_dir():
            print("\nNavigateToFolder failed: Path does not exist -> {}".format(folder))
        self.dirctrl.CollapseTree()
        self.dirctrl.SelectPath(folder)
        self.dirctrl.ExpandPath(folder)

    # TODO: image genration is slow
    # create (db, mainimage, list[BlockInfo]) cache
    def OnDirCtrlSelectionChanged(self, event: wx.TreeEvent):
        self.db = None
        self.listctrl.DeleteAllItems()
        self.listctrl.AssignImageList(None, wx.IMAGE_LIST_NORMAL)
        dwgpath = self.dirctrl.GetPath()
        if dwgpath.lower().endswith(".dwg"):
            self.db = Db.Database.createFromDWG(dwgpath)
            infos = getBlockInfos(self.db)
            imagelist = wx.ImageList(64, 64, False, len(infos))
            imgIdx = 0
            for itemIndex, info in enumerate(infos):
                has_image = False
                if info.image and info.image.IsOk():
                    imagelist.Add(wx.Bitmap(info.image))
                    has_image = True
                current_img_idx = imgIdx if has_image else -1
                self.listctrl.InsertItem(itemIndex, info.name, current_img_idx)
                if has_image:
                    imgIdx += 1
            self.listctrl.AssignImageList(imagelist, wx.IMAGE_LIST_NORMAL)
            dwgimg = Gs.Core.getBlockImage(self.db.modelSpaceId(), 400, 225, 1.0, [25, 25, 25])
            self.previewctrl.SetBitmap(wx.Bitmap(dwgimg))
        event.Skip()

    def OnSize(self, event):
        event.Skip()

    def getScaleValue(self):
        strval = self.scale_txtctrl.GetValue()
        val = float(strval)
        return 1.0 if val == 0.0 else val

    def getRotValue(self):
        strval = self.rot_textctrl.GetValue()
        return float(strval)

    def OnDragInit(self, event: wx.ListEvent):
        try:
            _lock = Ap.AutoDocLock()
            item_index = event.GetIndex()
            item_text = self.listctrl.GetItemText(item_index)
            drag = Ed.DragEffect()
            if drag.drag() and self.db is not None:
                insertBlockTableRecord(
                    self.db, item_text, self.getScaleValue(), self.getRotValue()
                )
        except Exception as e:
            print(f"OnDragInit failed: {e}")

    def OnPreviewLeftDClick(self, event: wx.MouseEvent):
        try:
            insertDwg(self.db, self.getScaleValue(), self.getRotValue())
        except Exception as e:
            print(f"OnPreviewLeftDClick failed: {e}")
        finally:
            event.Skip()


class BlockJig(Ed.Jig):
    def __init__(self, blockTableRecordId: Db.ObjectId, scale: float, rotation: float):
        self.ref = Db.BlockReference(Ge.Point3d.kOrigin, blockTableRecordId)
        Ed.Jig.__init__(self, self.ref)
        ucs = Ed.Editor.getCurrentUCS()
        rotMat = Ge.Matrix3d.rotation(rotation, ucs.zAxis(), Ge.Point3d.kOrigin)
        scaleMat = Ge.Matrix3d.scaling(scale, Ge.Point3d.kOrigin)
        self.localTransform = rotMat * scaleMat
        self.ref.transformBy(self.localTransform)
        self.point = Ge.Point3d.kOrigin

    def sampler(self) -> Ed.DragStatus:
        self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
        status, self.point = self.acquirePoint()
        return status

    def update(self) -> bool:
        self.ref.setPosition(self.point)
        return True

    def getPoint(self):
        return self.point


palette = Ap.PaletteSet("BlockPalette")


def createPalette() -> None:
    try:
        panel = PalettePanel()
        palette.add("BlockPanel", panel)
        palette.setVisible(True)
    except Exception as err:
        print(err)


def PyRxCmd_wxblockman() -> None:
    try:
        createPalette()
    except Exception as err:
        print(err)
