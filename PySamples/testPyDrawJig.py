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


class MyDrawJig(PyEd.DrawJig):
    def __init__(self, basepoint):
        try:
            PyEd.DrawJig.__init__(self)
            self.curpoint = basepoint
            self.basepoint = basepoint
            self.lastpoint = basepoint
        
            self.line = PyDb.Line(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
            self.line.setDatabaseDefaults()

            self.circle = PyDb.Circle(PyGe.Point3d(50, 50, 0), PyGe.Vector3d.kZAxis, 10)
            self.circle.setDatabaseDefaults()
        except Exception as err:
            print(err)

    def sampler(self):
        try:
            self.setUserInputControls
            (
                PyEd.UserInputControls(
                PyEd.UserInputControls.kAccept3dCoordinates |
                PyEd.UserInputControls.kNullResponseAccepted)
            )
            point_result_tuple = self.acquirePoint(self.curpoint)
            self.curpoint = point_result_tuple[1]
            return point_result_tuple[0]
        except Exception as err:
            print(err)

    # C++ update returns True is not overridden
    def update(self):
        try:
            if self.lastpoint == self.curpoint:
                return False
            self.lastpoint = self.curpoint
            return True
        except Exception as err:
            print(err)

    #worldDraw
    def worldDraw(self, wd):
        try:
            mat = PyGe.Matrix3d.translation(self.curpoint-self.basepoint)
            geo = wd.worldGeometry()
            geo.pushModelTransform(mat)
            geo.draw(self.line)
            geo.draw(self.circle)
            geo.popModelTransform()
            return True
        except Exception as err:
            print(err)

def PyRxCmd_pydrawjig():
    try:
        jig = MyDrawJig(PyGe.Point3d(0, 0, 0))
        jig.setDispPrompt("\nPick endPoint")
        if jig.drag() != PyEd.DragStatus.kNormal:
            print('oops')
            return

    except Exception as err:
        PyRxApp.Printf(err)
