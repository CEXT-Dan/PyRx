import math
import traceback

from helper import valignmentblocks

from pyrx import Cv, Db, Ed, Ge

# scale for horizontal axis is usually 1:1
# scale for vertical axis is usually 1:5 / 1:10
# text height is set to 3.5u for larger labels
# text height is set to 2.5u for smaller labels
# band height is 20

# samples available under landxml.org
# 1: http://landxml.org/schema/LandXML-1.1/samples/TopoCAD/Surface%20and%20alignments.xml
# 2: http://landxml.org/schema/LandXML-1.1/samples/Autodesk%20Civil%203D%202007/pipeworks-1.1.xml
# 3: http://landxml.org/schema/LandXML-1.1/samples/Autodesk%20Civil%203D%202007/Corridor-6a.xml
# for further testing 1# has been chosen
# terms as per https://en.wikipedia.org/wiki/Geometric_design_of_roads

def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

drawProps = {'colorIndex': 255,'radius': 0.2, 'verticalTick': 2, 'horizontalTick': 100}

print("added command - cv_annotate_verticalview")

# On PYRELOAD reload all used custom modules
def OnPyReload() -> None:
    try:
        import importlib
        importlib.reload(valignmentblocks)
        print("\nReloading all modules")
    except Exception as err:
        print(err)   

def getIds(valign: Cv.CvDbVAlignment):
    try:
        ids = []
        elementId = valign.firstElementId()
        while elementId != 0:
            element = valign.elementAtId(elementId)
            if elementId != 0:
                ids.append(elementId)
            elementId = element.nextId()
        return ids
    except Exception as err:
        traceback.print_exception(err)

def getElementPoints(valign: Cv.CvDbVAlignment, spt: Ge.Point2d, ept: Ge.Point2d):
    try:
        coords = []
        sdist = valign.getDistAtPoint(Ge.Point3d(spt.x,spt.y,0))
        edist = valign.getDistAtPoint(Ge.Point3d(ept.x,ept.y,0))
        dist = sdist
        while dist < edist:
            pt = valign.getPointAtDist(dist)
            coords.append([pt.x, pt.y])
            dist += (edist-sdist)/100
        return coords
    except Exception as err:
        traceback.print_exception(err)

def getVMaxPoint(valign: Cv.CvDbVAlignment, spt: Ge.Point2d, ept: Ge.Point2d):
    try:
        no = 100 # split in 100 points for max-search
        coords = []
        sdist = valign.getParamAtPoint(Ge.Point3d(spt.x,spt.y,0))
        edist = valign.getParamAtPoint(Ge.Point3d(ept.x,ept.y,0))
        dist = sdist
        while dist < edist:
            pt = valign.getPointAtDist(dist)
            coords.append([pt.x, pt.y])
            dist += (edist-sdist)/no
        if len(coords) == 0:
            coords.append([spt.x,spt.y])
        x, ymax = max(coords, key=lambda x: (x[1]))
        return Ge.Point3d(x,ymax,0)
    except Exception as err:
        traceback.print_exception(err)

def getVMinPoint(valign: Cv.CvDbVAlignment, spt: Ge.Point2d, ept: Ge.Point2d):
    try:
        no = 100
        coords = []
        sdist = valign.getParamAtPoint(Ge.Point3d(spt.x,spt.y,0))
        edist = valign.getParamAtPoint(Ge.Point3d(ept.x,ept.y,0))
        dist = sdist
        while dist < edist:
            pt = valign.getPointAtDist(dist)
            coords.append([pt.x, pt.y])
            dist += (edist-sdist)/no
        x, ymax = min(coords, key=lambda x: (x[1]))
        return Ge.Point3d(x,ymax,0)
    except Exception as err:
        traceback.print_exception(err)

def getVMidPoint(valign: Cv.CvDbVAlignment, spt: Ge.Point2d, ept: Ge.Point2d):
    try:
        sdist = valign.getParamAtPoint(Ge.Point3d(spt.x,spt.y,0))
        edist = valign.getParamAtPoint(Ge.Point3d(ept.x,ept.y,0))
        pt = valign.getPointAtDist(((edist-sdist)/2)+sdist)
        return pt
    except Exception as err:
        traceback.print_exception(err)

def getHTickCount(valign: Cv.CvDbVAlignment):
    try:
        hid = valign.baseHAlignment()
        halign = Cv.CvDbHAlignment(hid)
        stequation = halign.stationEquations()
        fs = stequation.getStartingStation()
        rest = stequation.getRawStationFromLength(halign.length())
        ls = stequation.getStation(rest)
        dist = ls - fs
        ct = math.floor(dist / drawProps["horizontalTick"])
        xlabel = []
        for i in range(ct+1):
            xlabel.append(fs + i * drawProps["horizontalTick"])
        return(xlabel, ct)
    except Exception as err:
        traceback.print_exception(err)

def getVTickCount(valignv: Cv.CvDbVAlignmentView):
    try:
        bl = valignv.baseElevation()
        dist = valignv.height() / valignv.verticalScale()
        _tl = bl + dist
        ct = math.floor(dist / drawProps["verticalTick"])
        ylabel = []
        for i in range(ct+1):
            ylabel.append(bl + i * drawProps["verticalTick"])
        # print(bl, tl, ylabel)
        return(ylabel, ct)
    except Exception as err:
        traceback.print_exception(err)

def drawCrestGripLabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initCrestGradientBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawCrestPVILabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initCrestPVIBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawCrestPILabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initCrestMPBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawSagGripLabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initSagGradientBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawSagPVILabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initSagPVIBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawSagPILabel(db: Db.Database, group: Db.Group, origin: Ge.Point2d, anchor: Ge.Point3d):
    try:
        blkid = valignmentblocks.initSagMPBlock(db) # return objectid for block
        blockRef = Db.BlockReference(anchor, blkid) # create block reference
        line1 = Db.Line(Ge.Point3d(anchor.x, anchor.y, 0), Ge.Point3d(anchor.x, origin.y, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        model.addAnnoScalestoBlkRefs(True)
        id1 = model.appendAcDbEntity(line1)
        id2 = model.appendAcDbEntity(blockRef)
        blockRef.close() # closing reference
        line1.close() # closing line
        # append objectids to group
        group.append(id1)
        group.append(id2)
    except Exception as err:
        traceback.print_exception(err)

def drawXaxisLabel(db: Db.Database, group: Db.Group, pos: Ge.Point3d, att: float):
    try:
        blkid = valignmentblocks.initXaxisStationBlock(db) # return objectid for block
        blockRef = Db.BlockReference(pos, blkid) # create block reference
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(blockRef)
        blockrec = Db.BlockTableRecord(blkid)
        if blockrec.hasAttributeDefinitions():
            attdefids = blockrec.objectIds(Db.AttributeDefinition.desc())
            attdefs = [Db.AttributeDefinition(id) for id in attdefids]
            for attdef in attdefs:
                if attdef.isConstant():
                    continue
                attref = Db.AttributeReference()
                attref.setDatabaseDefaults(db)
                attref.setPropertiesFrom(attdef)
                attref.setInvisible(attdef.isInvisible())
                basePoint = attdef.position()
                basePoint += blockRef.position().asVector()
                attref.setPosition(basePoint)
                attref.setHeight(attdef.height())
                attref.setRotation(attdef.rotation())
                attref.setFieldLength(attdef.fieldLength())
                attref.setHorizontalMode(attdef.horizontalMode())
                attref.setVerticalMode(attdef.verticalMode())
                attref.setTag(attdef.tag())
                blockRef.appendAttribute(attref)
                attref.setTextString(str(att))
                blockRef.close() # closing reference
        blockRef.close() # closing reference
        group.append(id1) # append objectid to group
    except Exception as err:
        traceback.print_exception(err)

def drawYaxisLabel(db: Db.Database, group: Db.Group, pos: Ge.Point3d, att: float):
    try:
        blkid = valignmentblocks.initYaxisLevelBlock(db) # return objectid for block
        blockRef = Db.BlockReference(pos, blkid) # create block reference
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite) # open blocktable
        id1 = model.appendAcDbEntity(blockRef)
        blockrec = Db.BlockTableRecord(blkid)
        if blockrec.hasAttributeDefinitions():
            attdefids = blockrec.objectIds(Db.AttributeDefinition.desc())
            attdefs = [Db.AttributeDefinition(id) for id in attdefids]
            for attdef in attdefs:
                if attdef.isConstant():
                    continue
                attref = Db.AttributeReference()
                attref.setDatabaseDefaults(db)
                attref.setPropertiesFrom(attdef)
                attref.setInvisible(attdef.isInvisible())
                basePoint = attdef.position()
                basePoint += blockRef.position().asVector()
                attref.setPosition(basePoint)
                attref.setHeight(attdef.height())
                attref.setRotation(attdef.rotation())
                attref.setFieldLength(attdef.fieldLength())
                attref.setHorizontalMode(attdef.horizontalMode())
                attref.setVerticalMode(attdef.verticalMode())
                attref.setTag(attdef.tag())
                blockRef.appendAttribute(attref)
                attref.setTextString(str(att))
                blockRef.close() # closing reference
        blockRef.close() # closing reference
        group.append(id1) # append objectid to group
    except Exception as err:
        traceback.print_exception(err)

def annotateCrestCurve(db: Db.Database, group: Db.Group, curvedElement, verticalAlignment: Cv.CvDbVAlignment, verticalAlignmentView: Cv.CvDbVAlignmentView):
    try:
        #get significant points for curve
        sp2d = curvedElement.startPoint()
        ep2d = curvedElement.endPoint()
        pvi = verticalAlignment.pviAtCurve(curvedElement)
        vmax = getVMaxPoint(verticalAlignment, sp2d, ep2d) #get the vmax point
        vpi = pvi.location() #get the pi point
        # transform the point from local to WCS
        vmax.x = verticalAlignmentView.toWCSX(vmax.x)
        vmax.y = verticalAlignmentView.toWCSY(vmax.y)
        sp2d.x = verticalAlignmentView.toWCSX(sp2d.x)
        sp2d.y = verticalAlignmentView.toWCSY(sp2d.y)
        ep2d.x = verticalAlignmentView.toWCSX(ep2d.x)
        ep2d.y = verticalAlignmentView.toWCSY(ep2d.y)
        vpi.x = verticalAlignmentView.toWCSX(vpi.x)
        vpi.y = verticalAlignmentView.toWCSY(vpi.y)
        # draw labels
        drawCrestGripLabel(db, group, verticalAlignmentView.origin(), vmax) # draw crest
        drawCrestPVILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(sp2d.x, sp2d.y, 0)) # draw PC
        drawCrestPVILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(ep2d.x, ep2d.y, 0)) # draw PT
        drawCrestPILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(vpi.x, vpi.y, 0)) # draw PI
    except Exception as err:
        traceback.print_exception(err)

def annotateSagCurve(db: Db.Database, group: Db.Group, curvedElement, verticalAlignment: Cv.CvDbVAlignment, verticalAlignmentView: Cv.CvDbVAlignmentView):
    try:
        #get significant points for curve
        sp2d = curvedElement.startPoint()
        ep2d = curvedElement.endPoint()
        pvi = verticalAlignment.pviAtCurve(curvedElement)
        vmin = getVMinPoint(verticalAlignment, sp2d, ep2d) #get the vmax point
        vpi = pvi.location() #get the pi point
        # transform the point from local to WCS
        vmin.x = verticalAlignmentView.toWCSX(vmin.x)
        vmin.y = verticalAlignmentView.toWCSY(vmin.y)
        sp2d.x = verticalAlignmentView.toWCSX(sp2d.x)
        sp2d.y = verticalAlignmentView.toWCSY(sp2d.y)
        ep2d.x = verticalAlignmentView.toWCSX(ep2d.x)
        ep2d.y = verticalAlignmentView.toWCSY(ep2d.y)
        vpi.x = verticalAlignmentView.toWCSX(vpi.x)
        vpi.y = verticalAlignmentView.toWCSY(vpi.y)
        # draw labels
        drawSagGripLabel(db, group, verticalAlignmentView.origin(), vmin) # draw crest
        drawSagPVILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(sp2d.x, sp2d.y, 0)) # draw PC
        drawSagPVILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(ep2d.x, ep2d.y, 0)) # draw PT
        drawSagPILabel(db, group, verticalAlignmentView.origin(), Ge.Point3d(vpi.x, vpi.y, 0)) # draw PI
    except Exception as err:
        traceback.print_exception(err)

def annotateXAxis(db: Db.Database, group: Db.Group, valign: Cv.CvDbVAlignment, valignv: Cv.CvDbVAlignmentView):
    try:
        getHTickCount(valign)
        xlabel, ct = getHTickCount(valign)
        pos = Ge.Point2d()
        for i in range(ct+1):
            pos.x = valignv.toWCSX(xlabel[i])
            pos.y = valignv.toWCSY(0)
            drawXaxisLabel(db, group, Ge.Point3d(pos.x, pos.y, 0), xlabel[i])
    except Exception as err:
        traceback.print_exception(err)

def annotateYAxis(db: Db.Database, group: Db.Group, valignv: Cv.CvDbVAlignmentView):
    try:
        ylabel, ct = getVTickCount(valignv)
        pos = Ge.Point2d()
        for i in range(ct+1):
            pos.x = valignv.toWCSX(0)
            pos.y = valignv.toWCSY(ylabel[i])
            drawYaxisLabel(db, group, Ge.Point3d(pos.x, pos.y, 0), ylabel[i])
    except Exception as err:
        traceback.print_exception(err)

def PyRxCmd_cv_annotate_verticalview():
    try:
        #select the view, wee need this to transform
        vsel = Ed.Editor.entSel("\nSelect vertical alignment view: ", Cv.CvDbVAlignmentView.desc())
        if vsel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(vsel[0]))
        vAlignmentView = Cv.CvDbVAlignmentView(vsel[1], Db.OpenMode.kForRead)

        # select the vAlignment
        esel = Ed.Editor.entSel("\nSelect vertical alignment: ", Cv.CvDbVAlignment.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Oops {}: ".format(esel[0]))
        vAlignment = Cv.CvDbVAlignment(esel[1], Db.OpenMode.kForRead)

        # calling basics
        handle = str(vAlignmentView.getHandle()) + "_" + str(vAlignment.getHandle())
        db = Db.curDb()

        #check for existing group in the drawing and preparing
        groups = Db.Dictionary(db.groupDictionaryId(), Db.OpenMode.kForWrite)
        if groups.has(handle): # if handle exists delete group and all containing entities
            groupId = groups.getAt(handle)
            group =  Db.Group(groupId,Db.OpenMode.kForWrite)
            for id in group.allEntityIds():
                ent = Db.Entity(id,Db.OpenMode.kForWrite)
                ent.erase()
            group.erase()
        group = Db.Group("Annotation to " + str(handle), True) # create handle group and fill

        # looping through vertical alignment
        for id in getIds(vAlignment):
            element = vAlignment.elementAtId(id)
            # checking whether element is first/last and setting flag
            if element.previousId():
                _prevElement : Cv.CvDbVAlignmentElement = vAlignment.elementAtId(element.previousId())
            else:
                _prevElement = None
            if element.nextId():
                _nextElement : Cv.CvDbVAlignmentElement = vAlignment.elementAtId(element.nextId())
            else:
                _nextElement = None
            # annotate as per element type
            match element.type():
                case Cv.VAlignmentElementType.eTangent:
                    _tangent: Cv.CvDbVAlignmentTangent = Cv.CvDbVAlignmentTangent.cast(element) # tangent
                    print("I'm a tangent")
                case Cv.VAlignmentElementType.ePVI:
                    print("I'm a PVI")
                    _pvi: Cv.CvDbVAlignmentPVI = Cv.CvDbVAlignmentPVI.cast(element) # pvi
                case Cv.VAlignmentElementType.eArc:
                    print("I'm an arc")
                    arc: Cv.CvDbVAlignmentArc = Cv.CvDbVAlignmentArc.cast(element)
                    if arc.gradeIn() >= 0: #We'are risin
                        annotateCrestCurve(db, group, arc, vAlignment, vAlignmentView)
                        print("\nRising")
                    else:
                        annotateSagCurve(db, group, arc, vAlignment, vAlignmentView)
                        print("\nFalling")
                case Cv.VAlignmentElementType.eParabola:
                    print("I'm a parabola")
                    parabola: Cv.CvDbVAlignmentParabola = Cv.CvDbVAlignmentParabola.cast(element)
                    if parabola.gradeIn() >= 0: #We'are risin
                        annotateCrestCurve(db, group, parabola, vAlignment, vAlignmentView)
                        print("\nRising")
                    else:
                        annotateSagCurve(db, group, parabola, vAlignment, vAlignmentView)
                        print("\nFalling")
                case Cv.VAlignmentElementType.eUndefined:
                    print("I'm a undefined")

        annotateXAxis(db, group, vAlignment, vAlignmentView) # drawing yaxis ticks
        annotateYAxis(db, group, vAlignmentView) # drawing yaxis ticks

        # set group content
        groups.setAt(handle,group)
        groups.close()
        group.close()

    except Exception as err:
        traceback.print_exception(err)
