import wx
from wx import xrc
from pyrx import Ap, Db, Ed, Ge, Gs
from typing import NamedTuple  # Fixed: Imported from typing for class syntax
import wx  # Assumed dependency based on wx.Image

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


class PalettePanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        self.imageDict = {}
        self.db = None

    def init_members(self):
        self.previewctrl = xrc.XRCCTRL(self, "ID_STATIC_PREVIEW")
        self.choicectrl = xrc.XRCCTRL(self, "ID_CHOICE")
        self.add_buttonctrl = xrc.XRCCTRL(self, "ID_ADD_BUTTON")
        self.rot_textctrl = xrc.XRCCTRL(self, "ID_ROTATION_TEXTCTRL")
        self.scale_txtctrl = xrc.XRCCTRL(self, "ID_SCALE_TEXTCTRL")
        self.dirctrl: wx.GenericDirCtrl = xrc.XRCCTRL(self, "ID_DIRCTRL")
        self.listctrl: wx.ListCtrl = xrc.XRCCTRL(self, "ID_LISTCTRL")

    def bind_events(self):
        self.Bind(wx.EVT_SIZE, self.OnSize)
        # ctrl events
        self.dirctrl.Bind(wx.EVT_DIRCTRL_SELECTIONCHANGED, self.OnDirCtrlSelectionChanged)
        self.listctrl.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragInit)

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

    def OnDragInit(self, event: wx.ListEvent):
        _lock = Ap.AutoDocLock()
        item_index = event.GetIndex()
        item_text = self.listctrl.GetItemText(item_index)
        
        # drag effect 
        drag = Ed.DropTarget()
        if drag.drag():
            print(f"Dragging item index: {item_index}, Text: {item_text}")

# jig
class Blockig(Ed.Jig):
    def __init__(self, blockRef, basepoint, db):
        Ed.Jig.__init__(self, blockRef)
        self.ref: Db.BlockReference = blockRef
        self.curPoint: Ge.Point3d = basepoint
        self.db: Db.Database = db

    def sampler(self):
        self.setUserInputControls
        (
            Ed.UserInputControls(
                Ed.UserInputControls.kAccept3dCoordinates
                | Ed.UserInputControls.kNullResponseAccepted
            )
        )
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]

    def update(self):
        self.ref.setPosition(self.curPoint)
        return True


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
