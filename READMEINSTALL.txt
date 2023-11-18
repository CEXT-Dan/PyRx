Install python (64 bit) python3.10.10 with PATH checkbox set to true.
https://www.python.org/downloads/release/python-31010/

install wxPython 4.2.0 from https://pypi.org/project/wxPython/
pip install wxPython==4.2.0

Run the PyRxSetup installer
This setup writes two values to the registry, adds wxPython to PATH, adds autocomplete stubs path to PYTHONPATH.
The stub files are for intellisense in Visual studio code

see env.png in this folder

Installs a .bundle in %ProgramData\Autodesk\ApplicationPlugins\PyRx.bundle
./PyRxHelp
./PyRxStubs
./PyRxSamples

win32com must be installed if you would like to use the ActiveX libraries
pip install pywin32

****ZwCAD and GstarCAD****
ZRX and GRX libraries are installed in same folder. Use the appload command and navigate to load the files. 
The GRX / ZRX modules may be moved to another location 
