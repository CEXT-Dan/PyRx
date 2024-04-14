Install python (64 bit) python3.12.X with PATH checkbox set to true.

![Python install](https://github.com/CEXT-Dan/PyRx/blob/main/pyinstall.png), 

![Environment](https://github.com/CEXT-Dan/PyRx/blob/main/env.png)

install wxPython 4.2.1 from https://pypi.org/project/wxPython/

Run the PyRxSetup installer https://github.com/CEXT-Dan/PyRx/releases

The bulk of the stuff is installed into:
%AppData%\Local\Programs\PyRx
And
Loader files for AutoCAD are in %AppData%\Roaming\Autodesk\ApplicationPlugins\PyRx.bundle

win32com must be installed if you would like to use the ActiveX libraries
pip install pywin32

****BricsCAD, ZwCAD and GstarCAD****
BRX, ZRX and GRX libraries are installed in %AppData%\Local\Programs\PyRx. Use the appload command and navigate to load the files. 
add to your startup suite
