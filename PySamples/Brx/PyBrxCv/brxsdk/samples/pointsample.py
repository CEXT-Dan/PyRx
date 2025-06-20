import math

from pyrx_imp import Cv, Db

# assembling sample in the style of BRX SDK samples\CsBrxMgdCivil\CsBrxMgdCivil\PointSample.cs

def samp_pointworkflow():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        # create a civil point as "firstpoint"
        cpoint = Cv.CvDbPoint()
        # print("Point number is 0 by default")
        cpoint.setDatabaseDefaults()
        cpoint.setEasting(-50)
        cpoint.setNorthing(-50)
        cpoint.setElevation(-50)
        cpoint.setName("firstpoint")
        model.appendAcDbEntity(cpoint)
        # print("Point number should be 1 here")

        # create a civil point as "point2"
        cpoint = Cv.CvDbPoint()
        # print("Point number is 0 by default")
        cpoint.setDatabaseDefaults()
        cpoint.setEasting(-60)
        cpoint.setNorthing(-60)
        cpoint.setElevation(-60)
        cpoint.setName("point2")
        model.appendAcDbEntity(cpoint)
        # print("Point number should be 2 here")
        
        for i in range(108):
            cpoint = Cv.CvDbPoint()
            cpoint.setDatabaseDefaults()
            cpoint.setNumber(i)
            cpoint.setEasting(-55 + math.cos(0.2*i)*i)
            cpoint.setNorthing(-55 + math.sin(0.2*i)*i)
            cpoint.setElevation(i)
            cpoint.setName("point" + str(i) + "D3")
            cpoint.addPersistentReactor
            model.appendAcDbEntity(cpoint)
            # print("Point number should be equal to i")

    except Exception as err:
        print(err)

def samp_pointgroupworkflow():
    try:
        # get the working database, database is also a property of Document
        db = Db.curDb()
        managerid = Cv.CvDbPointGroupManager.getManagerId(db) #returns an object id
        manager = Cv.CvDbPointGroupManager(managerid, Db.OpenMode.kForWrite) #open id for **write**
        print(manager.nextPointNumber())

        # creating new point group and setting group filters
        # point group object neeeds to be called with Db.OpenMode.kForWrite for writing
        groupNewId = manager.createPointGroup("NewPointGroup")
        print("added new point group")
        groupNew = Cv.CvDbPointGroup(groupNewId, Db.OpenMode.kForWrite)
        groupNew.setIncludeNumbers("1-200")
        print("added point group filter " + groupNew.includeNumbers())
        groupNew.setExcludeNumbers("1,2,>=100")
        print("added point group filter " + groupNew.excludeNumbers())
        groupNew.setExcludeNames("*point,point??2")
        print("added point group filter " + groupNew.excludeNames())

        # checking for point **symbol** style manager
        symbolStyleManagerId = Cv.CvDbStyleManager.getManager(db, Cv.StyleManagerType.eSymbolStyle)
        symbolStyleManager = Cv.CvDbStyleManager(symbolStyleManagerId) #open id for **read**
        print(symbolStyleManager.elementCount())
        
        # checking for point **label** style manager, don't know how to call between the different ones
        labelStyleManagerId = Cv.CvDbStyleManager.getManager(db, Cv.StyleManagerType.ePointLabel)
        labelStyleManager = Cv.CvDbStyleManager(labelStyleManagerId) #open id for **read**
        #print(labelStyleManager.name())
        print("Existing point label styles")
        for style in labelStyleManager.names():
            print(style)

        # creating point group and setting style
        groupBelow30ElevId = manager.createPointGroup("groupBelow30Elev")
        print("added new point group")
        groupBelow30Elev = Cv.CvDbPointGroup(groupBelow30ElevId, Db.OpenMode.kForWrite)
        groupBelow30Elev.setIncludeElevations("<30.0")
        print("added point group filter " + groupNew.includeElevations())

    except Exception as err:
        print(err)
