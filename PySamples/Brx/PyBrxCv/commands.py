

from brxsdk.helper import debug, helper

#from pybrxcv.utils import cvdbalignment
from brxsdk.samples import alignmentsample, gradingsample, pointsample, surfacesample

print("added command - samp_createalignment")
print("added command - samp_alignmentreport")
print("added command - samp_gradingslopeoffset")
print("added command - samp_creategradingslopesurface")
print("added command = samp_tincreate")
print("added command = samp_tinlistdata")
print("added command = samp_tinaddbreakline")
print("added command = samp_tinaddboundary")
print("added command = samp_tinremovebreakline")
print("added command = samp_tinremoveboundary")
print("added command = samp_tinchangestyle")
print("added command = samp_tinmerge")
print("added command = samp_tinmesh")
print("added command - samp_pointworkflow")
print("added command - samp_pointgroupworkflow")

# On PYRELOAD reload all used custom modules
def OnPyReload() -> None:
    try:
        import importlib
        importlib.reload(helper)
        importlib.reload(debug)
        importlib.reload(alignmentsample)
        importlib.reload(gradingsample)
        importlib.reload(surfacesample)
        importlib.reload(pointsample)
        print("\nReloading all modules")
    except Exception as err:
        print(err)

def PyRxCmd_pydebug():
    try:
        debug.pydebug()
    except Exception as err:
        print(err)

# define a command
def PyRxCmd_samp_createalignment():
    try:
        alignmentsample.samp_createalignment()
    except Exception as err:
        print(err)

def PyRxCmd_samp_reportaligment():
    try:
        alignmentsample.samp_alignmentreport()
    except Exception as err:
        print(err)

def PyRxCmd_samp_gradingslopeoffset():
    try:
        gradingsample.samp_gradingslopeoffset()
    except Exception as err:
        print(err)

def PyRxCmd_samp_creategradingslopesurface():
    try:
        gradingsample.samp_creategradingslopesurface()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tincreate():
    try:
        surfacesample.samp_tincreate()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinlistall():
    try:
        surfacesample.samp_tinlistall()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinlistdata():
    try:
        surfacesample.samp_tinlistdata()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinaddbreakline():
    try:
        surfacesample.samp_tinaddbreakline()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinaddboundary():
    try:
        surfacesample.samp_tinaddboundary()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinremovebreakline():
    try:
        surfacesample.samp_tinremovebreakline()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinremoveboundary():
    try:
        surfacesample.samp_tinremoveboundary()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinchangestyle():
    try:
        surfacesample.samp_tinchangestyle()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinmerge():
    try:
        surfacesample.samp_tinmerge()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinmesh():
    try:
        surfacesample.samp_tinmesh()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tindrape():
    try:
        surfacesample.samp_tindrape()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinvolumesurface():
    # still having trouble here
    try:
        surfacesample.samp_tinvolumesurface()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinvolumesurfaceelevation():
    # still having trouble here
    try:
        surfacesample.samp_tinvolumesurfaceelevation()
    except Exception as err:
        print(err)

def PyRxCmd_samp_tinvolumesurfacebounded():
    # still having trouble here
    try:
        surfacesample.samp_tinvolumesurfacebounded()
    except Exception as err:
        print(err)

def PyRxCmd_samp_pointworkflow():
    try:
        pointsample.samp_pointworkflow()
    except Exception as err:
        print(err)

def PyRxCmd_samp_pointgroupworkflow():
    try:
        pointsample.samp_pointgroupworkflow()
    except Exception as err:
        print(err)

def PyRxCmd_pymodules():
    try:
        debug.reload_modules()
    except Exception as err:
        print(err)