# import
import traceback

from pyrx import Db, Ed, Ge


def PyRxCmd_doit():
    try:
        db = Db.curDb()
        selres: tuple[Ed.PromptStatus, Db.ObjectId, Ge.Point3d, Ge.Matrix3d] = Ed.Editor.nEntSelP(
            "\nselect: "
        )

        if selres[0] != Ed.PromptStatus.eNormal:
            return

        cloneId = doDeepClone(selres[1], db)
        clone = Db.Entity(cloneId, Db.OpenMode.kForWrite)
        clone.transformBy(selres[3])

        jig = MoveJig(clone, selres[2])
        jig.setDispPrompt("\nPick point: ")
        if jig.drag() != Ed.DragStatus.kNormal:
            print("oops")
    except Exception as err:
        traceback.print_exception(err)


def doDeepClone(id: Db.ObjectId, db: Db.Database) -> Db.ObjectId:
    mapping = Db.IdMapping()
    db.deepCloneObjects([id], db.currentSpaceId(), mapping)
    for idPair in mapping.idPairs():
        if not idPair.isPrimary():
            continue
        return idPair.value()
    return None


class MoveJig(Ed.Jig):
    def __init__(self, ent, basepoint):
        Ed.Jig.__init__(self, ent)
        self.ent = ent
        self.curPoint = basepoint
        self.basepoint = basepoint
        self.mat = Ge.Matrix3d()

    def sampler(self):
        self.setUserInputControls
        (
            Ed.UserInputControls(
                Ed.UserInputControls.kAccept3dCoordinates
                | Ed.UserInputControls.kNullResponseAccepted
            )
        )
        point_result_tuple = self.acquirePoint(self.curPoint)
        self.curPoint = point_result_tuple[1]
        return point_result_tuple[0]

    def update(self):
        self.mat.setToTranslation(self.curPoint - self.basepoint)
        self.ent.transformBy(self.mat)
        self.basepoint = self.curPoint
        return True
