from __future__ import annotations

from typing import List

import pytest

from pyrx import Db, Ge


class TestAssocPersSubentIdPE:

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_soid3d_subent_geometry(self, db_subentpe: Db.Database):
        objHnd = Db.Handle("26c")
        objId = db_subentpe.getObjectId(False, objHnd)
        assert objId.isValid() == True
        solid = Db.Solid3d(objId)
        pe = Db.AssocPersSubentIdPE(solid.queryX(Db.AssocPersSubentIdPE.desc()))

        vertexs: List[Ge.Point3d] = list()
        edges: List[Ge.Curve3d] = list()
        faces: List[Ge.Surface] = list()

        for vtx in pe.getAllSubentities(solid, Db.SubentType.kVertexSubentType):
            vertexs.append(pe.getVertexSubentityGeometry(solid, vtx))

        for edge in pe.getAllSubentities(solid, Db.SubentType.kEdgeSubentType):
            edges.append(pe.getEdgeSubentityGeometry(solid, edge))

        for face in pe.getAllSubentities(solid, Db.SubentType.kFaceSubentType):
            faces.append(pe.getFaceSubentityGeometry(solid, face))

        assert len(vertexs), 8
        assert len(edges), 12
        assert len(faces), 6
