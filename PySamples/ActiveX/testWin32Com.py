# import

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

# these are in the stub file
# requires win32com
import win32com.client
import AcadComTypes24 as Ac
import ComAcadApplication24 as AcadApp

import traceback
from timeit import default_timer as timer


# optional, global instance of IAcadApplication
# there's only one app, might as well cache it
theApp = Ac.getApp()


def PyRxCmd_comAddLine():
    try:
        model: AcadApp.IAcadBlock = theApp.ActiveDocument.ModelSpace
        line: AcadApp.IAcadLine = model.AddLine(
            Ac.comPnt3d(Ge.Point3d(0, 0, 0)),
            Ac.comPnt3d(Ge.Point3d(100, 100, 0)))

        clr: AcadApp.IAcadAcCmColor = AcadApp.AcadAcCmColor()
        clr.SetRGB(255, 255, 0)
        line.TrueColor = clr

        # convert to a wrapper
        newId = Db.ObjectId()
        newId.setFromOldId(line.ObjectID)

        rxLine = Db.Line(newId)
        print(rxLine.startPoint(), rxLine.endPoint())

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comMenuGroups():
    try:
        menuGroups: AcadApp.IAcadMenuGroups = theApp.MenuGroups
        print("Menu.Count",  menuGroups.Count)

        menuGroup: AcadApp.IAcadMenuGroup = menuGroups.Item(0)
        pops: AcadApp.IAcadPopupMenus = menuGroup.Menus

        for i in range(pops.Count):
            pop: AcadApp.IAcadPopupMenu = pops.Item(i)
            print(pop.Name)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetEnt():
    try:
        doc: AcadApp.IAcadDocument = theApp.ActiveDocument
        util: AcadApp.IAcadUtility = doc.Utility

        ent: AcadApp.IAcadEntity = util.GetEntity(
            None, None, "\nPick an ent: ")

        print(ent[0].ObjectName, ent[1])
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetang():
    try:
        pt1 = Ge.Point3d(100, 100, 0)

        retAngle = theApp.ActiveDocument.Utility.GetAngle(
            Ac.comPnt3d(pt1), "\nGet Angle with base:")

        print(retAngle)

    except Exception as err:
        traceback.print_exception(err)

# 0.9011179999997694!
def PyRxCmd_comPerf():
    try:
        start = timer()

        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
        comMat = Ac.comMatrix3d(mat)

        for ent in theApp.ActiveDocument.ModelSpace:
            if ent.ObjectName == "AcDbPoint":
                ent.TransformBy(comMat)

        end = timer()
        print(end - start)

    except Exception as err:
        traceback.print_exception(err)
