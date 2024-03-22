from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
from pyrx_imp import Cv

import math

# assembling sample in the style of BRX SDK samples\CsBrxMgdCivil\CsBrxMgdCivil\GradingSample.cs
# only PyRxCmd_samp_gradingslopeoffset
# missing do_GradingSlopeSurfaceCreate, do_GradingParams, do_GradingSetRegion

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

def PyRxCmd_samp_gradingslopeoffset():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()
        # open modelspace for write
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)

        # create a 3d polyline as input object
        pline = Db.Polyline3d()
        pline.setDatabaseDefaults()
        pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(-5, -20, 1)))
        pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(5, -20, 1)))
        pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(5, 20, 1)))
        pline.appendVertex(Db.Polyline3dVertex(Ge.Point3d(-5, 20, 1)))
        pline.setClosed(False)
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
        except:
            print("Could not attach gradient object")

    except Exception as err:
        print(err)
