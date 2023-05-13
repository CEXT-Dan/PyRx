import os

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

print("command = pyjigstyle")
print("command = pyjig")

# just like in ARX, ent must not be null


class MyJig(PyEd.Jig):
    def __init__(self, line, basepoint):
        PyEd.Jig.__init__(self, line)
        self.line = line
        self.curPoint = basepoint

    # C++ sampler returns AcEdJig::DragStatus::kNoChange if not overridden
    # acquireXXX returns a tuple AcEdJig::DragStatus and Value
    def sampler(self):
        self.setUserInputControls
        (
           PyEd.Jig.UserInputControls(
              PyEd.Jig.UserInputControls.kAccept3dCoordinates | PyEd.Jig.UserInputControls.kNullResponseAccepted)
        )
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]

    # C++ update returns True is not overridden
    def update(self):
        self.line.setEndPoint(self.curPoint)
        return True


def PyRxCmd_pyjigstyle():
    try:
        doc = PyAp.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        # create a style
        style = PyEd.DragStyle()
        style.setStyleTypeForDragged(PyEd.DragStyleType.kTransparent75)

        point_result_tuple = ed.getPoint("\nPick startPoint")
        if point_result_tuple[0] != PyEd.PromptStatus.eNormal:
            print('oops')
            return

        model = PyDb.BlockTableRecord(
            db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        line = PyDb.Line(point_result_tuple[1], point_result_tuple[1])
        line.setDatabaseDefaults()

        jig = MyJig(line, point_result_tuple[1])
        jig.setDispPrompt("\nPick endPoint")

        # use the style overload
        if jig.drag(style) != PyEd.Jig.DragStatus.kNormal:
            print('oops')
            return

        line.setEndPoint(jig.curPoint)
        model.appendAcDbEntity(line)

    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pyjig():
    try:
        doc = PyAp.docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        point_result_tuple = ed.getPoint("\nPick startPoint")
        if point_result_tuple[0] != PyEd.PromptStatus.eNormal:
            print('oops')
            return

        model = PyDb.BlockTableRecord(
            db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        line = PyDb.Line(point_result_tuple[1], point_result_tuple[1])
        line.setDatabaseDefaults()

        jig = MyJig(line, point_result_tuple[1])
        jig.setDispPrompt("\nPick endPoint")
        if jig.drag() != PyEd.Jig.DragStatus.kNormal:
            print('oops')
            return

        line.setEndPoint(jig.curPoint)
        model.appendAcDbEntity(line)

    except Exception as err:
        PyRxApp.Printf(err)
