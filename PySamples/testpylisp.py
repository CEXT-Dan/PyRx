import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

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
		return [(Rx.LispDataType.kListBegin, 0),
	            (Rx.LispDataType.kText, "Text"),
		        (Rx.LispDataType.kDouble, 12.23),
			    (Rx.LispDataType.kListBegin, 0),
			    (Rx.LispDataType.kInt16, 1),
			    (Rx.LispDataType.kInt32, 2),
			    (Rx.LispDataType.kNil, 0),
			    (Rx.LispDataType.kT_atom, 0),
			    (Rx.LispDataType.kListEnd, 0),
		     	(Rx.LispDataType.kPoint3d,Ge.Point3d(1,10,100)),
				(Rx.LispDataType.kListEnd, 0)]
	except Exception as err:
		print(err)

#(pylisp1)
def PyRxLisp_pylisp1(args):
	try: 
		return [(Rx.LispDataType.kText, "Text")]
	except Exception as err:
		print(err)

#(pylisprt '("hello world" 1 2 3 4 (1 10 100)))
def PyRxLisp_pylisprt(args):
	try: 
		return args
	except Exception as err:
		print(err)

#(pylispvoid)	
def PyRxLisp_pylispvoid(args):
	try: 
		print("yay!")
	except Exception as err:
		print(err)

#(pylispbad)	
def PyRxLisp_pylispbad(args):
	try: 
		print("yay!")
		return "bad"
	except Exception as err:
		print(err)
