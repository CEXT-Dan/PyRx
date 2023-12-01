import wx
import sys
import debugpy


def startListener():
    oldpath = sys.executable
    try:
        result = wx.MessageDialog(
            None,
            'Now is a good time to run your debugger:',
            'Confirm',
            wx.YES_NO | wx.NO_DEFAULT | wx.ICON_QUESTION
            ).ShowModal()

        if result != wx.ID_YES:
            return
        sys.executable = sys.prefix + "\\python.exe"
        debugpy.listen(("localhost", 5678))
        debugpy.wait_for_client()
    except:
        pass
    finally:
        sys.executable = oldpath


def PyRxCmd_pystartdebuglistener():
    startListener()

    # sample config
    # {
    #     "name": "Remote Attach",
    #     "type": "python",
    #     "request": "attach",
    #     "debugServer": 5678,
    #     "justMyCode": false
    # }
