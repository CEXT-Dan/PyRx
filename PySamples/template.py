#import 
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback


# called when the app is loaded
def OnPyInitApp():
    print("\nOnPyInitApp")


# called when the app is inloaded
def OnPyUnloadApp():
   print("\nOnPyUnloadApp")

# called when a drawing is opened
def OnPyLoadDwg():
   print("\nOnPyLoadDwg")

# called when a drawing is closed
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")
   
# prefix PyRxCmd_ defines a command
# CmdFlags is optional, default is modal
def PyRxCmd_mycommand(CmdFlags = Ap.CmdFlags.TRANSPARENT):
    try:
        print("Hello world!")
    except Exception as err:
        traceback.print_exception(err)

# prefix PyRxLisp_ defines a lisp function
# (mylisp '("hello world" 1 2 3 4 (1 10 100)))
def PyRxLisp_mylisp(args):
	try:
		return args
	except Exception as err:
		print(err)
