import os

import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 


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
		return [(PyRx.LispDataType.kListBegin, 0),
	            (PyRx.LispDataType.kText, "Text"),
		        (PyRx.LispDataType.kDouble, 12.23),
			    (PyRx.LispDataType.kListBegin, 0),
			    (PyRx.LispDataType.kInt16, 1),
			    (PyRx.LispDataType.kInt32, 2),
			    (PyRx.LispDataType.kNil, 0),
			    (PyRx.LispDataType.kT_atom, 0),
			    (PyRx.LispDataType.kListEnd, 0),
		     	(PyRx.LispDataType.kPoint3d,PyGe.Point3d(1,10,100)),
				(PyRx.LispDataType.kListEnd, 0)]
	except Exception as err:
		print(err)

#(pylisp1)
def PyRxLisp_pylisp1(args):
	try: 
		return [(PyRx.LispDataType.kText, "Text")]
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
