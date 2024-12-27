Python (Native Python)<br/>

bindings for C++: <br/>
AutoCAD®    ObjectARX®  2021-2025<br/>
ZwCAD®      ZRX®        2024-2025<br/>
GstarCAD®   GRX®        2024-2025<br/>
BricsCAD®   BRX®        v24-v25<br/>

bindings for ActiveX <br/>
AutoCAD®    2021-2025<br/>
BricsCAD    v24-v25<br/>
GstarCAD    2024-2025<br/>
ZwCAD       2024-2025<br/>

uses wxPython for the GUI, Dialogs and CAdUiPalette wrapper

Embeds Python (3.12) and wxPython(4.2.1) into a loadable ARX module

Read ths install info here https://github.com/CEXT-Dan/PyRx/blob/main/READMEINSTALL.md<br/>
Get the latest build from https://github.com/CEXT-Dan/PyRx/releases

On loading the ARX/BRX/GRX/ZRX module, the following commands are added to AutoCAD<br/>
PYLOAD:<br/> 
Use this command to load your python modules.<br/>

PYRELOAD:<br/>
Use this command to reload your python modules.<br/>

PYCMDPROMPT:<br/>
Provides simple access to the python interpreter <br/>

PYRXVER:<br/>
Prints the ARX module version<br/>

Autolisp:<br/>
(adspyload PATH) returns  T or nil<br/>
(adspyreload PATH) returns  T or nil<br/>
(adspyloaded) returns a list of loaded modules<br/>

#PyRx sample:

```Python
#imports 
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed, Sm
import traceback

 # these four (Optional) functions are called as they would be in ARX
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
```	

#ActiveX sample:

```Python
from pyrx_impx import Rx, Ge, Gi, Db, Ap, Ed, Ax
import traceback

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
        axSs.SelectByPolygon(
            Ax.constants.acSelectionSetFence, minmax, [0], ["ACAD_TABLE"]
        )

        for axEnt in axSs:
            axTable = Ax.IAcadTable(axEnt)
            hit = axTable.HitTest(hitPnt, hitVec)
            if hit[0]:
                cellstr = "Cell={},{}".format(hit[1], hit[2])
                axTable.SetTextString(hit[1], hit[2], 0, cellstr)
                return

    except Exception as err:
        traceback.print_exception(err)
    finally:
        axSs.Delete()
```

Create GUIs with wxPython, bindings for dialogs and palettes 

![wxPython Gui](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/palette.png), 

Generated stub files for built in help, autocomplete 

![wxPython Gui](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/stubs.png), 

Debugging support with debugpy

![wxPython Gui](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/debug.png), 

Blogs: https://pyarx.blogspot.com/
Discussion forum:  https://www.theswamp.org/index.php?board=76.0
