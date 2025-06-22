import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed

ACDB_INFINITE_XCLIP_DEPTH = 1.0e300


def addFilter_getmat(refid, filter):
    ref = Db.BlockReference(refid, Db.OpenMode.kForWrite)
    Db.IndexFilterManager.addFilter(ref, filter)
    return ref.blockTransform()


@Ap.Command()
def doit():
    try:
        db = Db.curDb()

        ps, refid, _ = Ed.Editor.entSel("\nSelect ", Db.BlockReference.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        ps, pt1 = Ed.Editor.getPoint("\nGet lower left: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("GetPoint Error! {}: ".format(ps))

        ps, pt2 = Ed.Editor.getCorner(pt1,"\nGet top right: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("GetPoint Error! {}: ".format(ps))

        filter = Db.SpatialFilter()
        mat = addFilter_getmat(refid, filter)

        pts2d = []
        for pt in [pt1,pt2]:
            pt.transformBy(mat)
            pts2d.append(Ge.Point2d(pt.x, pt.y))

        filter.setDefinition(
            pts2d,
            Ge.Vector3d.kZAxis,
            db.elevation(),
            ACDB_INFINITE_XCLIP_DEPTH,
            -ACDB_INFINITE_XCLIP_DEPTH,
            True,
        )

    except Exception as err:
        print(err)
