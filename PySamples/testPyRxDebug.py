import traceback
from pyrx_imp import Rx, Ge, Gs, Gi, Db, Ap, Ed

#uncomment to set a break point manually
#import debugpy

print("added command = pystartdebug")
print("added command = pytestdebug")

def PyRxCmd_pystartdebug():
    import PyRxDebug
    PyRxDebug.startListener()
    
def PyRxCmd_pytestdebug():
    import PyRxDebug
    PyRxDebug.testListener()

def PyRxCmd_doit():
    try:
        #uncomment to set a break point manually
        #debugpy.breakpoint()
        
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId())

        mat = Ge.Matrix3d()
        mat.setToTranslation(Ge.Point3d(100, 100, 0).asVector())

        transformedPoints = [
            Db.Point(id, Db.OpenMode.kForWrite).transformBy(mat)
            for id in model.objectIds(Db.Point.desc())
        ]

    except Exception as err:
        traceback.print_exception(err)
