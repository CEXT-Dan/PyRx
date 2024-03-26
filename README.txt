Python (Native Python)

bindings for C++: 
AutoCAD®    ObjectARX®  2021-2025
ZwCAD®      ZRX®        2024
GstarCAD®   GRX®        2024
BricsCAD®   BRX®        2024

bindings for ActiveX 
AutoCAD®    2021-2025
BricsCAD    v24
GstarCAD    2024
ZwCAD       2024

uses wxPython for the GUI, Dialogs and CAdUiPalette wrapper

Embeds Python (3.12) and wxPython(4.2.1) into a loadable ARX module

Get the latest build from https://github.com/CEXT-Dan/PyRx/releases
or https://github.com/CEXT-Dan/PyRx/tags

On loading the ARX/BRX/GRX/ZRX module, the following commands are added to AutoCAD
PYLOAD: 
Use this command to load your python modules.

PYRELOAD:
Use this command to reload your python modules.

PYCMDPROMPT:
Provides simple access to the python interpreter 

PYRXVER:
Prints the ARX module version

Autolisp:
(pyload PATH) returns  T or nil
(pyloaded) returns a list of loaded modules


PyRx sample:

#imports 
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed

 # these four functions are called as they would be in ARX
def OnPyInitApp():
    print("\nOnPyInitApp")
    print("\ncommand = pydoit")

def OnPyUnloadApp():
    print("\nOnPyUnloadApp")

def OnPyLoadDwg():
    print("\nOnPyLoadDwg")

def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")

 # functions that are prefixed with PyRxCmd_ are registered as AutoCAD commands
def PyRxCmd_pydoit():
    try:
        db = Db.HostApplicationServices().workingDatabase()

        # create a line
        line = Db.Line()
        line.setDatabaseDefaults()

        # use Ge point
        line.setStartPoint(Ge.Point3d(0, 0, 0))
        line.setEndPoint(Ge.Point3d(100, 100, 0))

        # set a color
        color = Db.Color()
        color.setRGB(255, 255, 0)
        line.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(line)

    except Exception as err:
        print(err)

		
...
ActiveX sample:

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
import traceback
 
import AxApp24 as Ax
import AxAppUtils24 as AxUt
 
def PyRxCmd_makeTable():
    try:
        axApp = Ax.getApp()
        axDoc = axApp.ActiveDocument
 
        tablePnt = axDoc.Utility.GetPoint("\nTable location: ")
        axDoc.ModelSpace.AddTable(tablePnt, 5, 5, 10, 30)
 
    except Exception as err:
        traceback.print_exception(err)
 
def PyRxCmd_hitTest():
    try:
        axApp = Ax.getApp()
        axDoc = axApp.ActiveDocument
        
        hitVec = (0, 0, 1)  # kZaxis
        hitPnt = axDoc.Utility.GetPoint("\nSelect cell: ")
        minmax = hitPnt + axDoc.GetVariable("VSMAX")
 
        axSs = axDoc.SelectionSets.Add("AXTBLSS")
        axSs.SelectByPolygon(Ax.constants.acSelectionSetFence,
                             minmax, [0], ["ACAD_TABLE"])
        
        for axEnt in axSs:
            axTable = Ax.IAcadTable(axEnt)
            hit = axTable.HitTest(hitPnt, hitVec)
            if hit[0]:
                cellstr = "Cell={},{}".format(hit[1], hit[2])
                axTable.SetTextString(hit[1], hit[2], 1, cellstr)
                return
            
    except Exception as err:
        traceback.print_exception(err)
        
    finally:
        axSs.Delete()

Blogs: https://pyarx.blogspot.com/
Discussion forum:  https://www.theswamp.org/index.php?board=76.0
