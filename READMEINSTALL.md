Install python (64 bit) python3.12.X with the :exclamation:PATH checkbox:exclamation: set to true.

![Python install](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/pyinstall.png), 

Environment paths should look like this

![Environment](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/env.png)

install wxPython 4.2.1 from https://pypi.org/project/wxPython/
in powershell, run "pip install wxPython"

Run the PyRxSetup installer https://github.com/CEXT-Dan/PyRx/releases

The bulk of the stuff is installed into:
%AppData%\Local\Programs\PyRx
And
Loader files for AutoCAD are in %AppData%\Roaming\Autodesk\ApplicationPlugins\PyRx.bundle

win32com must be installed if you would like to use the ActiveX libraries
pip install pywin32, https://pypi.org/project/pywin32/

Other recommended python libraries.
debugpy for attaching to CAD and debugging, https://pypi.org/project/debugpy/
 


****BricsCAD, ZwCAD and GstarCAD****
BRX, ZRX and GRX libraries are installed in %AppData%\Local\Programs\PyRx. Use the appload command and navigate to load the files. 
add to your startup suite

If the module does not load the first time around. Run (setenv "PYRX_LOG" "1") from lisp.
The next time you attempt to load the module, some information will be printed on the screen  

BricsCAD users,
This these modules have nothing to do with BricsCAD BIMPYTHON.
