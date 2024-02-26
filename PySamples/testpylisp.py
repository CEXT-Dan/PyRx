from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

def OnPyInitApp():
    print("\nOnPyInitApp")
    
def OnPyUnloadApp():
   print("\nOnPyUnloadApp")

def OnPyLoadDwg():
   print("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

# (pylisp)
def PyRxLisp_pylisp(args):
    try:
        return [(Rx.LispType.kListBegin, 0),
                (Rx.LispType.kText, "Text"),
                (Rx.LispType.kDouble, 12.23),
                (Rx.LispType.kListBegin, 0),
                (Rx.LispType.kInt16, 1),
                (Rx.LispType.kInt32, 2),
                (Rx.LispType.kNil, 0),
                (Rx.LispType.kT_atom, 0),
                (Rx.LispType.kListEnd, 0),
                (Rx.LispType.kPoint3d, Ge.Point3d(1, 10, 100)),
                (Rx.LispType.kListEnd, 0)]
    except Exception as err:
        print(err)

# (pylisp1)
def PyRxLisp_pylisp1(args):
    try:
        return [(Rx.LispType.kText, "Text")]
    except Exception as err:
        print(err)

# (pylisprt '("hello world" 1 2 3 4 (1 10 100)))
def PyRxLisp_pylisprt(args):
    try:
        return args
    except Exception as err:
        print(err)

# (pylispvoid)
def PyRxLisp_pylispvoid(args):
    try:
        print("yay!")
    except Exception as err:
        print(err)

# (pylispbool)
def PyRxLisp_pylispbool(args):
    try:
        print("yay!")
        return True
    except Exception as err:
        print(err)

# (pylispint)
def PyRxLisp_pylispint(args):
    try:
        print("yay!")
        return 42
    except Exception as err:
        print(err)

# (pylispreal)
def PyRxLisp_pylispreal(args):
    try:
        print("yay!")
        return 1.1
    except Exception as err:
        print(err)

# (pylisp2p)
def PyRxLisp_pylisp2p(args):
    try:
        print("yay!")
        return Ge.Point2d(1.2, 1.4)
    except Exception as err:
        print(err)

# (pylisp3p)
def PyRxLisp_pylisp3p(args):
    try:
        print("yay!")
        return Ge.Point3d(1.2, 1.4, 4.5)
    except Exception as err:
        print(err)

# (pylispstr)
def PyRxLisp_pylispstr(args):
    try:
        print("yay!")
        return "woohoo"
    except Exception as err:
        print(err)
