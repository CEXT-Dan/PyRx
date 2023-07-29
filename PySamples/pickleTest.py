import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyGs as Gs

import pickle

def pickleizer():
    sysvars = Ed.Core.getSysVars()
    pickle.dump(sysvars, open("E:\\SysVar.p", "wb"))
    return sysvars


def depickleizer():
    sysvars = pickle.load(open("E:\\SysVar.p", "rb"))
    return sysvars

# pickle
def PyRxCmd_doit():
    try:
        pickleizer()
    except Exception as err:
        print(err)

# unpickle
def PyRxCmd_doit2():
    try:
        sysvars = depickleizer()
        print(sysvars)
    except Exception as err:
        print(err)

# pickle test
def PyRxCmd_doit3():
    try:
        sysvars1 = pickleizer()
        sysvars2 = depickleizer()
        for left, right in zip(sysvars1.values(), sysvars2.values()):
            if left != right:
                print(left, "!=", right)

    except Exception as err:
        print(err)
