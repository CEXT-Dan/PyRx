import os

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("command = pyjigstyle")
print("command = pyjig")

# just like in ARX, ent must not be null


class MyJig(Ed.Jig):
    def __init__(self, line, basepoint):
        Ed.Jig.__init__(self, line)
        self.line = line
        self.curPoint = basepoint

    # acquireXXX returns a tuple AcEdJig::DragStatus and Value
    def sampler(self):
        self.setUserInputControls
        (
           Ed.UserInputControls(
              Ed.UserInputControls.kAccept3dCoordinates | 
              Ed.UserInputControls.kNullResponseAccepted)
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
        doc = Ap.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        # create a style
        style = Ed.DragStyle()
        style.setStyleTypeForDragged(Ed.DragStyleType.kTransparent75)

        point_result_tuple = ed.getPoint("\nPick startPoint")
        if point_result_tuple[0] != PyEd.PromptStatus.eNormal:
            print('oops')
            return

        model = Db.BlockTableRecord(
            db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(point_result_tuple[1], point_result_tuple[1])
        line.setDatabaseDefaults()

        jig = MyJig(line, point_result_tuple[1])
        jig.setDispPrompt("\nPick endPoint")

        # use the style overload
        if jig.drag(style) != Ed.DragStatus.kNormal:
            print('oops')
            return

        line.setEndPoint(jig.curPoint)
        model.appendAcDbEntity(line)

    except Exception as err:
        print(err)


def PyRxCmd_pyjig():
    try:
        doc = Ap.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        point_result_tuple = ed.getPoint("\nPick startPoint")
        if point_result_tuple[0] != Ed.PromptStatus.eNormal:
            print('oops')
            return

        model = Db.BlockTableRecord(
            db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(point_result_tuple[1], point_result_tuple[1])
        line.setDatabaseDefaults()

        jig = MyJig(line, point_result_tuple[1])
        jig.setDispPrompt("\nPick endPoint")
        if jig.drag() != Ed.DragStatus.kNormal:
            print('oops')
            return

        line.setEndPoint(jig.curPoint)
        model.appendAcDbEntity(line)

    except Exception as err:
        print(err)
