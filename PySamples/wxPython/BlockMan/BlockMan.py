import wx
from wx import xrc

from pyrx import Ap, Db, Ed, Ge, Gs

print("added command wxblockman")


# create a docment reactor to notify the palette of document switching
class DocReactor(Ap.DocManagerReactor):
    def __init__(self, PalettePanel):
        Ap.DocManagerReactor.__init__(self)
        self.panel = PalettePanel

    # froward the event
    def documentBecameCurrent(self, dwgdoc: Ap.Document):
        if not dwgdoc.isNullObj():
            self.panel.documentBecameCurrent(dwgdoc)


# the palette set holds a collection of panels, this is one
class PalettePanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.reactor = DocReactor(self)
        self.reactor.addReactor()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        self.imageDict = {}
        self.dwgdoc = None

    def documentBecameCurrent(self, dwgdoc):
        self.dwgdoc = dwgdoc
        self.validateimageDictForDoc(dwgdoc)
        self.listctrl.DeleteAllItems()
        d: dict = self.findImageDictForDoc(dwgdoc)
        for idx, key in enumerate(d.keys()):
            self.listctrl.InsertItem(idx, key)

    # import the .XRC file and init the controls
    def OnShow(self, event):
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

        # get ctrls as member variables
        self.listctrl = xrc.XRCCTRL(self, "wxID_LISTCTRL")
        self.imagectrl = xrc.XRCCTRL(self, "wxID_STATIC_PREVIEW")
        self.OnInitListCtrl()

        # bind events
        self.Bind(wx.EVT_SIZE, self.OnSize)
        self.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragInit, self.listctrl)
        self.Bind(wx.EVT_LIST_ITEM_SELECTED, self.OnItemSelected, self.listctrl)

        self.documentBecameCurrent(Ap.curDoc())
        self.set_dark_mode(self)

    # some colors I thought were cool
    def set_dark_mode(self, control):
        bkclr = wx.Colour(palette.paletteBackgroundColor())
        fgcolor = wx.Colour(palette.paletteTabTextColor())
        for child in control.GetChildren():
            child.SetForegroundColour(fgcolor)
            child.SetBackgroundColour(bkclr)
            self.set_dark_mode(child)

    def OnSize(self, event):
        event.Skip()

    def OnInitListCtrl(self):
        self.listctrl.InsertColumn(0, "Item", width=245)

    # create a new ref and pass it to the jig
    def OnDragInit(self, event: wx.ListEvent):
        _lock = Ap.AutoDocLock()
        item = event.GetText()
        db = self.dwgdoc.database()
        bt = Db.BlockTable(db.blockTableId())
        id = bt.getAt(item)
        pos = Ed.Core.getMousePositionUCS()
        ref = Db.BlockReference(pos, id)
        jig = Blockig(ref, pos, db)
        jig.doit()

    # search for an image in the cache, if none, make one
    def OnItemSelected(self, event: wx.ListEvent):
        _lock = Ap.AutoDocLock()
        item = event.GetText()
        imdict = self.findImageDictForDoc(self.dwgdoc)
        if imdict[item] is None:
            db = self.dwgdoc.database()
            bt = Db.BlockTable(db.blockTableId())
            id = bt.getAt(item)
            imdict[item] = Gs.Core.getBlockImage(id, 252, 140, 1.0, [49, 56, 66])
        img: wx.Image = imdict[item]
        self.imagectrl.SetBitmap(img.ConvertToBitmap())

    def findImageDictForDoc(self, dwgdoc):
        if dwgdoc not in self.imageDict:
            self.imageDict[dwgdoc] = {}
        return self.imageDict[dwgdoc]

    def validateimageDictForDoc(self, dwgdoc: Ap.Document):
        _lock = Ap.AutoDocLock()
        imdict = self.findImageDictForDoc(dwgdoc)
        db = dwgdoc.database()
        bt = Db.BlockTable(db.blockTableId())
        for name, id in bt.toDict().items():
            if name.startswith("*") or name.startswith("A$"):
                continue
            btr = Db.BlockTableRecord(id)
            if btr.isLayout() or btr.isAnonymous():
                continue
            if btr.isFromOverlayReference() or btr.isFromExternalReference():
                continue
            if name not in imdict:
                imdict[name] = None


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
