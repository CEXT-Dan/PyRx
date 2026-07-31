import wx
from wx import xrc

from pyrx import Ap, Db, Ed, Ge, Gs

print("added command wxblockman")

class PalettePanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        self.imageDict = {}
        
    def init_members(self):
        self.previewctrl = xrc.XRCCTRL(self, "ID_STATIC_PREVIEW")
        self.choicectrl = xrc.XRCCTRL(self, "ID_CHOICE")
        self.add_buttonctrl = xrc.XRCCTRL(self, "ID_ADD_BUTTON")
        self.rot_textctrl = xrc.XRCCTRL(self, "ID_ROTATION_TEXTCTRL")
        self.scale_txtctrl = xrc.XRCCTRL(self, "ID_SCALE_TEXTCTRL")
        self.dirctrl: wx.GenericDirCtrl = xrc.XRCCTRL(self, "ID_DIRCTRL")
        self.listctrl = xrc.XRCCTRL(self, "ID_LISTCTRL")
        
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
        dwgpath = self.dirctrl.GetPath()
        if dwgpath.lower().endswith('.dwg'):
            print(dwgpath)

    def OnSize(self, event):
        event.Skip()

    def OnDragInit(self, event: wx.ListEvent):
        _lock = Ap.AutoDocLock()
        item_index = event.GetIndex()
        item_text = self.listctrl.GetItemText(item_index)
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

    # TODO make attibutes
    def doit(self):
        self.setDispPrompt("\nPick Point: ")
        if self.drag() != Ed.DragStatus.kNormal:
            print("oops")
            return
        self.db.addToCurrentspace(self.ref)
        self.ref.close()


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
