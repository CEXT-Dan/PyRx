import traceback
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import wx

#example of how to get an instance of wxApp
def PyRxCmd_doit():
    try:
        app : wx.App = Ap.Application.wxApp()
        print(app.AppName)
    except Exception as err:
        print(err)
        



