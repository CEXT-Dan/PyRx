# PyRx

[Visit us on PyPi](https://pypi.org/project/cad-pyrx/)

PyRx provides Python bindings for CAD software:

**C++ bindings**:

- **AutoCAD®**: ObjectARX® 2021-2025
- **ZwCAD®**: ZRX® 2024-2025
- **GstarCAD®**: GRX® 2024-2025
- **BricsCAD®**: BRX® v24-v25

**ActiveX bindings**:

- **AutoCAD®**: 2021-2025
- **BricsCAD®**: v24-v25
- **GstarCAD®**: 2024-2025
- **ZwCAD®**: 2024-2025

_Wherever in this project we talk about AutoCAD, we mean all supported applications (BricsCAD, GstarCAD, ZwCAD), and when we talk about ARX (Object ARX), we also mean BRX, GRX and ZRX._

Uses wxPython for the GUI, dialogs, and CAdUiPalette wrapper.
Embeds Python (3.12) and wxPython (4.2.2) into a loadable ARX module.

## Installation

Install [python 3.12.X](https://www.python.org/downloads/windows/) (64 bit) with the :exclamation:PATH checkbox:exclamation: set to true:

![Python install](./GitResources/images/pyinstall.png),

Environment paths should look like this:

![Environment](./GitResources/images/env.png)

Install PyRx from [PyPI](https://pypi.org/project/cad-pyrx):

```bash
pip install cad-pyrx
```

Use ``APPLOAD`` command or the startup suite to load PyRx in CAD application, example:

```raw
_APPLOAD
%localappdata%\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderZ25.0.zrx
```

Install PyRx from a tag , e.g. for git tag v2.1.7:  

```bash
python -m pip install git+https://github.com/CEXT-Dan/PyRx.git@v2.1.7
```

Install PyRx from the latest commit:

```bash
python -m pip install git+https://github.com/CEXT-Dan/PyRx.git
```

Uninstall:

```bash
python -m pip uninstall cad-pyrx
```

AutoCAD user may optionally install a .bundle using the MSI installer attached to the release

## Downloads

Get the latest build from [GitHub Releases](https://github.com/CEXT-Dan/PyRx/releases).

## Commands

When loading the ARX/BRX/GRX/ZRX module, the following commands are added to CAD application:

- **PYLOAD**: Use this command to load your Python modules
- **PYRELOAD**: Use this command to reload your Python modules
- **PYCMDPROMPT**: Provides simple access to the python interpreter
- **PYRXVER**: Prints the ARX module version
- **PYRXLOADLOG**: Prints the ARX module load logs

**Autolisp commands:**  
``(adspyload PATH)`` returns T or nil  
``(adspyreload PATH)`` returns T or nil  
``(adspyloaded)`` returns a list of loaded modules  

## ARX sample

```py
from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Sm
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

    except Exception:
        traceback.print_exc()
```

## ActiveX sample

```py
from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax
import traceback

def PyRxCmd_makeTable():
    try:
        axApp = Ax.getApp()
        axDoc = axApp.ActiveDocument
        
        tablePnt = axDoc.Utility.GetPoint("\nTable location: ")
        axDoc.ModelSpace.AddTable(tablePnt, 5, 5, 10, 30)
        
    except Exception:
        traceback.print_exc()


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

    except Exception:
        traceback.print_exc()
    finally:
        axSs.Delete()
```

**and many more examples**: <https://github.com/CEXT-Dan/PyRx/tree/main/PySamples>

## Features

- Create GUIs with wxPython, bindings for dialogs and palettes

    ![wxPython Gui](./GitResources/images/palette.png)

- Generated stub files for built in help, autocomplete

    ![stubs](./GitResources/images/stubs.png)

- Debugging support with debugpy

    ![debug](./GitResources/images/debug.png)

## See also

- [Blogs](https://pyarx.blogspot.com)
- [Discussion forum](https://www.theswamp.org/index.php?board=76.0)
- [AutoCAD Object Model (AutoLISP/ActiveX)](https://help.autodesk.com/view/OARX/2025/ENU/?guid=GUID-A809CD71-4655-44E2-B674-1FE200B9FE30)
- [ObjectARX Reference Guide](https://help.autodesk.com/view/OARX/2025/ENU/?guid=OARX-RefGuide-ObjectARX_Reference_Guide)
