import unittest
import testcfg
import dbc

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
from typing import List

host = Ap.Application.hostAPI()

class TestAssocPersSubentIdPE(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestAssocPersSubentIdPE, self).__init__(*args, **kwargs)
    
    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX|testcfg.ETFlags.eGRX|testcfg.ETFlags.eZRX))
    def test_soid3d_subent_geometry(self):
        objHnd = Db.Handle("26c")
        objId =  dbc.dbs["subentpe"].getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        solid = Db.Solid3d(objId)
        pe = Db.AssocPersSubentIdPE(solid.queryX(Db.AssocPersSubentIdPE.desc()))
        
        vertexs: List[Ge.Point3d] = list()
        edges: List[Ge.Curve3d] = list()
        faces: List[Ge.Surface] = list()
        
        for vtx in pe.getAllSubentities(solid, Db.SubentType.kVertexSubentType):
            vertexs.append(pe.getVertexSubentityGeometry(solid,vtx))

        for edge in pe.getAllSubentities(solid, Db.SubentType.kEdgeSubentType):
            edges.append(pe.getEdgeSubentityGeometry(solid, edge))
            
        for face in pe.getAllSubentities(solid, Db.SubentType.kFaceSubentType):
            faces.append(pe.getFaceSubentityGeometry(solid, face))
            
        self.assertEqual(len(vertexs), 8)
        self.assertEqual(len(edges), 12)
        self.assertEqual(len(faces), 6)
        
        
def AssocPersSubentIdPETester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestAssocPersSubentIdPE)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestAssocPersSubentIdPE"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestAssocPersSubentIdPE")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
