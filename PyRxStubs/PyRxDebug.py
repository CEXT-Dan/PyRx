import wx
import sys
import debugpy
import traceback


def startListener():
    try:
        result = wx.MessageDialog(
            None,
            "This will start the debug Listener for the session"
            + "\n"
            + "Now is a good time to run your debugger from vs code:",
            "Confirm",
            wx.YES_NO | wx.NO_DEFAULT | wx.ICON_QUESTION,
        ).ShowModal()

        if result != wx.ID_YES:
            return

        #config
        DEBUG_HOST = "127.0.0.1"
        DEBUG_PORT = 5678
        PYTHON_PATH = sys.prefix + "\\python.exe"

        debugpy.configure(python=PYTHON_PATH)
        debugpy.listen((DEBUG_HOST, DEBUG_PORT))
        
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pystartdebuglistener():
    startListener()


# sample config
#  {
#     "name": "Remote Attach",
#     "type": "python",
#     "request": "attach",
#     "port": 5678,
#     "host": "127.0.0.1",
#     "justMyCode": false
# }
