import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

def PyRxCmd_pyofd():
  try:
    #acedGetFileD
    path = Ed.Core.getFileD("myfile.dwg", "", "dwg;eps;abc", 33)
    print(path)
  except Exception as err:
    print(err)

def PyRxCmd_pyofd2():
  try:
    #acedGetFileNavDialog
    paths = Ed.Core.getFileNavDialog("myfile.dwg","", "dwg;eps;abc","My File Dialog", 4096)
    print(paths)
  except Exception as err:
    print(err)

