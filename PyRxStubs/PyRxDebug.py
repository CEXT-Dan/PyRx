import wx
import os
import sys
import debugpy
import traceback

#pip install debugpy
#https://github.com/microsoft/debugpy/wiki

def testListener():
    try:
        if debugpy.is_client_connected():
            print("dubugger is conected...")
        else:
            print("dubugger not connected...")
    except Exception as err:
        traceback.print_exception(err)


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
        PYTHON_PATH = sys.base_prefix + "\\python.exe"
        
        os.environ["PYDEVD_DISABLE_FILE_VALIDATION"] = "1"
        debugpy.configure(python=PYTHON_PATH)
        debugpy.listen((DEBUG_HOST, DEBUG_PORT))
        debugpy.wait_for_client()
        print("dubugger running...")
        
    except Exception as err:
        traceback.print_exception(err)

# sample config
#  {
#     "name": "Remote Attach",
#     "type": "python",
#     "request": "attach",
#     "port": 5678,
#     "host": "127.0.0.1",
#     "justMyCode": false
# }

# or

# {
#    "name": "Remote Attach",
#    "type": "debugpy",
#     "request": "attach",
#     "connect": { "host": "127.0.0.1", "port": 5678 },
#     "justMyCode": false
# }