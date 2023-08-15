import sys
import os
import PyRx
import win32com.client
import pythoncom
from time import perf_counter

def OnPyInitApp():
	print("\nOnPyInitApp")
	
def OnPyUnloadApp():
	print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
	print("\nOnPyLoadDwg")
	
def OnPyUnloadDwg():
	print("\nOnPyUnloadDwg")
	
def getApp():
	return win32com.client.GetActiveObject("AutoCAD.Application")
	
def	makeComPoint3d(x, y, z):
	return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, [x,y,z])
  
def makeComString(string) :
	return win32com.client.VARIANT(pythoncom.VT_BSTR, string)

def PyRxCmd_Comtest1():
	try:
		app = getApp()
		prompt = makeComString("\nGet Angle:")
		retAngle = app.ActiveDocument.Utility.GetAngle(pythoncom.Empty,prompt)
		print(retAngle)
	except Exception as err:
		print(err)
			
def PyRxCmd_Comtest2():
	try:
		app = getApp()
		pnt = makeComPoint3d(100, 100, 0)
		prompt = makeComString("\nGet Angle with base:")
		retAngle = app.ActiveDocument.Utility.GetAngle(pnt ,prompt)
		print(retAngle)
	except Exception as err:
		print(err)
		
def PyRxCmd_Comtest3():
	try:
		app = getApp()
		ms = app.ActiveDocument.ModelSpace
		
		t1_start = perf_counter()
		
		for i in range(10000):
			ms.AddLine(makeComPoint3d(0, 0, 0), makeComPoint3d(100, 100, 0))
			
		t1_stop = perf_counter()
		r = "Elapsed time: {t:.4f}".format(t = t1_stop-t1_start)
		print(r)
	except Exception as err:
		print(err)
  


		
		

