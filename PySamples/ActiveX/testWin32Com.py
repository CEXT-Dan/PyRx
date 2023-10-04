# import
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback
import win32com.client as com
import pythoncom
import ComAcadApplication24 as AcadApp

import AcadComTypes as Act


def PyRxCmd_doit():
    try:
        id =  AcadApp.AcadApplication.CLSID
        app: AcadApp.IAcadApplication = com.Dispatch(id)
        
        doc: AcadApp.IAcadDocument = app.ActiveDocument
        model: AcadApp.IAcadBlock = doc.ModelSpace
        util: AcadApp.IAcadUtility = doc.Utility

        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(100, 100, 0)

        model.AddLine(Act.comPt3d(pt1), Act.comPt3d(pt2))

        ent: AcadApp.IAcadEntity = util.GetEntity(
            None, None, "\nPick an ent: ")
        
        print(ent[0].ObjectName, ent[1])
        
        app.ZoomExtents()
        print(app.ListArx())

    except Exception as err:
        traceback.print_exception(err)
