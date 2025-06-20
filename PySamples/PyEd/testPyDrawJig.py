from pyrx import Ed, Ge, Gi

print("command = pydrawjig")


class MyDrawJig(Ed.DrawJig):
    def __init__(self, basepoint):
        Ed.DrawJig.__init__(self)
        self.ds = Ed.DragStatus.kNormal
        self.basepoint = basepoint
        self.curpoint = basepoint
        self.tri = [
            Ge.Point3d(-1, 0, 0),
            Ge.Point3d(1, 0, 0),
            Ge.Point3d(0, 1, 0),
            Ge.Point3d(-1, 0, 0),
        ]

    # get the mouse point, use base point or not
    def sampler(self):
        self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
        self.ds, self.curpoint = self.acquirePoint(self.basepoint)
        return self.ds

    def update(self):
        if self.ds == Ed.DragStatus.kNoChange:
            return False
        return True

    # draw anything you like, even your block, you can also scale or apply color
    def worldDraw(self, wd: Gi.WorldDraw):
        # always draws, do this if you want to skip
        if self.ds == Ed.DragStatus.kNoChange:
            return True
        try:
            mat = Ge.Matrix3d.translation(self.curpoint - self.basepoint)
            geo = wd.geometry()
            geo.pushModelTransform(mat)
            # draw tri as polyline
            geo.polyline(self.tri, Ge.Vector3d.kZAxis)
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
