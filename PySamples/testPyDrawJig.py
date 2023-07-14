import os

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
            PyEd.DrawJig.__init__(self)
            self.curpoint = basepoint
            self.basepoint = basepoint
            self.lastpoint = basepoint
        
            self.line = PyDb.Line(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
            self.line.setDatabaseDefaults()

            self.circle = PyDb.Circle(PyGe.Point3d(50, 50, 0), PyGe.Vector3d.kZAxis, 10)
            self.circle.setDatabaseDefaults()


    def sampler(self):
            self.setUserInputControls(PyEd.UserInputControls.kAccept3dCoordinates)
            point_result_tuple = self.acquirePoint()
            self.curpoint = point_result_tuple[1]
            
            if point_result_tuple[0] == PyEd.DragStatus.kNormal:
                return PyEd.DragStatus.kNoChange
            return point_result_tuple[0]

    # C++ update returns False is not overridden
    def update(self):
        try:
            self.lastpoint = self.curpoint
            return True
        except Exception as err:
            print(err)

    #worldDraw
    def worldDraw(self, wd):
        try:
            mat = PyGe.Matrix3d.translation(self.curpoint-self.basepoint)
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
        jig = MyDrawJig(PyGe.Point3d(0, 0, 0))
        jig.setDispPrompt("\nPick endPoint:\n")
        res = jig.drag()
        print("done", res)
    except Exception as err:
        print(err)
