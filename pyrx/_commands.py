import subprocess
import sys
import traceback

import wx

from pyrx import Ed

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


class PipManager:
    """
    A utility class for managing Python packages using pip.
    The PipManager class provides static methods to install, update, uninstall, and list Python packages
    by invoking pip commands through subprocess. Each method handles exceptions and prints the output or errors.
    Methods
    -------
    install(package: str) -> None
        Installs the specified Python package using pip.
    update(package: str) -> None
        Upgrades the specified Python package to the latest version using pip.
    uninstall(package: str) -> None
        Uninstalls the specified Python package using pip.
    list() -> None
        Lists all installed Python packages using pip.
    """

    @staticmethod
    def install(package: str) -> None:
        try:
            result = subprocess.run(
                [sys.executable, "-m", "pip", "install", package],
                capture_output=True,
                text=True,
                check=True,
                shell=True,
            )
            print(f"{result.stdout}\n")
        except subprocess.CalledProcessError as e:
            print(f"Failed to install {package}: {e}")
        except Exception as e:
            print(f"An error occurred while installing {package}: {e}")
            traceback.print_exc()

    @staticmethod
    def update(package: str) -> None:
        try:
            result = subprocess.run(
                [sys.executable, "-m", "pip", "install", "--upgrade", package],
                capture_output=True,
                text=True,
                check=True,
                shell=True,
            )
            print(f"{result.stdout}\n")
        except subprocess.CalledProcessError as e:
            print(f"Failed to upgrade {package}: {e}")
        except Exception as e:
            print(f"An error occurred while upgrading {package}: {e}")
            traceback.print_exc()

    @staticmethod
    def uninstall(package: str) -> None:
        try:
            result = subprocess.run(
                [sys.executable, "-m", "pip", "uninstall", "-y", package],
                capture_output=True,
                text=True,
                check=True,
                shell=True,
            )
            print(f"{result.stdout}\n")
        except subprocess.CalledProcessError as e:
            print(f"Failed to uninstall {package}: {e}")
        except Exception as e:
            print(f"An error occurred while uninstalling {package}: {e}")
            traceback.print_exc()

    @staticmethod
    def list() -> None:
        try:
            result = subprocess.run(
                [sys.executable, "-m", "pip", "list"],
                capture_output=True,
                text=True,
                check=True,
                shell=True,
            )
            print(f"{result.stdout}\n")
        except subprocess.CalledProcessError as e:
            print(f"Command failed with error: {e}")
        except Exception:
            print("An error occurred while calling list:")
            traceback.print_exc()


@command
def pypip() -> None:
    """
    Interactively manage Python packages using a PIP-like interface.
    Prompts the user to select an action (List, Install, Remove, Update) and performs the corresponding
    operation using the PIP. For Install, (Uninstall)Remove, and Update actions, the user is prompted to enter
    the package name. Raises an exception if user input is cancelled or invalid.
    Replicates basic PIP functionality within the application.
    """
    ig_ps = Ed.Editor.initGet(0, "List Install Remove Update")
    if ig_ps != Ed.PromptStatus.eOk:
        raise Exception(ig_ps)

    kw_ps, kw_str = Ed.Editor.getKword("\n[List/Install/Remove/Update] <list>: ")
    if kw_ps != Ed.PromptStatus.eOk and kw_ps != Ed.PromptStatus.eNone:
        raise Exception(kw_ps)

    def _getPackageName() -> str:
        gs_ps, gs_str = Ed.Editor.getString("\nEnter package: ", Ed.PromptCondition.eNoEmpty)
        if ig_ps != Ed.PromptStatus.eOk:
            raise Exception(gs_ps)
        return gs_str.strip()

    match kw_str:
        case "List":
            PipManager.list()
        case "Install":
            PipManager.install(_getPackageName())
        case "Remove":
            PipManager.uninstall(_getPackageName())
        case "Update":
            PipManager.update(_getPackageName())
        case _:
            PipManager.list()
