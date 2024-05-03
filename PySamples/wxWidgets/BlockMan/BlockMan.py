import traceback
from pyrx_imp import Rx, Ge, Db, Ap, Ed, Gi, Gs

import wx
from wx import xrc

print("added command wxblockman")


class DocReactor(Ap.DocManagerReactor):
    def __init__(self, PalettePanel):
        Ap.DocManagerReactor.__init__(self)
        self.panel = PalettePanel

    # froward the event
    def documentBecameCurrent(self, dwgdoc: Ap.Document):
        if not dwgdoc.isNullObj():
            self.panel.documentBecameCurrent(dwgdoc)

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
        self.validateDictForDoc(dwgdoc)
        self.listctrl.DeleteAllItems()
        d: dict = self.findImageDictForDoc(dwgdoc)
        for idx, key in enumerate(d.keys()):
            self.listctrl.InsertItem(idx, key)

    def OnShow(self, event):
        res = Ap.ResourceOverride()
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource("./BlockMan.xrc")
        self.childpanel = self.res.LoadPanel(self, "ID_BLOCKMAN")
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

    def OnDragInit(self, event):
        print("drag")

    def OnItemSelected(self, event: wx.ListEvent):
        item = event.GetText()
        imdict = self.findImageDictForDoc(self.dwgdoc)
        if imdict[item] == None:
            db = self.dwgdoc.database()
            bt = Db.BlockTable(db.blockTableId())
            id = bt.getAt(item)
            imdict[item] = Gs.Core.getBlockImage(id, 256, 144, 1.0, [49, 56, 66])
        img: wx.Image = imdict[item]
        self.imagectrl.SetBitmap(img.ConvertToBitmap())

    def findImageDictForDoc(self, dwgdoc):
        if not dwgdoc in self.imageDict:
            self.imageDict[dwgdoc] = {}
        return self.imageDict[dwgdoc]

    def validateDictForDoc(self, dwgdoc: Ap.Document):
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
            if not name in imdict:
                imdict[name] = None

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
