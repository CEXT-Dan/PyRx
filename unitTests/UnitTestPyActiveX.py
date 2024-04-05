import os
import unittest
import testcfg
from pyrx_impx import Rx
from pyrx_impx import Ge
from pyrx_impx import Gi
from pyrx_impx import Db
from pyrx_impx import Ap
from pyrx_impx import Ed
from pyrx_impx import Ax


import math

def almostEq(L , R) -> bool:
    for l,r in zip(L,R):
        if not math.isclose(l, r, rel_tol=1e-2):
            return False
    return True

host = Ap.Application.hostAPI()
    
class TestActiveX(unittest.TestCase):
    def test_get_app(self):
        app = Ax.getApp()
        name: str = app.Name
        if "BRX" in host:
            self.assertTrue("BricsCAD" in name)
        elif "GRX" in host:
            self.assertTrue("GstarCAD" in name)
        elif "ZRX" in host:
            self.assertTrue("ZWCAD" in name)
        else:
            self.assertTrue("AutoCAD" in name)

    def test_get_dbx(self) -> None:
        if not "ARX" in host:
            return
        dbx = Ax.getDbx()
        path = ".\\testmedia\\06457.dwg"
        dbx.Open(path, None)
        for ent in dbx.ModelSpace:
            self.assertNotEqual(ent.ObjectID, 0)

        self.assertEqual(dbx.Name, path)
        self.assertNotEqual(dbx.ModelSpace.Count, 0)

    def test_add_attribute(self):
        app = Ax.getApp()
        attr = app.ActiveDocument.ModelSpace.AddAttribute(1, 
            Ax.constants.acAttributeModeInvisible,
            "PromptTest",
            (0, 0, 0),
            "Tag",
            "Value")       

        self.assertEqual(attr.InsertionPoint, (0, 0, 0))
        self.assertEqual(attr.TagString, "Tag")
        self.assertEqual(attr.TextString, "Value")
        attr.InsertionPoint = (1, 2, 3)
        attr.TagString = "Tag2"
        attr.TextString = "Value2"
        self.assertEqual(attr.InsertionPoint, (1, 2, 3))
        self.assertEqual(attr.TagString, "Tag2")
        self.assertEqual(attr.TextString, "Value2")
        attr.Delete()

    def test_add_point(self) -> None:
        app = Ax.getApp()
        point = app.ActiveDocument.ModelSpace.AddPoint((100, 200, 300))
        self.assertEqual(point.Coordinates, (100, 200, 300))
        point.Coordinates = (1, 2, 3)
        self.assertEqual(point.Coordinates, (1, 2, 3))
        point.Delete()

    def test_add_line(self) -> None:
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLine((100, 200, 300), (400, 500, 600))
        self.assertEqual(line.StartPoint, (100, 200, 300))
        self.assertEqual(line.EndPoint, (400, 500, 600))
        line.StartPoint = (1, 2, 3)
        line.EndPoint = (4, 5, 6)
        self.assertEqual(line.StartPoint, (1, 2, 3))
        self.assertEqual(line.EndPoint, (4, 5, 6))
        line.Delete()
    
    def test_add_circle(self) -> None:
        app = Ax.getApp()
        circle = app.ActiveDocument.ModelSpace.AddCircle((100,200,300),50)
        self.assertEqual(circle.Radius,50)
        self.assertEqual(circle.Center,(100,200,300))
        circle.Center = (400,500,600)
        circle.Radius = 100
        self.assertEqual(circle.Radius,100)
        self.assertEqual(circle.Center,(400,500,600))
        circle.Delete()

    def test_add_ellipse(self) -> None:
        app = Ax.getApp()
        ellipse = app.ActiveDocument.ModelSpace.AddEllipse((100,200,0),(200,300,0),0.5)
        self.assertTrue(almostEq(ellipse.Center,(100,200,0)))
        self.assertTrue(almostEq(ellipse.MajorAxis, (200,300,0)))
        self.assertAlmostEqual(ellipse.RadiusRatio, 0.5, 10)
        ellipse.Center = (400,500,0)
        ellipse.MajorAxis = (500,600,0)
        self.assertTrue(almostEq(ellipse.Center, (400,500,0)))
        self.assertTrue(almostEq(ellipse.MajorAxis, (500,600,0)))
        ellipse.Delete()

    # Todo: run test on AutoCAD with Position
    def test_add_box(self) -> None:
        app = Ax.getApp()
        box = app.ActiveDocument.ModelSpace.AddBox((0, 0, 0), 10, 20, 30)
        self.assertEqual(box.Layer, "0")
        # self.assertEqual(box.Position, (0, 0, 0))
        # box.Position= (1, 2, 3)
        # self.assertEqual(box.Position, (1, 2, 3))
        box.Delete()

    def test_add_cylinder(self) -> None:
        app = Ax.getApp()
        cylinder = app.ActiveDocument.ModelSpace.AddCylinder((0, 0, 0), 10, 50)
        # self.assertEqual(cylinder.Position, (0, 0, 0))
        cylinder.Delete()
        # find solid properties to test
        # assertequal one property

    def test_add_cone(self) -> None:
        pass

    def test_add_elliptical_cylinder(self) -> None:
        pass

    def test_add_elliptical_cone(self) -> None:
        pass

    def test_add_polyline(self) -> None:
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLightWeightPolyline(
            [0, 0, 10, 10, 20, 10]
        )
        self.assertEqual(line.Coordinates, (0, 0, 10, 10, 20, 10))
        line.Coordinates = (1, 2, 3, 4, 5, 6)
        self.assertEqual(line.Coordinates, (1, 2, 3, 4, 5, 6))
        line.Delete()

    #TODO: GRX is wonkey 
    def test_add_table(self) -> None:
        app = Ax.getApp()
        table = app.ActiveDocument.ModelSpace.AddTable((0, 0, 0), 4, 5, 10, 30)
        self.assertEqual(table.InsertionPoint, (0, 0, 0))
        self.assertEqual(table.Rows, 4)
        self.assertEqual(table.Columns, 5)
        self.assertEqual(table.GetRowHeight(2), 10)
        self.assertEqual(table.GetColumnWidth(2), 30)
        table.InsertionPoint = (1, 2, 3)
        self.assertEqual(table.InsertionPoint, (1, 2, 3))
        if not "GRX" in host:
            table.SetTextString(0, 0, 0, "MyDadIsDisappointedThatIPutHi")
            self.assertEqual(table.GetTextString(0, 0, 0), "MyDadIsDisappointedThatIPutHi")
        table.Delete()

    def test_add_mline(self) -> None:
        app = Ax.getApp()
        mline = app.ActiveDocument.ModelSpace.AddMLine([0, 0, 0, 10, 20, 0])
        self.assertEqual(mline.Coordinates, (0, 0, 0, 10, 20, 0))
        mline.Coordinates = [10, 10, 0, 20, 30, 0]
        self.assertEqual(mline.Coordinates, (10, 10, 0, 20, 30, 0))
        mline.Delete()

    def test_add_text(self) -> None:
        app = Ax.getApp()
        text = app.ActiveDocument.ModelSpace.AddText("Oratrice Mechanique D'Analyse Cardinale 3000", (0, 0, 0), 1)
        self.assertEqual(text.TextString, "Oratrice Mechanique D'Analyse Cardinale 3000")
        self.assertEqual(text.InsertionPoint, (0, 0, 0))
        self.assertEqual(text.Height, 1)
        text.TextString = "Hello World"
        text.InsertionPoint = (1,2,3)
        self.assertEqual(text.TextString, "Hello World")
        self.assertEqual(text.InsertionPoint, (1, 2, 3))
        text.Delete()

    def test_add_mtext(self) -> None:
        app = Ax.getApp()
        mt = app.ActiveDocument.ModelSpace.AddMText((100, 200, 300), 40, "Hello world")
        self.assertEqual(mt.InsertionPoint, (100, 200, 300))
        mt.InsertionPoint = (400, 100, 0)
        self.assertEqual(mt.InsertionPoint, (400, 100, 0))
        mt.Delete()

    def test_Add3DFaceProps(self) -> None:
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        face = model.Add3DFace((0, 0, 0), (0, 100, 0), (100, 100, 0), (100, 0, 0))
        face.SetCoordinate(3, face.Coordinate(3))
        self.assertEqual(face.Coordinate(3), (100, 0, 0))
        face.Delete()

    def test_ent_copy(self) -> None:
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        line = model.AddLine((0, 0, 0), (100, 100, 0))
        lineCopy = line.Copy()
        self.assertEqual(line.StartPoint, lineCopy.StartPoint)
        self.assertEqual(line.EndPoint, lineCopy.EndPoint)
        line.Delete()
        lineCopy.Delete()

    def test_iter_block(self) -> None:
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        points = []
        for x in range(10):
            for y in range(100):
                points.append(model.AddPoint((x, y, 0)))
        cnt = 0
        for item in model:
            cnt += 1
        self.assertEqual(len(points), cnt)
        for p in points:
            p.Delete()

    def test_iter_selection1(self) -> None:
        app = Ax.getApp()
        doc = app.ActiveDocument
        model = doc.ModelSpace
        points = []
        for x in range(10):
            for y in range(100):
                points.append(model.AddPoint((x, y, 0)))
        cnt = 0
        for item in model:
            cnt += 1
        self.assertEqual(len(points), cnt)
        cnt2 = 0
        ss = doc.SelectionSets.Add("mysset")
        try:
            ss.Select(Ax.constants.acSelectionSetAll)
            for e in ss:
                name = e.ObjectName
                cnt2 += 1
            self.assertEqual(cnt2, cnt)
        except:
            pass
        finally:
            for p in points:
                p.Delete()
            ss.Delete()

    def test_iter_selection2(self) -> None:
        app = Ax.getApp()
        doc = app.ActiveDocument
        model = doc.ModelSpace
        points = []
        for x in range(10):
            for y in range(100):
                points.append(model.AddPoint((x, y, 0)))
        cnt = 0
        for item in model:
            cnt += 1
        self.assertEqual(len(points), cnt)
        cnt2 = 0
        ss = doc.SelectionSets.Add("mysset")
        try:
            ss.Select(Ax.constants.acSelectionSetAll)
            for i in range(ss.Count):
                name = ss[i].ObjectName
                cnt2 += 1
            self.assertEqual(cnt2, cnt)
        except:
            pass
        finally:
            for p in points:
                p.Delete()
            ss.Delete()

    def test_iter_selection3(self) -> None:
        app = Ax.getApp()
        doc = app.ActiveDocument
        model = doc.ModelSpace
        points = []
        for x in range(10):
            for y in range(100):
                points.append(model.AddPoint((x, y, 0)))
        cnt = 0
        for item in model:
            cnt += 1
        self.assertEqual(len(points), cnt)
        cnt2 = 0
        ss = doc.SelectionSets.Add("mysset")
        try:
            ss.Select(Ax.constants.acSelectionSetAll)
            for i in range(ss.Count):
                name = ss.Item(i).ObjectName
                cnt2 += 1
            self.assertEqual(cnt2, cnt)
        except:
            pass
        finally:
            for p in points:
                p.Delete()
            ss.Delete()
            
    def test_iter_documents(self) -> None:
        axApp = Ax.getApp()
        cnt = 0
        for doc in axApp.Documents:
            cnt +=1
        self.assertNotEqual(cnt, 0)

def pyactivex() -> None:
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestActiveX)
        print("TestActiveX")
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print(unittest.TextTestRunner(testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
