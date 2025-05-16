# CAD-PyRx

## Python for AutoCAD & Clones

CAD-PyRx is an ObjectARX module that exposes ObjectARX methods to Python, CAD-PyRx also exposes CAD's ActiveX API.
Currently supported platforms are AutoCAD® 2021-2026, BricsCAD® V24.2-V25.2, GStarCAD® 2024-2026, and ZwCAD® 2024-2026

## Features

- uses wxPython for the GUI, support for Palette and Dialogs
- degugpy to easily step through and debug your code
- Jig, Overrule, Point monitor and other advanced tools
- readDwgFile to open and manipulate side databases
- import other python modules such as pandas

## Installation

- [Install Python 3.12 as shown here](https://github.com/CEXT-Dan/PyRx/blob/main/README.md#Installation)
- Install from PyPI (here):  
  ``pip install cad-pyrx``
- Install from the trunk:  
  ``python -m pip install git+https://github.com/CEXT-Dan/PyRx.git``
- Uninstall:  
  ``python -m pip uninstall cad-pyrx``

Use ``APPLOAD`` command or the startup suite to load PyRx in CAD application, example: Note: if you are using a VENV, this path may differ, it will be loacated where you installed it

```raw
_APPLOAD
%localappdata%\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderZ25.0.zrx
or
RxLoader24.0.arx = 2021
RxLoader24.1.arx = 2022
RxLoader24.2.arx = 2023
RxLoader24.3.arx = 2024
RxLoader25.0.arx = 2025
RxLoader25.1.arx = 2026
RxLoaderV25.0.brx = BricsCAD v25
```

## Sample

```Python
# use prefix PyRxCmd_ to define a command called doit1
def PyRxCmd_doit1():
    try:
        db = Db.curDb()
        filter = [(Db.DxfCode.kDxfStart, "LINE")]
        ps, ss = Ed.Editor.select(filter)
        if ps != Ed.PromptStatus.eOk:
            return

        lines = [Db.Line(id) for id in ss.objectIds()]
        for line in lines:
            print(line.startPoint().distanceTo(line.endPoint()))

    except Exception as err:
        traceback.print_exception(err)

# or use decorator to define a command called doit2
@Ap.Command("doit2", Ap.CmdFlags.kMODAL)
def function_setlayer():
    try:
        db = Db.curDb()
        ps, id, _ = Ed.Editor.entSel("\nSelect a line: ", Db.Line.desc())
        if ps != Ed.PromptStatus.eOk:
            return

        # all DbObjects accept an ID in the constructor
        # line is garbage collected and closed
        line = Db.Line(id, Db.OpenMode.kForWrite)
        line.setLayer("0")

    except Exception as err:
        traceback.print_exception(err)
```
