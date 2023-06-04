import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = pyselectall")

def PyRxCmd_pyselectall():
    ed = Ed.Editor()
    res = ed.selectAll()
    if res[0] == Ed.PromptStatus.eNormal:
        selection = res[1]
        print(selection.size())
        ids = selection.toList()
        print(ids)
        print(selection.hasMember(ids[0]))
        selection.remove(ids[0])
        print(selection.size())
        print(selection.hasMember(ids[0]))
        selection.add(ids[0])
        print(selection.hasMember(ids[0]))
        print(selection.size())
    