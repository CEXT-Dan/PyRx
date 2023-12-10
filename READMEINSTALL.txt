Install python (64 bit) python3.12.X with PATH checkbox set to true.

install wxPython 4.2.1 from https://pypi.org/project/wxPython/

Run the PyRxSetup installer https://github.com/CEXT-Dan/PyRx/releases or https://github.com/CEXT-Dan/PyRx/tags
This setup writes two values to the registry, adds wxPython to PATH, adds autocomplete stubs path to PYTHONPATH.
The stub files are for intellisense in Visual studio code

see env.png in this folder

Installs a .bundle in %ProgramData\Autodesk\ApplicationPlugins\PyRx.bundle
./PyRxHelp
./PyRxStubs
./PyRxSamples

win32com must be installed if you would like to use the ActiveX libraries
pip install pywin32

****BricsCAD, ZwCAD and GstarCAD****
BRX, ZRX and GRX libraries are installed in same ApplicationPlugins folder as above. Use the appload command and navigate to load the files. 
The BRX / GRX / ZRX modules may be moved to another location
