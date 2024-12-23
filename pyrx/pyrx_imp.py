import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyPl as Pl
import PyGs as Gs
import PySm as Sm
import PyBr as Br

import importlib.util
if importlib.util.find_spec("PyBrxCv") is not None:
    import PyBrxCv as Cv
    
if importlib.util.find_spec("PyBrxBim") is not None:
    import PyBrxBim as Bim
    
if importlib.util.find_spec("PyBrx") is not None:
    import PyBrx as Brx

# this module is to hide Pylance 'module not found' warnings
# Pylance cant read Python embedded in C++
