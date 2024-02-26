import traceback
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
import wx

#example of how to get an instance of wxApp
def PyRxCmd_doit():
    try:
        app : wx.App = Ap.Application.wxApp()
        print(app.AppName)
    except Exception as err:
        print(err)
        



