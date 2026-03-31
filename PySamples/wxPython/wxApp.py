import wx

from pyrx import Ap

def app_details(app : wx.App):
    print(app.AppName)
    
    appearance = wx.SystemSettings.GetAppearance()
    
    print(appearance.IsDark()) #Application 
    print(appearance.IsSystemDark()) #System 
    print(appearance.IsUsingDarkBackground()) #Application
    
    #missing
    #app.MSWEnableDarkMode
    
@Ap.Command()
def doit1():
    try:
        app: wx.App = Ap.Application.wxApp()
        app_details(app)
    except Exception as err:
        print(err)

@Ap.Command()
def doit2():
    try:
        app: wx.App = wx.App.GetInstance()
        app_details(app)
    except Exception as err:
        print(err)

@Ap.Command()
def doit3():
    try:
        app: wx.App = wx.App.Get()
        app_details(app)
    except Exception as err:
        print(err)


@Ap.Command()
def doit4():
    try:
        app: wx.App = wx.GetApp()
        app_details(app)
    except Exception as err:
        print(err)
