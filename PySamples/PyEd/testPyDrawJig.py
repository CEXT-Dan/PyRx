import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx

print("command = pydrawjig")

class MyDrawJig(Ed.DrawJig):
    def __init__(self, basepoint):
        Ed.DrawJig.__init__(self)
        self.basepoint = basepoint
        self.curpoint = basepoint
        self.tri = [
            Ge.Point3d(-1, 0, 0),
            Ge.Point3d(1, 0, 0),
            Ge.Point3d(0, 1, 0),
            Ge.Point3d(-1, 0, 0),
        ]

    #get the mouse point, use base point or not
    def sampler(self):
        self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
        ds, self.curpoint = self.acquirePoint(self.basepoint)
        return ds

    def update(self):
        return True

    # draw anything you like, even your block, you can also scale or apply
    # color
    def worldDraw(self, wd: Gi.WorldDraw):
        try:
            mat = Ge.Matrix3d.translation(self.curpoint - self.basepoint)
            geo = wd.geometry()
            geo.pushModelTransform(mat)
            #draw tri as polyline
            geo.polyline(self.tri,Ge.Vector3d.kZAxis)
            geo.popModelTransform()
            return True
        except Exception as err:
            print(err)

def PyRxCmd_pydrawjig():
    try:
        jig = MyDrawJig(Ge.Point3d(0, 0, 0))
        jig.setDispPrompt("\nPick point:\n")
        res = jig.drag()
        print("done", res)
    except Exception as err:
        print(err)
