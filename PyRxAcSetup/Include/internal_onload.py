import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed

loadedOnce = False

def OnPyLoadDwg() -> None:
    global loadedOnce
    if loadedOnce == False:
        Ap.Application.loadPythonModule("M:/Dev/Projects/PyRxGit/unitTests/UnitTestRunner.py")
        Ap.Application.loadPythonModule("M:/Dev/Projects/PyRxGit/PyRxStubs/utility/genDoc.py")
        loadedOnce = True
    

