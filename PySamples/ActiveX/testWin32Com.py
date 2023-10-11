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

import traceback
from timeit import default_timer as timer


# optional, global instance of IAcadApplication
# there's only one app, might as well cache it
theApp = Ax.getApp()

def PyRxCmd_sstestx():
    try:

        doc = theApp.ActiveDocument
        ss = doc.SelectionSets.Add('mysset')

        #safe arrays
        ss.SelectOnScreen([0],["POINT"])

        # COM returns a tuple (ent, point)
        entres = doc.Utility.GetEntity("\nPick an ent: ")
        
        #ass to the set
        entstoadd = [entres[0]]
        ss.AddItems(entstoadd)

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

def PyRxCmd_AddPolylineX():
    try:
        model: Ax.IAcadBlock = theApp.ActiveDocument.ModelSpace
        line = model.AddLightWeightPolyline([0,0,10,10,20,10])

        clr: Ax.IAcadAcCmColor = Ax.AcadAcCmColor()
        clr.SetRGB(255, 255, 0)
        line.TrueColor = clr

        # convert to PyRx
        newId = Db.ObjectId()
        newId.setFromOldId(line.ObjectID)

        rxLine = Db.Polyline(newId)
        print(rxLine.toList())

    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_AddLineX():
    try:
        model: Ax.IAcadBlock = theApp.ActiveDocument.ModelSpace
        line = model.AddLine((0, 0, 0),(100, 100, 0))

        clr: Ax.IAcadAcCmColor = Ax.AcadAcCmColor()
        clr.SetRGB(255, 255, 0)
        line.TrueColor = clr

        # convert to PyRx
        newId = Db.ObjectId()
        newId.setFromOldId(line.ObjectID)

        rxLine = Db.Line(newId)
        print(rxLine.startPoint(), rxLine.endPoint())

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_MenuGroupsX():
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


def PyRxCmd_GetEntX():
    try:
        doc: Ax.IAcadDocument = theApp.ActiveDocument
        util: Ax.IAcadUtility = doc.Utility
        ent: Ax.IAcadEntity = util.GetEntity("\nPick an ent: ")
        print(ent[0].ObjectName, ent[1])
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_getangx():
    try:
        ut = theApp.ActiveDocument.Utility
        pt1 = Ge.Point3d(100, 100, 0)
        retAngle = ut.GetAngle(pt1.toList(), "\nGet Angle with base:")
        print(retAngle)
    except Exception as err:
        traceback.print_exception(err)
        
def PyRxCmd_getpointwithbasex():
    try:
        ut = theApp.ActiveDocument.Utility
        pt1 = Ge.Point3d(100, 100, 0)
        retAngle = ut.GetPointWithBase(pt1.toList(), "\nGet Point with base:")
        print(retAngle)
    except Exception as err:
        traceback.print_exception(err)
        
def PyRxCmd_getpointx():
    try:
        ut = theApp.ActiveDocument.Utility
        retAngle = ut.GetPoint("\nGet point:")
        print(retAngle)
    except Exception as err:
        traceback.print_exception(err)
        
def PyRxCmd_layerStateX():
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
        coords = mat.toList()

        for ent in theApp.ActiveDocument.ModelSpace:
            if ent.ObjectName == "AcDbPoint":
                ent.TransformBy(coords)

        end = timer()
        print(end - start)

    except Exception as err:
        traceback.print_exception(err)
        
        
        #ActiveX
def PyRxCmd_moveToOriginX():
    try:
        dbx = Ax.getDbx()
        dbx.Open("e:\\06457Submittal.dwg")
        minpt = [float('inf'), float('inf'), float('inf')]
        
        ents = []
        ent: Ax.IAcadEntity
        for ent in dbx.ModelSpace:
            try:
                ents.append(ent)
                minmax = ent.GetBoundingBox()
                minpt[0] = min(minmax[0][0], minpt[0])
                minpt[1] = min(minmax[0][1], minpt[1])
                minpt[2] = min(minmax[0][2], minpt[2])
            except:# 'Null extents'
                continue
            
        for ent in ents:
            ent.Move(minpt,  (0, 0, 0))
            
        dbx.SaveAs("e:\\06457Submittal2.dwg")
    except Exception as err:
        traceback.print_exception(err)
