from pyrx_imp import Ap, Db, Ed

print("command = pyjigstyle")
print("command = pyjig")


class MyJig(Ed.Jig):
    def __init__(self, line, basepoint):
        Ed.Jig.__init__(self, line)
        self.line = line
        self.lastPoint = basepoint
        self.curPoint = basepoint

    def sampler(self):
        self.setUserInputControls(
            Ed.UserInputControls(
                Ed.UserInputControls.kAccept3dCoordinates
                | Ed.UserInputControls.kNullResponseAccepted
            )
        )

        ds, self.curPoint = self.acquirePoint(self.lastPoint)

        if self.curPoint.distanceTo(self.lastPoint) < 1:
            return Ed.DragStatus.kNoChange
        self.line.setEndPoint(self.curPoint)
        self.lastPoint = self.curPoint
        return ds

    def update(self):
        return True


def PyRxCmd_pyjigstyle():
    try:
        doc = Ap.Application().docManager().curDocument()
        db = doc.database()
        ed = doc.editor()

        # create a style
        style = Ed.DragStyle()
        style.setStyleTypeForDragged(Ed.DragStyleType.kTransparent75)

        ps, pnt = ed.getPoint("\nPick startPoint")
        if ps != Ed.PromptStatus.eNormal:
            print("oops")
            return

        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(pnt, pnt)
        line.setDatabaseDefaults()

        jig = MyJig(line, pnt)
        jig.setDispPrompt("\nPick endPoint")

        # use the style overload
        if jig.drag(style) != Ed.DragStatus.kNormal:
            print("oops")
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

        ps, pnt = ed.getPoint("\nPick startPoint")
        if ps != Ed.PromptStatus.eNormal:
            print("oops")
            return

        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        line = Db.Line(pnt, pnt)
        line.setDatabaseDefaults()

        jig = MyJig(line, pnt)
        jig.setDispPrompt("\nPick end Point")
        if jig.drag() != Ed.DragStatus.kNormal:
            print("oops")
            return

        line.setEndPoint(jig.curPoint)
        model.appendAcDbEntity(line)

    except Exception as err:
        print(err)
