import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyPl as Pl
import PyGs as Gs

# this module is to hide Pylance 'module not found' warnings
# Pylance cant read Python embedded in C++

import importlib.util
if importlib.util.find_spec("PyBrxCv") is not None:
    import PyBrxCv as Cv

import importlib
flag = importlib.import_module('win32com')
if flag is not None:
    try:
        host = Ap.Application.hostAPI()
        if host == "BRX24":
            import BxApp24 as Ax
        elif host == "GRX24":
            import GxApp24 as Ax
        elif host == "ZRX24":
            import ZxApp24 as Ax
        elif host == "ZRX25":
            import ZxApp25 as Ax
        elif host == "ARX24":
            import AxApp24 as Ax
        elif host == "ARX25":
            import AxApp25 as Ax
    except ImportError:
        pass
        
    
