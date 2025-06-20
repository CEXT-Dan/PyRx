import traceback

from pyrx import Db, Ed, Ge


def PyRxCmd_doit():
    try:
        es, id, pnt = Ed.Editor.entSel("\nPick it: \n")
        ent = Db.Entity(id)

        pe = Db.AssocPersSubentIdPE(ent.queryX(Db.AssocPersSubentIdPE.desc()))

        print("vertex")
        for vtx in pe.getAllSubentities(ent, Db.SubentType.kVertexSubentType):
            pos = pe.getVertexSubentityGeometry(ent, vtx)
            print(pos)

        print("edge")
        for edge in pe.getAllSubentities(ent, Db.SubentType.kEdgeSubentType):
            curve = pe.getEdgeSubentityGeometry(ent, edge)
            print(curve.getStartPoint(), curve.getEndPoint())

        print("surface")
        for face in pe.getAllSubentities(ent, Db.SubentType.kFaceSubentType):

            # ge gesurface
            gesurface: Ge.Surface = pe.getFaceSubentityGeometry(ent, face)
            print("Ge.Surface", gesurface)

            # db version
            dbsurface = Db.Surface.cast(ent.subent(Db.FullSubentPath(id, face)))
            print("Db.Surface", dbsurface)

    except Exception as err:
        traceback.print_exception(err)