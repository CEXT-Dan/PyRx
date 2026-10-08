import traceback

from pyrx import Ap, Db, Ge


@Ap.Command()
def doit():
    try:
        db = Db.curDb()
        fonts = [
            "ITALIC8.shx",
            "romant.shx",
            "extfont.shx",
            "gbcbig.shx",
            "gothicg.shx",
            "gothice.shx",
            "italic.shx",
            "simplex.shx",
        ]
        line_gap = 1.5
        for idx, font in enumerate(fonts):
            val = f"This is some text in {font}"
            plines = Db.Core.tessellateString(val, font)
            mat = Ge.Matrix3d.translation(Ge.Vector3d(0, idx * line_gap, 0))
            for pline in plines:
                pline.transformBy(mat)
                db.addToCurrentspace(pline)
    except Exception:
        traceback.print_exc()
