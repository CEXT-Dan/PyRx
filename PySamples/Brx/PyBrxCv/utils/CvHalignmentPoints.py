import math
import traceback

from pyrx import Cv, Db, Ed


def getHTickCount(halign: Cv.CvDbHAlignment, tick: float):
    try:
        stequation = halign.stationEquations()
        fs = stequation.getStartingStation()
        rest = stequation.getRawStationFromLength(halign.length())
        ls = stequation.getStation(rest)
        dist = ls - fs
        ct = math.floor(dist / tick)
        xylabel = []
        for i in range(ct+1):
            xylabel.append(fs + i * tick)
        return(xylabel, ct)
    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_cvhalignmentpoints():
    try:
        # select entity
        esel = Ed.Editor.entSel("\nSelect Horizontal Alignment: ", Cv.CvDbHAlignment.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Not a Horizontal Alignment{}: ".format(esel[0])) 
            return
        
        # get distance as positive float
        while True:
            ssResult = Ed.Editor.getDouble("\nEnter distance interval:")
            if ssResult[0] == Ed.PromptStatus.eNormal : 
                if ssResult[1] > 0 :
                    break
                print("\nEnter a positive value")
        distLabel = ssResult[1]

        # do general stuff
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        # fetching basic alignment info and tick list
        halign = Cv.CvDbHAlignment(esel[1], Db.OpenMode.kForRead)
        xylabel, ct = getHTickCount(halign, distLabel)
        _handle = halign.getHandle()
        name = halign.name()

        # generating point list
        coordlabel = []
        for label in xylabel:
            coordlabel.append([label, halign.getPointAtDist(label)]) 

        # generating cogo points
        for cl in coordlabel:
            cpoint = Cv.CvDbPoint()
            cpoint.setDatabaseDefaults()
            cpoint.setEasting(cl[1].x)
            cpoint.setNorthing(cl[1].y)
            cpoint.setElevation(cl[1].z)
            cname = cpoint.name()
            cname = name + "_" + cname
            cpoint.setName(cname)
            cpoint.addPersistentReactor
            model.appendAcDbEntity(cpoint)            

        # check for point group and include names
        managerid = Cv.CvDbPointGroupManager.getManagerId(db) #returns an object id
        manager = Cv.CvDbPointGroupManager(managerid, Db.OpenMode.kForWrite) #open id for **write**
        groupId = manager.createPointGroup(str(name) + "_" + str(distLabel))
        group = Cv.CvDbPointGroup(groupId, Db.OpenMode.kForWrite)
        group.setIncludeNames(name + "*")

    except Exception as err:
        traceback.print_exception(err)
