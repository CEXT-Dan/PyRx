import math
import traceback

from pyrx_imp import Cv, Db

from ..helper import helper

# assembling sample in the style of BRX SDK samples\CsBrxMgdCivil\CsBrxMgdCivil\GradingSample.cs
# only PyRxCmd_samp_gradingslopeoffset, PyRxCmd_samp_gradingslopesurfacecreate
# missing do_GradingParams, do_GradingSetRegion

def samp_gradingslopeoffset():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()
        # open modelspace for write
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)

        # create a 3d polyline as input object
        pline = helper.create3dPolyline()
        model.appendAcDbEntity(pline) # push entity before grading

        # set a color
        color = Db.Color()
        color.setRGB(255, 255, 0)
        pline.setColor(color)

        # Creating grading object and feeding
        grading = Cv.CvDbGrading()
        try:
            grading.setInputDataId(pline.objectId())
            rule = Cv.CvGradingSlopeOffsetRule()
            rule.setSlope(math.radians(45.3)) # convert deg to rad
            rule.setOffset(1.7) 
            rule.setSide(Cv.GradingSide.eGradingSideRight) # which is right?
            grading.setRule(rule)
            model.appendAcDbEntity(grading)
        except Exception as e:
            print("Could not attach gradient object",e)

    except Exception as err:
        traceback.print_exception(err)

def samp_creategradingslopesurface():
    try:
        # get the working database
        db = Db.curDb()
        
        # create sample surface and add
        surface = helper.createSampleTinSurface()
        surfaceId = db.addToModelspace(surface)

        # create sample polyline and add        
        polyline = helper.create3dPolyline()
        polylineId = db.addToModelspace(polyline)
        
        # create grading object and set input
        grading = Cv.CvDbGrading()
        stat = grading.setInputDataId(polylineId)
        print("\nstatus = {}: ".format(stat))
        
        # prepare cut/fill slopes in degrees
        cutSlope = math.radians(77.0)
        fillSlope = math.radians(33.0)
        
        # prepare grading rule
        rule = Cv.CvGradingSlopeSurfaceRule(surfaceId,cutSlope,fillSlope)
        rule.setSide(Cv.GradingSide.eGradingSideRight)
        
        # apply grading rule and update
        stat = grading.setRule(rule)
        print("\nstatus = {}: ".format(stat))
        stat = grading.update(True)
        print("\nstatus = {}: ".format(stat))
        
        _gradingId = db.addToModelspace(grading)
        
    except Exception as err:
        traceback.print_exception(err)