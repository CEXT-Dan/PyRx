# import
import traceback
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import AcadComTypes as acax
import ComAcadApplication24 as AcadApp
import win32com.client as com
from timeit import default_timer as timer


def getApp() -> AcadApp.IAcadApplication:
    id = AcadApp.AcadApplication.CLSID
    app: AcadApp.IAcadApplication = com.Dispatch(id)
    return app


def PyRxCmd_comAddLine():
    try:
        app = getApp()
        model: AcadApp.IAcadBlock = app.ActiveDocument.ModelSpace
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(100, 100, 0)
        model.AddLine(acax.comPnt3d(pt1), acax.comPnt3d(pt2))

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetEnt():
    try:
        app = getApp()
        doc: AcadApp.IAcadDocument = app.ActiveDocument
        util: AcadApp.IAcadUtility = doc.Utility

        ent: AcadApp.IAcadEntity = util.GetEntity(
            None, None, "\nPick an ent: ")

        print(ent[0].ObjectName, ent[1])
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetang():
    try:
        app = getApp()
        pt1 = Ge.Point3d(100, 100, 0)

        retAngle = app.ActiveDocument.Utility.GetAngle(
            acax.comPnt3d(pt1), "\nGet Angle with base:")

        print(retAngle)

    except Exception as err:
        traceback.print_exception(err)
        
#0.9682186000000002
def PyRxCmd_comPerf():
    try:
        start = timer()
        
        app = getApp()
        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100,100,0).asVector())
        
        comMat = acax.comMatrix3d(mat)

        model: AcadApp.IAcadBlock = app.ActiveDocument.ModelSpace

        for ent in model:
            if ent.ObjectName == "AcDbPoint":
                ent.TransformBy(comMat)
                
        end = timer()
        print(end - start)

    except Exception as err:
        traceback.print_exception(err)
