# import

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

# these are in the stub file
# requires win32com
import AxApp24 as Ax
import AxAppUtils24 as Axu

import traceback
from timeit import default_timer as timer


# optional, global instance of IAcadApplication
# there's only one app, might as well cache it
theApp = Axu.getApp()

def PyRxCmd_sstest1():
    try:

        doc = theApp.ActiveDocument
        ss = doc.SelectionSets.Add('mysset')

        #safe arrays
        ss.SelectOnScreen(Axu.ssfilterType([0]),
                          Axu.ssfilterData(["POINT"]))

        # COM returns a tuple (ent, point)
        entres = doc.Utility.GetEntity(None, None, "\nPick an ent: ")
        
        #ass to the set
        entstoadd = [entres[0]]
        ss.AddItems(Axu.entlist(entstoadd))

        # for loop
        print('\nway 1')
        for e in ss:
            p = Ax.IAcadPoint(e)
            print(p.Coordinates)

        # sdded array ss[ids]
        print('\nway 2')
        for i in range(ss.Count):
            print(ss[i].ObjectName)

        # added array Item(idx)
        print('\nway 3')
        for i in range(ss.Count):
            print(ss.Item(i).ObjectName)

    except Exception as err:
        traceback.print_exception(err)
    finally:
        ss.Delete()


def PyRxCmd_comAddLine():
    try:
        model: Ax.IAcadBlock = theApp.ActiveDocument.ModelSpace
        line: Ax.IAcadLine = model.AddLine(
            Axu.pnt3d(Ge.Point3d(0, 0, 0)),
            Axu.pnt3d(Ge.Point3d(100, 100, 0)))

        clr: Ax.IAcadAcCmColor = Ax.AcadAcCmColor()
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
        menuGroups: Ax.IAcadMenuGroups = theApp.MenuGroups
        print("Menu.Count",  menuGroups.Count)

        menuGroup: Ax.IAcadMenuGroup = menuGroups.Item(0)
        pops: Ax.IAcadPopupMenus = menuGroup.Menus

        for i in range(pops.Count):
            pop: Ax.IAcadPopupMenu = pops.Item(i)
            print(pop.Name)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetEnt():
    try:
        doc: Ax.IAcadDocument = theApp.ActiveDocument
        util: Ax.IAcadUtility = doc.Utility

        ent: Ax.IAcadEntity = util.GetEntity(
            None, None, "\nPick an ent: ")

        print(ent[0].ObjectName, ent[1])
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_comGetang():
    try:
        pt1 = Ge.Point3d(100, 100, 0)

        retAngle = theApp.ActiveDocument.Utility.GetAngle(
            Axu.pnt3d(pt1), "\nGet Angle with base:")

        print(retAngle)

    except Exception as err:
        traceback.print_exception(err)
        
def PyRxCmd_comLayerState():
    try:
        state : Ax.IAcadLayerStateManager = Ax.AcadLayerStateManager()
        state.SetDatabase(theApp.ActiveDocument.Database)
        state.Export('WOOHOOSTATE','e:\\temp\\WOOHOOSTATE.txt')
    except Exception as err:
        traceback.print_exception(err)

# 0.9011179999997694!
def PyRxCmd_comPerf():
    try:
        start = timer()

        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())
        comMat = Axu.matrix3d(mat)

        for ent in theApp.ActiveDocument.ModelSpace:
            if ent.ObjectName == "AcDbPoint":
                ent.TransformBy(comMat)

        end = timer()
        print(end - start)

    except Exception as err:
        traceback.print_exception(err)
