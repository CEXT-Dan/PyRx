from collections import deque
import wx
from pyrx import Ap, Db, Ed

print("Added command = pyaddrepeat")
print("Added command = pyremoverepeat")

# exit clean
def OnPyUnloadApp():
    pyremoverepeat()

recent_commands = deque(maxlen=5)
IGNORED_COMMANDS = {"PYADDREPEAT", "PYREMOVEREPEAT", "U", "UNDO", "REDO"}

class CommandHistoryReactor(Ed.EditorReactor):
    def __init__(self):
        Ed.EditorReactor.__init__(self)
       
    def commandEnded(self, cmdStr: str):
        cmd = cmdStr.strip().upper()
        if not cmd or cmd.startswith('_') or cmd in IGNORED_COMMANDS:
            return
        if cmd in recent_commands:
            recent_commands.remove(cmd)
        recent_commands.appendleft(cmd)

class MyMenu(Ed.UIContext):
    def __init__(self):
        Ed.UIContext.__init__(self)
        self.contextMenu = None
        self.cmd_map = {}

    def getMenuContext(self, rxClass, ids):
        self.contextMenu = wx.Menu()
        self.cmd_map.clear()
        if not recent_commands:
            item = self.contextMenu.Append(10000, "(No recent commands)")
            item.Enable(False)
        else:
            for idx, cmd_name in enumerate(recent_commands):
                menu_id = 10001 + idx
                self.cmd_map[menu_id] = cmd_name
                self.contextMenu.Append(menu_id, f"Repeat {cmd_name}")
        return self.contextMenu

    def onCommand(self, cmd):
        if cmd in self.cmd_map:
            chosen_cmd = self.cmd_map[cmd]
            Ap.DocManager().sendStringToExecute(
                Ap.curDoc(), f"_{chosen_cmd} ", True, False, False
            )

    def OnUpdateMenu(self):
        pass


# === Global State ===
menus = []
reactor = None

@Ap.Command()
def pyaddrepeat():
    global reactor
    try:
        if reactor is None:
            reactor = CommandHistoryReactor()
            reactor.addReactor()
        if not menus:
            menu = MyMenu()
            if Ed.UIContext.addDefaultContextMenu(menu, "Repeat Commands"):
                menus.append(menu)
                print("Repeat Commands context menu added.")
            else:
                print("Failed to add context menu.")
    except Exception as err:
        print(f"Error in pyaddrepeat: {err}")

@Ap.Command()
def pyremoverepeat():
    global reactor
    try:
        if menus:
            Ed.UIContext.removeDefaultContextMenu(menus[0])
            menus.clear()
            print("Repeat Commands context menu removed.")
        if reactor is not None:
            reactor.removeReactor()
            reactor = None
    except Exception as err:
        print(f"Error in pyremoverepeat: {err}")
