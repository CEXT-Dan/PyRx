import os
import PyRxApp

def OnPyInitApp():
    PyRxApp.Printf("\nOnPyInitApp")
	
def OnPyUnloadApp():
    PyRxApp.Printf("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
    PyRxApp.Printf("\nOnPyLoadDwg")
	
def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")
         
def PyRxAppCmd_testfuncs():
	testFuncDoc()
	
def testFuncDoc():
	PyRxApp.Printf(PyRxApp.Printf.__doc__)
	PyRxApp.Printf(PyRxApp.GetVar.__doc__)
	PyRxApp.Printf(PyRxApp.SetVar.__doc__)

def PyRxAppCmd_testSetVar():
	try:
		PyRxApp.SetVar("OSMODE", 0)
		PyRxApp.Printf(PyRxApp.GetVar("OSMODE"))
		PyRxApp.SetVar("OSMODE", 191)
		PyRxApp.Printf(PyRxApp.GetVar("OSMODE"))
	except Exception as err:
		PyRxApp.Printf(err)
	