from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
import traceback

import AxApp24 as Ax
import AxAppUtils24 as AxUt

axApp = Ax.getApp()
axDoc = axApp.ActiveDocument

# create doc event class
class DocumentEvents():
    def OnLayoutSwitched(self, LayoutName):
        print('fired LayoutSwitched', LayoutName)

# create app event class
class ApplicationEvents:
    
    def __init__ (self):
        self.docEvents = {}
        
    def OnAppActivate(self):
        print('fired OnAppActivate')

    def OnAppDeactivate(self):
        print('fired OnAppDeactivate')

    def OnSysVarChanged(self, varname, val):
        print('fired OnSysVarChanged varname={}, val={}'.format(varname, val))
    
    def OnBeginCommand(self, CommandName):
        print("OnBeginCommand fired",CommandName)
    
    def OnBeginOpen(self, Filename):
        print("OnBeginOpen fired",Filename)
      
    def OnEndOpen(self, Filename):
        print("OnEndOpen fired")
        for doc in axApp.Documents:
            if doc.Name == Filename:
                self.docEvents[Filename] = Ax.createEventObject(doc, DocumentEvents)
                
# register it
eventApp = Ax.createEventObject(axApp, ApplicationEvents)


def PyRxCmd_doit():
    try:
        print("hi")
    except Exception as err:
        traceback.print_exception(err)

