import wx

from . import command
from .PyRxDebug import startListener
from .utils.wx import show_inspection_frame

command(show_inspection_frame, name="PY_WX_INSPECT")

_VSCODE_DEBUG_CONFIG = """{
    "name": "Remote Attach",
    "type": "debugpy",
    "request": "attach",
    "connect": {
        "host": "127.0.0.1",
        "port": "${command:pickArgs}"
    },
    "justMyCode": false
}"""


@command
def pydebug_port():
    dlg = wx.TextEntryDialog(None, "Enter the port for the debug listener:", "Debug Port", "5678")
    with dlg:
        if not dlg.ShowModal() == wx.ID_OK:
            return
    try:
        port = int(dlg.GetValue())
    except ValueError:
        wx.MessageBox(
            "Invalid port number. Please enter a valid integer.", "Error", wx.OK | wx.ICON_ERROR
        )
        return
    if port < 1 or port > 65535:
        wx.MessageBox("Port number must be between 1 and 65535.", "Error", wx.OK | wx.ICON_ERROR)
        return
    startListener(port=port, quit=True)
    print(
        f"Debug listener started on port {port}. "
        "You can use the following configuration in VS Code:\n"
        f"{_VSCODE_DEBUG_CONFIG}"
    )
