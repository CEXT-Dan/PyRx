import os

import PyRxApp# = all the global methods like acutPrintf, 
import PyAp# = application, document classes services 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database

def OnPyLoadDwg():
	PyRxApp.Printf("\nOnPyLoadDwg")
	PyRxApp.Printf("\nrun pygetest :")

def PyRxCmd_pygetest():
	try:
		Point3dCtor()
		Point3dDistanceTo()
		Point3dTransformBy()
	except Exception as err:
		PyRxApp.Printf(err)
        
def Point3dCtor():
	try:
		o = PyGe.Point3d()
		if o.x == 0.0 and o.y == 0.0 and o.z == 0.0:
			PyRxApp.Printf("\nPASS({},{},{})".format(o.x, o.y, o.z))
		else:
			PyRxApp.Printf("\nFAIL({},{},{})".format(o.x, o.y, o.z))

		o = PyGe.Point3d.kOrigin
		if o.x == 0.0 and o.y == 0.0 and o.z == 0.0:
			PyRxApp.Printf("\nPASS({},{},{})".format(o.x, o.y, o.z))
		else:
			PyRxApp.Printf("\nFAIL({},{},{})".format(o.x, o.y, o.z))
			
		o = PyGe.Point3d(100,100,100)
		if o.x == 100.0 and o.y == 100.0 and o.z == 100.0:
			PyRxApp.Printf("\nPASS({},{},{})".format(o.x, o.y, o.z))
		else:
			PyRxApp.Printf("\nFAIL({},{},{})".format(o.x, o.y, o.z))
			
	except Exception as err:
		PyRxApp.Printf(err)
#
def Point3dDistanceTo():
	s = PyGe.Point3d()
#X
	e = PyGe.Point3d(100,0,0)
	ans = s.distanceTo(e)
	if ans == 100.0:
		PyRxApp.Printf("\nPASS({})".format(ans))
	else:
		PyRxApp.Printf("\nFAIL({})".format(ans))
#y
	s = PyGe.Point3d()
	e = PyGe.Point3d(0,100,0)
	ans = s.distanceTo(e)
	if ans == 100.0:
		PyRxApp.Printf("\nPASS({})".format(ans))
	else:
		PyRxApp.Printf("\nFAIL({})".format(ans))
#z
	s = PyGe.Point3d()
	e = PyGe.Point3d(0,0,100)
	ans = s.distanceTo(e)
	if ans == 100.0:
		PyRxApp.Printf("\nPASS({})".format(ans))
	else:
		PyRxApp.Printf("\nFAIL({})".format(ans))
#
def Point3dTransformBy():
	p = PyGe.Point3d(1,1,1)
	m = PyGe.Matrix3d()
	m.setToScaling(100.0, PyGe.Point3d.kOrigin)
	p.transformBy(m)
	if p.x == 100.0 and p.y == 100.0 and p.z == 100.0:
		PyRxApp.Printf("\nPASS({},{},{})".format(p.x, p.y, p.z))
	else:
		PyRxApp.Printf("\nFAIL({},{},{})".format(p.x, p.y, p.z))
