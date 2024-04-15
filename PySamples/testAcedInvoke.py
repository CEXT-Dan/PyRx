from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

#args must end with (Rx.LispType.kNone,0)

#  (defun C:ADDNUM ( x / ) (+ x x))
def PyRxCmd_doit(CmDFlags = Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:ADDNUM"),(Rx.LispType.kInt16,10),(Rx.LispType.kNone,0) ]
        result = Ed.Core.invoke(args)
        print(result)
      
    except Exception as err:
        print(err)
        
    #  (defun C:GETLASTENT () (entget(entlast)))
def PyRxCmd_doit2(CmDFlags = Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:GETLASTENT"),(Rx.LispType.kNone,0) ]
        result = Ed.Core.invoke(args)
        print(result)
      
    except Exception as err:
        print(err)
        
        
#  (defun C:GETENTSEL () (entget(car(entsel))))
def PyRxCmd_doit3():
    try:
        args = [(Rx.LispType.kText, "C:GETENTSEL"),(Rx.LispType.kNone,0) ]
        result = Ed.Core.invoke(args)
        print(result)
      
    except Exception as err:
        print(err)