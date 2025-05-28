import traceback
from pyrx import Ap, Db, Ed, Ge, Gi, Gs, Rx
import wx


def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command 'wxpy'")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


# command to launch the dialog
def PyRxCmd_wxpy():
    try:
        # calls CAcModuleResourceOverride
        res = Ap.ResourceOverride()

        dlg = TestDialog(None, -1, "mY fRirst diaLog", wx.Size(700, 300))
        if dlg.ShowModal() == wx.ID_OK:
            print(dlg.text1.GetValue())
            print(dlg.text2.GetValue())

    except Exception as err:
        print(err)
    finally:
        # explicitly cause the dialog to destroy itself
        dlg.Destroy()


class TestDialog(wx.Dialog):
    def __init__(
        self,
        parent,
        id,
        title,
        size,
        pos=wx.DefaultPosition,
        style=wx.DEFAULT_DIALOG_STYLE,
        name="dialog",
    ):

        # Instead of calling wx.Dialog.__init__ we precreate the dialog
        # so we can set an extra style that must be set before
        # creation, and then we create the GUI object using the Create
        # method.
        wx.Dialog.__init__(self)
        self.SetExtraStyle(wx.DIALOG_EX_CONTEXTHELP)
        self.Create(parent, id, title, pos, size, style, name)

        # Now continue with the normal construction of the dialog
        # contents
        sizer = wx.BoxSizer(wx.VERTICAL)

        label = wx.StaticText(self, -1, "This is a wx.Dialog")
        sizer.Add(label, 0, wx.ALIGN_CENTRE | wx.ALL, 5)

        box = wx.BoxSizer(wx.HORIZONTAL)

        label = wx.StaticText(self, -1, "Field #1:")
        box.Add(label, 0, wx.ALIGN_CENTRE | wx.ALL, 5)

        self.text1 = wx.TextCtrl(self, -1, "", size=(200, -1))
        box.Add(self.text1, 1, wx.ALIGN_CENTRE | wx.ALL, 5)

        sizer.Add(box, 0, wx.EXPAND | wx.ALL, 5)

        box = wx.BoxSizer(wx.HORIZONTAL)

        label = wx.StaticText(self, -1, "Field #2:")
        box.Add(label, 0, wx.ALIGN_CENTRE | wx.ALL, 5)

        self.text2 = wx.TextCtrl(self, -1, "", size=(200, -1))
        box.Add(self.text2, 1, wx.ALIGN_CENTRE | wx.ALL, 5)

        sizer.Add(box, 0, wx.EXPAND | wx.ALL, 5)

        line = wx.StaticLine(self, -1, size=(20, -1), style=wx.LI_HORIZONTAL)
        sizer.Add(line, 0, wx.EXPAND | wx.RIGHT | wx.TOP, 5)

        btnsizer = wx.StdDialogButtonSizer()

        if wx.Platform != "__WXMSW__":
            btn = wx.ContextHelpButton(self)
            btnsizer.AddButton(btn)

        btn = wx.Button(self, wx.ID_OK)
        btn.SetDefault()
        btnsizer.AddButton(btn)

        btn = wx.Button(self, wx.ID_CANCEL)
        btnsizer.AddButton(btn)
        btnsizer.Realize()

        sizer.Add(btnsizer, 0, wx.ALL, 5)

        self.SetSizer(sizer)
        sizer.Fit(self)
