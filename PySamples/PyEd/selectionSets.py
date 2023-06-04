import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = pyselectall")
print("added command = pyselectallf")

def PyRxCmd_pyselectall():
    try:
        ed = Ed.Editor()
        
        #returns a tuple (PromptStatus, SelectionSet)
        ssres = ed.selectAll()
        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
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
    except Exception as err:
	    PyRxApp.Printf(err)


def PyRxCmd_pyselectallf():
    try:
        
        #create a filter, a list of tuples
        filter = [(Db.DxfCode.kDxfStart,"CIRCLE")]
        ed = Ed.Editor()
        
        #returns a tuple (PromptStatus, SelectionSet)
        ssres = ed.selectAll(filter)
        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
            print(selection.size())
            
    except Exception as err:
	    print(err)