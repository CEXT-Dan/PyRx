# CAD-PyRx
## Python for AutoCAD
CAD-PyRx is an ObjectARX module that exposes ObjectARX methods to Python, CAD-PyRx also exposes CAD's ActiveX API.
Currently supported platforms are AutoCAD 2021-2025, BricsCAD V24-V25, GStarCAD 2024-2025, and ZwCAD 2024-2025

## Features
- uses wxPython for the GUI, support for Palette and Dialogs
- degugpy to easily step through and debug your code
- Jig, Overrules, Point monitor and other advanced tools
- readDwgFile to open and manipulate side databases
- import other python modules such as pandas

## Installation

- [Install Python 3.12 as shown here](https://github.com/CEXT-Dan/PyRx/blob/main/READMEINSTALL.md)
- Install from PyPi:
  pip install cad-pyrx   -here- https://pypi.org/project/cad-pyrx/
- Install from a tag, where v2.1.7 is the target tag:
  python -m pip install git+https://github.com/CEXT-Dan/PyRx.git@v2.1.7
- Install from the trunk:
  python -m pip install git+https://github.com/CEXT-Dan/PyRx.git
- Uninstall:
  python -m pip uninstall cad-pyrx

use appload, or the startup suite to load the module, example
appload C:\Users\Dan\AppData\Local\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderV25.0.brx