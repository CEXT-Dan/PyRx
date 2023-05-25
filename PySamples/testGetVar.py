import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("command = pygetvar")
          
def PyRxCmd_pygetvar():
    try:
        ed = Ed.Editor()
        
        #result VALUE or None
        result = ed.getVar("FILLETRAD")
        print(result)
       
        #returns a bool
        result = ed.setVar("FILLETRAD", 1.25)
       
        result = ed.getVar("FILLETRAD")
        print(result)
		
        result = ed.getVar("SHIRTCOLOR")
        print(result)

    except Exception as err:
        print(err)
        
#Command: PYGETVAR
#0.0
#1.25
#(False, None)