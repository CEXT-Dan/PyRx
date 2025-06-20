import wx

from pyrx import Db, Ed

print("added command = pyaddmenu")
print("added command = pyremovemenu")


# subclass UIContext
class MyMenu(Ed.UIContext):
    def __init__(self):
        Ed.UIContext.__init__(self)
        self.contextMenu = wx.Menu()
        self.contextMenu.Append(10001, "🖨️ Print Attributes")
        self.ids = []
        self.rxClass = None

    # return the menu
    def getMenuContext(self, rxClass, ids):
        self.rxClass = rxClass
        self.ids = ids
        return self.contextMenu

    def onCommand(self, cmd):
        if cmd == 10001:
            self.doCmd10001()

    def OnUpdateMenu(self):
        print("update")

    def doCmd10001(self):
        for id in self.ids:
            bref = Db.BlockReference(id)
            brec = Db.BlockTableRecord(bref.blockTableRecord())
            for refid in brec.getBlockReferenceIds():
                subbref = Db.BlockReference(refid)
                for attid in subbref.attributeIds():
                    att = Db.AttributeReference(attid)
                    print(att.textString())


# global, we don't want it to be garbage collected
menus = []


def PyRxCmd_pyaddmenu():
    try:
        menus.append(MyMenu())
        flag = Ed.UIContext.addObjectContextMenu(Db.BlockReference.desc(), menus[0])
        if flag:
            print("YaY!")
        else:
            print("Boo!")
    except Exception as err:
        print(err)


def PyRxCmd_pyremovemenu():
    try:
        flag = Ed.UIContext.removeObjectContextMenu(Db.BlockReference.desc(), menus[0])
        if flag:
            menus[0] = None
            print("YaY!")
        else:
            print("Boo!")
    except Exception as err:
        print(err)
