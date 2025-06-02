# WxPython

PyRx imbeds wxWidgets and wxPython to allow programmers to create rich GUI interfaces. Some things to take note of when using wxPython in PyRx

## AutoCAD is the wxTheApp

Many wxPython samples will show creating an “app” by calling wx.App(), this is incorrect because AutoCAD is the app and already has a main loop running, you will want to avoid calling code like this

```PY
    # Don't do this
    if __name__ == "__main__":
        app = App()
        app.MainLoop()
```

This will create a new application instance and possibly crash AutoCAD, if you need to get an instance of the "app", please use one of the following

```PY
    Ap.Application.wxApp() #preferred 
    wx.App.Get()
    wx.GetApp()
    wx.App.GetInstance()
```
