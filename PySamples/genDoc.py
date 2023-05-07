import os
import inspect

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

#just some ideas on getting help, work in progress
def PyRxCmd_pydoit():
    try:
        module = inspect.getmodule(PyGe)
        for members_1 in inspect.getmembers(module):
            PyRxApp.Printf("\n{}".format(members_1[0]))
    except Exception as err:
        PyRxApp.Printf(err)
        
def PyRxCmd_pydoit2():
    try:
        members = inspect.getmembers(PyGe.Curve2d)
        for x in members:
              PyRxApp.Printf("\n{} ".format(x[0]))       
    except Exception as err:
        PyRxApp.Printf(err)
        
def PyRxCmd_pydoit3():
    try:
        PyRxApp.Printf(PyGe.Curve2d.__doc__)   
    except Exception as err:
        PyRxApp.Printf(err)
        
def PyRxCmd_pydoit4():
    try:    
        members = inspect.getmembers(PyEd.DragStatus)
        for member in members:
            if not member[0].startswith("__"):
                PyRxApp.Printf("\n{}, {}".format(member[0],member[1].__doc__))       
    except Exception as err:
        PyRxApp.Printf(err)

def PyRxCmd_pydoit5():
    try:
        module = inspect.getmodule(PyDb);
        for members_1 in inspect.getmembers(module):
            PyRxApp.Printf("\n{}\n".format(members_1[0]))
            if inspect.isclass(members_1[1]):
                members_2 = inspect.getmembers(members_1[1])
                for x in members_2:
                    if not x[0].startswith("__"):
                        PyRxApp.Printf("{} ".format(x[1].__doc__))  
    except Exception as err:
        PyRxApp.Printf(err)
        
def PyRxCmd_pydoit6():
    try:
       print(dir(PyDb))
    except Exception as err:
        PyRxApp.Printf(err)