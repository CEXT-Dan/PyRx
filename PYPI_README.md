# CAD-PyRx

## Python for AutoCAD & Clones

CAD-PyRx is an ObjectARX module that exposes ObjectARX methods to Python, CAD-PyRx also exposes CAD's ActiveX API.
Currently supported platforms are AutoCAD® 2021-2025, BricsCAD® V24-V25, GStarCAD® 2024-2025, and ZwCAD® 2024-2025

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
- Install from a tag, i.e. where v2.1.7 is the target tag:  
  ``python -m pip install git+https://github.com/CEXT-Dan/PyRx.git@v2.1.7``
- Install from the trunk:  
  ``python -m pip install git+https://github.com/CEXT-Dan/PyRx.git``
- Uninstall:  
  ``python -m pip uninstall cad-pyrx``

Use ``APPLOAD`` command or the startup suite to load PyRx in CAD application, example:

```raw
_APPLOAD
%localappdata%\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderZ25.0.zrx
```

## Sample

```Python
# define a command called doit1
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

# define a command called doit2
def PyRxCmd_doit2():
    try:
        db = Db.curDb()
        ps, id, _ = Ed.Editor.entSel("\nSelect a line: ", Db.Line.desc())
        if ps != Ed.PromptStatus.eOk:
            return

        # all DbObjects except an ID in the constructor
        # line is garbage collected and closed
        line = Db.Line(id, Db.OpenMode.kForWrite)
        line.setLayer("0")

    except Exception as err:
        traceback.print_exception(err)
```
