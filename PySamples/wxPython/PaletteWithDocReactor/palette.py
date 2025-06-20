import wx
from wx import xrc

from pyrx import Ap, Db

print("added command - wxpalette")


class MyPopupMenu(wx.Menu):
    def __init__(self):
        wx.Menu.__init__(self)
        item = wx.MenuItem(self, wx.NewId(), "Item One")
        self.Append(item)
        self.Bind(wx.EVT_MENU, self.OnItem1, item)
        item = wx.MenuItem(self, wx.NewId(), "Item Two")
        self.Append(item)
        self.Bind(wx.EVT_MENU, self.OnItem2, item)
        item = wx.MenuItem(self, wx.NewId(), "Item Three")
        self.Append(item)
        self.Bind(wx.EVT_MENU, self.OnItem3, item)

    def OnItem1(self, event):
        print("OnItem1")

    def OnItem2(self, event):
        print("OnItem2")

    def OnItem3(self, event):
        print("OnItem3")


# creates reactor class that holds a reference to PalettePanel
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

    # do documentBecameCurrent
    def documentBecameCurrent(self, dwgdoc):
        self.comboctrl.Clear()
        for doc in Ap.DocManager().documents():
            self.comboctrl.Append(doc.docTitle())
        self.comboctrl.SetStringSelection(dwgdoc.docTitle())

        self.listctrl.DeleteAllItems()
        blkdict = self.createBlockDict(dwgdoc)
        for i, (key, value) in enumerate(blkdict.items()):
            self.listctrl.InsertItem(i, key)
            self.listctrl.SetItem(i, 1, str(value))

    def OnShow(self, event):
        # import the XRC
        _res = Ap.ResourceOverride()
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource("./wxPaletteTab.xrc")
        self.childpanel = self.res.LoadPanel(self, "ID_WXPALETTETAB")
        if not self.childpanel:
            raise Exception("failed to find xrc file")

        # create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel, 1, wx.ALL | wx.EXPAND)
        self.SetSizerAndFit(sizer)
        self.Layout()

        # get ctrls as member variables
        self.comboctrl = xrc.XRCCTRL(self, "wxID_COMBOCTRL")
        self.listctrl = xrc.XRCCTRL(self, "wxID_LISTCTRL")

        self.index = 0
        self.OnInitListCtrl()

        # bind events
        self.Bind(wx.EVT_SIZE, self.OnSize)
        self.Bind(wx.EVT_CHOICE, self.OnChoice, self.comboctrl)
        self.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragInit, self.listctrl)
        self.Bind(wx.EVT_CONTEXT_MENU, self.OnContextMenu, self.listctrl)
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
        self.listctrl.InsertColumn(0, "Item", width=125)
        self.listctrl.InsertColumn(1, "Qty", width=125)

    def OnChoice(self, event):
        selection = self.comboctrl.GetSelection()
        selectionString = self.comboctrl.GetString(selection)
        print(selection, selectionString)

    def OnDragInit(self, event):
        text = self.listctrl.GetItemText(event.GetIndex())
        tobj = wx.TextDataObject(text)
        src = wx.DropSource(self.listctrl)
        src.SetData(tobj)
        print(src.DoDragDrop(True))

    def OnContextMenu(self, event):
        self.PopupMenu(MyPopupMenu(), self.ScreenToClient(event.GetPosition()))

    def OnItemSelected(self, event):
        print("OnItemSelected")

    def createBlockDict(self, doc: Ap.Document) -> dict:
        blkdict = {}
        db = doc.database()
        modelSpace = Db.BlockTableRecord(db.modelSpaceId())
        ids = modelSpace.objectIds(Db.BlockReference.desc())
        for id in ids:
            ref = Db.BlockReference(id)
            blk = Db.BlockTableRecord(ref.blockTableRecord())
            name = blk.getName()
            if name.startswith("*") or name.startswith("A$"):
                continue
            if name not in blkdict:
                blkdict[name] = 1
            else:
                blkdict[name] += 1
        return dict(sorted(blkdict.items()))


palette = Ap.PaletteSet("MyPalette")


def createPalette():
    try:
        panel = PalettePanel()
        palette.add("PalettePanel", panel)
        palette.setVisible(True)
    except Exception as err:
        print(err)


def PyRxCmd_wxpalette():
    try:
        createPalette()
    except Exception as err:
        print(err)
