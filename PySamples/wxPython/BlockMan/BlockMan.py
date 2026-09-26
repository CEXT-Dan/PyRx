from pathlib import Path
from typing import NamedTuple

import wx
from wx import xrc

from pyrx import Ap, Db, Ed, Ge, Gs
from enum import Flag, auto

print("added command wxblockman")


def OnPyUnloadApp():
    panel.ClearDatabase()


from enum import Flag, auto


class OnScreenFlags(Flag):
    NONE = 0
    ROTATE = auto()  # 1
    SCALE = auto()  # 2


def set_bit(flags: OnScreenFlags, bit: OnScreenFlags, value: bool) -> OnScreenFlags:
    if value:
        return flags | bit
    else:
        return flags & ~bit


def get_bit(flags: OnScreenFlags, bit: OnScreenFlags) -> bool:
    return bit in flags


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


def insertDwg(db: Db.Database, scale: float, rotation: float, flags):
    if not db:
        raise Db.ErrorStatusException(Db.ErrorStatus.eNoDatabase)
    srcBlockId = db.currentSpaceId()
    blockName = db.getFilename()
    point = Ge.Point3d()
    flag, point, scale, rotation = xform_block_jig(srcBlockId, point, scale, rotation, flags)
    if flag:
        if insertBlockViaActiveX(blockName, point, scale, rotation):
            return Db.ErrorStatus.eOk
        raise Db.ErrorStatusException(Db.ErrorStatus.eInvalidInput)
    return Db.ErrorStatus.eOk


def xform_block_jig(block_id, point, scale, rotation, flags):
    lock = Ap.AutoDocLock()
    jig = BlockJig(block_id, scale, rotation)
    if jig.doit() == Ed.PromptStatus.eOk:
        point = jig.getPoint()
    if flags & OnScreenFlags.SCALE:
        sjig = BlockJigScale(block_id, point, rotation)
        if sjig.doit() != Ed.PromptStatus.eOk:
            return False, point, scale, rotation
        scale = sjig.getScale()
    if flags & OnScreenFlags.ROTATE:
        rjig = BlockJigRotate(block_id, point, rotation, scale)
        if rjig.doit() != Ed.PromptStatus.eOk:
            return False, point, scale, rotation
        rotation = rjig.getRotation()
    return True, point, scale, rotation


def insertBlockTableRecord(sourceDb: Db.Database, blockName, scale, rotation, flags):
    lock = Ap.AutoDocLock()
    point = Ge.Point3d()
    # Check if the block is already inserted
    pDestDb = Db.workingDb()
    if not pDestDb:
        raise Db.ErrorStatusException(Db.ErrorStatus.eNoDatabase)

    pDestBlockTable = Db.BlockTable(pDestDb.blockTableId())
    bBlockExists = pDestBlockTable.has(blockName)

    if bBlockExists:
        srcBlockId = pDestBlockTable.getAt(blockName)
        pDestBlockTable.close()
        flag, point, scale, rotation = xform_block_jig(srcBlockId, point, scale, rotation, flags)
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
    flag, point, scale, rotation = xform_block_jig(srcBlockId, point, scale, rotation, flags)
    pTmpDb = None
    if flag:
        if not insertBlockViaActiveX(blockName, point, scale, rotation):
            raise RuntimeError("insertBlockViaActiveX Failed")
    return Db.ErrorStatus.eOk


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
        self.dwgimageDict = {}
        self.db = None

    def ClearDatabase(self):
        self.db = None

    def init_members(self):
        # init from xrc
        self.previewctrl = xrc.XRCCTRL(self, "ID_STATIC_PREVIEW")
        self.choicectrl: wx.Choice = xrc.XRCCTRL(self, "ID_CHOICE")
        self.add_buttonctrl: wx.Button = xrc.XRCCTRL(self, "ID_ADD_BUTTON")
        self.rot_textctrl = xrc.XRCCTRL(self, "ID_ROTATION_TEXTCTRL")
        self.scale_txtctrl = xrc.XRCCTRL(self, "ID_SCALE_TEXTCTRL")
        self.dirctrl: wx.GenericDirCtrl = xrc.XRCCTRL(self, "ID_DIRCTRL")
        self.listctrl: wx.ListCtrl = xrc.XRCCTRL(self, "ID_LISTCTRL")
        self.rosCheckBoxCtrl = xrc.XRCCTRL(self, "ID_CHECKBOX_ROS")
        self.sosCheckBoxCtrl = xrc.XRCCTRL(self, "ID_CHECKBOX_SOS")

        # theme
        bkl = wx.Colour(45, 45, 45)
        self.rot_textctrl.SetBackgroundColour(bkl)
        self.scale_txtctrl.SetBackgroundColour(bkl)

    def bind_events(self):
        self.Bind(wx.EVT_SIZE, self.OnSize)
        # ctrl events
        self.dirctrl.Bind(wx.EVT_DIRCTRL_SELECTIONCHANGED, self.OnDirCtrlSelectionChanged)
        if self.dirctrl:
            internal_tree = self.dirctrl.GetTreeCtrl()
            if internal_tree:
                internal_tree.Bind(wx.EVT_TREE_ITEM_RIGHT_CLICK, self.OnDirCtrlRightClick)
        self.listctrl.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragInit)
        self.listctrl.Bind(wx.EVT_LEFT_DCLICK, self.OnListCtrlLeftDClick)
        self.previewctrl.Bind(wx.EVT_LEFT_DCLICK, self.OnPreviewLeftDClick)
        self.add_buttonctrl.Bind(wx.EVT_BUTTON, self.OnAddButtonClick)
        self.choicectrl.Bind(wx.EVT_CHOICE, self.OnChoiceSelected)

    def OnShow(self, event):
        # import the .XRC file and init the controls
        __annotations__res = Ap.ResourceOverride()
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource("./BlockMan.xrc")
        self.childpanel = self.res.LoadPanel(self, "wxID_BLOCKMAN")
        if not self.childpanel:
            raise Exception("failed to find xrc file")

        # create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel, 1, wx.ALL | wx.EXPAND)
        self.SetSizerAndFit(sizer)
        self.Layout()
        self.init_members()
        self.bind_events()

    def OnAddButtonClick(self, event):
        __annotations__res = Ap.ResourceOverride()
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

    def getCachedDwgImage(self, dwgpath: str):
        """Get cached modelSpace image for the given DWG path, or generate and cache them."""
        if dwgpath in self.dwgimageDict:
            return self.dwgimageDict[dwgpath]
        self.dwgimageDict[dwgpath] = Gs.Core.getBlockImage(
            self.db.modelSpaceId(), 400, 225, 1.0, [25, 25, 25]
        )
        return self.dwgimageDict[dwgpath]

    def getCachedBlockInfos(self, dwgpath: str):
        """Get cached block infos for the given DWG path, or generate and cache them."""
        if dwgpath in self.imageDict:
            return self.imageDict[dwgpath]
        self.imageDict[dwgpath] = getBlockInfos(self.db)
        return self.imageDict[dwgpath]

    def OnDirCtrlSelectionChanged(self, event: wx.TreeEvent):
        __annotations__res = Ap.ResourceOverride()
        self.db = None
        self.listctrl.DeleteAllItems()
        self.listctrl.AssignImageList(None, wx.IMAGE_LIST_NORMAL)
        dwgpath = self.dirctrl.GetPath()
        if dwgpath.lower().endswith(".dwg"):
            self.db = Db.Database.createFromDWG(dwgpath)
            infos = self.getCachedBlockInfos(dwgpath)
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
            self.previewctrl.SetBitmap(self.getCachedDwgImage(dwgpath))
        event.Skip()

    def OnSize(self, event):
        __annotations__res = Ap.ResourceOverride()
        event.Skip()

    def OnListCtrlLeftDClick(self, event):
        __annotations__res = Ap.ResourceOverride()
        pos = event.GetPosition()
        item_index, flags = self.listctrl.HitTest(pos)
        if item_index != wx.NOT_FOUND:
            os_flags = OnScreenFlags.NONE
            os_flags = set_bit(os_flags, OnScreenFlags.ROTATE, self.isRosChecked())
            os_flags = set_bit(os_flags, OnScreenFlags.SCALE, self.isSosChecked())
            item_text = self.listctrl.GetItemText(item_index)
            sc = self.getScaleValue()
            rot = self.getRotValue()
            if insertBlockTableRecord(self.db, item_text, sc, rot, os_flags) == Db.ErrorStatus.eOk:
                print("\n")
            else:
                print("\nOops, Something went wrong")
        event.Skip()

    def OnDirCtrlRightClick(self, event):
        __annotations__res = Ap.ResourceOverride()
        path = self.dirctrl.GetPath()
        if path.lower().endswith(".dwg"):
            self.ClearDatabase()
            if Ap.DocManager().isApplicationContext():
                Ap.DocManager().appContextOpenDocument(path)
            else:
                print("\n[Error] Failed to acquire main Application Context.\n")
        else:
            response = wx.MessageBox(
                "Add this folder to favorites?",
                "Add Favorites",
                wx.YES_NO | wx.ICON_QUESTION,
                self,
            )
            if response == wx.YES:
                existing_index = self.choicectrl.FindString(path)
                if existing_index == wx.NOT_FOUND:
                    new_index = self.choicectrl.Append(path)
                    self.choicectrl.SetSelection(new_index)
                else:
                    self.choicectrl.SetSelection(existing_index)
        self.NavigateToFolder(path)
        # self.SaveChoiceSetting()

    def getScaleValue(self):
        strval = self.scale_txtctrl.GetValue()
        val = float(strval)
        return 1.0 if val == 0.0 else val

    def getRotValue(self):
        strval = self.rot_textctrl.GetValue()
        return float(strval)

    def OnDragInit(self, event: wx.ListEvent):
        __annotations__res = Ap.ResourceOverride()
        _lock = Ap.AutoDocLock()
        item_index = event.GetIndex()
        item_text = self.listctrl.GetItemText(item_index)

        os_flags = OnScreenFlags.NONE
        os_flags = set_bit(os_flags, OnScreenFlags.ROTATE, self.isRosChecked())
        os_flags = set_bit(os_flags, OnScreenFlags.SCALE, self.isSosChecked())

        drag = Ed.DragEffect()
        if drag.drag() and self.db is not None:
            insertBlockTableRecord(
                self.db, item_text, self.getScaleValue(), self.getRotValue(), os_flags
            )

    def OnPreviewLeftDClick(self, event: wx.MouseEvent):
        __annotations__res = Ap.ResourceOverride()
        _lock = Ap.AutoDocLock()
        os_flags = OnScreenFlags.NONE
        os_flags = set_bit(os_flags, OnScreenFlags.ROTATE, self.isRosChecked())
        os_flags = set_bit(os_flags, OnScreenFlags.SCALE, self.isSosChecked())
        insertDwg(self.db, self.getScaleValue(), self.getRotValue(), os_flags)
        event.Skip()

    def isRosChecked(self):
        return self.rosCheckBoxCtrl.IsChecked()

    def isSosChecked(self):
        return self.sosCheckBoxCtrl.IsChecked()


class BlockJig(Ed.Jig):
    def __init__(self, blockTableRecordId: Db.ObjectId, scale: float, rotation: float):
        self.ref = Db.BlockReference(Ge.Point3d.kOrigin, blockTableRecordId)
        self.ref.setDatabaseDefaults()
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

    def doit(self):
        self.setDispPrompt("\nInsertion Point: ")
        stat = self.drag()
        if stat == Ed.DragStatus.kNormal:
            return Ed.PromptStatus.kNormal
        return Ed.PromptStatus.eFailed


class BlockJigScale(Ed.Jig):
    def __init__(self, blockTableRecordId: Db.ObjectId, pos: Ge.Point3d, scale: float):
        self.pos = pos
        self.curScale = scale
        self.ref = Db.BlockReference(pos, blockTableRecordId)
        self.ref.setDatabaseDefaults()
        Ed.Jig.__init__(self, self.ref)
        self.baseMat = self.ref.blockTransform() * Ed.Editor.getCurrentUCS()
        self.refDist = self.curScale
        if self.refDist < 1e-4:
            self.refDist = 1.0

    def sampler(self) -> Ed.DragStatus:
        self.setUserInputControls(Ed.UserInputControls.kNullResponseAccepted)
        status, self.curScale = self.acquireDist(self.pos)
        if status == Ed.DragStatus.kCancel:
            return status
        return Ed.DragStatus.kNormal

    def update(self) -> bool:
        if self.curScale < 1e-6:
            self.curScale = 1e-6
        totalScaleFactor = self.curScale / self.refDist
        scaleMat = Ge.Matrix3d.scaling(totalScaleFactor, self.pos)
        self.ref.setBlockTransform(scaleMat * self.baseMat)
        return True

    def doit(self):
        self.setDispPrompt("\nSpecify scale factor: ")
        stat = self.drag()
        if stat == Ed.DragStatus.kNormal:
            return Ed.PromptStatus.kNormal
        return Ed.PromptStatus.eFailed

    def getScale(self):
        return self.curScale


class BlockJigRotate(Ed.Jig):
    def __init__(
        self, blockTableRecordId: Db.ObjectId, pos: Ge.Point3d, rotation: float, scale: float
    ):
        self.pos = pos
        self.curAng = rotation
        self.prevAng = 0.0
        self.ref = Db.BlockReference(pos, blockTableRecordId)
        self.ref.setDatabaseDefaults()
        Ed.Jig.__init__(self, self.ref)
        matUcs = Ed.Editor.getCurrentUCS()
        self.normal = matUcs.zAxis()
        scaleMat = Ge.Matrix3d.scaling(scale, self.pos)
        rotMat = Ge.Matrix3d.rotation(rotation, self.normal, self.pos)
        self.ref.transformBy(rotMat * scaleMat)
        self.baseMat = self.ref.blockTransform() * matUcs

    def sampler(self) -> Ed.DragStatus:
        self.setUserInputControls(Ed.UserInputControls.kNullResponseAccepted)
        status, self.curAng = self.acquireAngle(self.pos)
        if status == Ed.DragStatus.kCancel:
            return status
        return Ed.DragStatus.kNormal

    def update(self) -> bool:
        dynamicRot = Ge.Matrix3d.rotation(self.curAng, self.normal, self.pos)
        self.ref.setBlockTransform(dynamicRot * self.baseMat)
        return True

    def doit(self):
        self.setDispPrompt("\nSpecify rotation angle: ")
        stat = self.drag()
        if stat == Ed.DragStatus.kNormal:
            return Ed.PromptStatus.kNormal
        return Ed.PromptStatus.eFailed

    def getRotation(self):
        return self.curAng


palette = Ap.PaletteSet("BlockPalette")
panel = PalettePanel()


def createPalette() -> None:
    try:
        palette.add("BlockPanel", panel)
        palette.setVisible(True)
    except Exception as err:
        print(err)


def PyRxCmd_wxblockman() -> None:
    try:
        createPalette()
    except Exception as err:
        print(err)
