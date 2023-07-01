import os
import PyRxApp

def OnPyInitApp():
    print("\nOnPyInitApp")
	
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
    print("\nOnPyLoadDwg")
	
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")
         
def PyRxCmd_testfuncs():
	testFuncDoc()
	
def testFuncDoc():
	print(print.__doc__)
	print(PyRxApp.GetVar.__doc__)
	print(PyRxApp.SetVar.__doc__)

def PyRxCmd_testSetVar():
	try:
		PyRxApp.SetVar("OSMODE", 0)
		print(PyRxApp.GetVar("OSMODE"))
		PyRxApp.SetVar("OSMODE", 191)
		print(PyRxApp.GetVar("OSMODE"))
	except Exception as err:
		print(err)
	