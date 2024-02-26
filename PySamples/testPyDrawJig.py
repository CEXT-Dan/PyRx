import os

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


print("command = pydrawjig")

# just like in ARX, ent must not be null
class MyDrawJig(Ed.DrawJig):
    def __init__(self, basepoint):
            Ed.DrawJig.__init__(self)
            self.curpoint = basepoint
            self.basepoint = basepoint
            self.lastpoint = basepoint
        
            self.line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
            self.line.setDatabaseDefaults()

            self.circle = Db.Circle(Ge.Point3d(50, 50, 0), Ge.Vector3d.kZAxis, 10)
            self.circle.setDatabaseDefaults()


    def sampler(self):
            self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
            point_result_tuple = self.acquirePoint()
            self.curpoint = point_result_tuple[1]
            
            if point_result_tuple[0] == Ed.DragStatus.kNormal:
                return Ed.DragStatus.kNoChange
            return point_result_tuple[0]

    # C++ update returns False is not overridden
    def update(self):
        try:
            self.lastpoint = self.curpoint
            return True
        except Exception as err:
            print(err)

    #worldDraw
    def worldDraw(self, wd : Gi.WorldDraw):
        try:
            mat = Ge.Matrix3d.translation(self.curpoint-self.basepoint)
            geo = wd.geometry()
            geo.pushModelTransform(mat)
            geo.draw(self.line)
            geo.draw(self.circle)
            geo.popModelTransform()
            return True
        except Exception as err:
            print(err)

def PyRxCmd_pydrawjig():
    try:
        jig = MyDrawJig(Ge.Point3d(0, 0, 0))
        jig.setDispPrompt("\nPick endPoint:\n")
        res = jig.drag()
        print("done", res)
    except Exception as err:
        print(err)
