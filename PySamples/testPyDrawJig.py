import os

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor


print("command = pydrawjig")

# just like in ARX, ent must not be null


class DrawJig(PyEd.DrawJig):
    def __init__(self, basepoint):
        PyEd.DrawJig.__init__(self)
        self.curPoint = basepoint
        self.basepoint = basepoint

        self.line = PyDb.Line(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
        self.line.setDatabaseDefaults()

        self.circle = PyDb.Circle(PyGe.Point3d(
            50, 50, 0), PyGe.Vector3d.kZAxis, 10)
        self.circle.setDatabaseDefaults()

    def sampler(self):
        self.setUserInputControls
        (
            PyEd.UserInputControls(
                PyEd.UserInputControls.kAccept3dCoordinates |
                PyEd.UserInputControls.kNullResponseAccepted)
        )
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]

    # C++ update returns True is not overridden
    def update(self):
        mat = PyGe.Matrix3d.translation(PyGe.Point3d(0, 0, 0) - self.curPoint)
        self.line.transformBy(mat)
        self.circle.transformBy(mat)
        return True

    #worldDraw
    def worldDraw(self, wd):
        wd.draw(self.line)
        wd.draw(self.circle)
        return True


def PyRxCmd_pydrawjig():
    try:
        jig = DrawJig(PyGe.Point3d(0, 0, 0))
        jig.setDispPrompt("\nPick endPoint")
        if jig.drag() != PyEd.DragStatus.kNormal:
            print('oops')
            return

    except Exception as err:
        PyRxApp.Printf(err)
