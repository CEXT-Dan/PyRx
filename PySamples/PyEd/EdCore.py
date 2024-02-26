from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

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

