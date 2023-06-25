import os
import sys
import PyRxApp
import win32com.client
import pythoncom
from time import perf_counter

def OnPyInitApp():
	PyRxApp.Printf("\nOnPyInitApp")
	
def OnPyUnloadApp():
	PyRxApp.Printf("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
	PyRxApp.Printf("\nOnPyLoadDwg")
	
def OnPyUnloadDwg():
	PyRxApp.Printf("\nOnPyUnloadDwg")
	
def getApp():
	return win32com.client.GetActiveObject("BricscadApp.AcadApplication")
	
def	makeComPoint3d(x, y, z):
	return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, [x,y,z])
  
def makeComString(string) :
	return win32com.client.VARIANT(pythoncom.VT_BSTR, string)

def PyRxCmd_Comtest1():
	try:
		app = getApp()
		prompt = makeComString("\nGet Angle:")
		retAngle = app.ActiveDocument.Utility.GetAngle(pythoncom.Empty,prompt)
		PyRxApp.Printf(retAngle)
	except Exception as err:
		PyRxApp.Printf(err)
		
		
def PyRxCmd_Comtest2():
	try:
		app = getApp()
		pnt = makeComPoint3d(100, 100, 0)
		prompt = makeComString("\nGet Angle with base:")
		retAngle = app.ActiveDocument.Utility.GetAngle(pnt ,prompt)
		PyRxApp.Printf(retAngle)
	except Exception as err:
		PyRxApp.Printf(err)
		
def PyRxCmd_Comtest3():
	try:
		app = getApp()
		ms = app.ActiveDocument.ModelSpace
		
		t1_start = perf_counter()
		
		for i in range(10000):
			ms.AddLine(makeComPoint3d(0, 0, 0), makeComPoint3d(100, 100, 0))
			
		t1_stop = perf_counter()
		r = "Elapsed time: {t:.4f}".format(t = t1_stop-t1_start)
		PyRxApp.Printf(r)
	except Exception as err:
		PyRxApp.Printf(err)
