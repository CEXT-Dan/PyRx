import os
import unittest
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

# requires win32com.client
host = Ap.Application.hostAPI()
if host == "BRX":
    import BxApp24 as Ax
elif host == "GRX":
    import GxApp24 as Ax
elif host == "ZRX":
    import ZxApp24 as Ax
else:
    import AxApp24 as Ax

print("testname = pyactivex")

class TestActiveX(unittest.TestCase):
    def test_get_app(self):
        app = Ax.getApp()
        name: str = app.Name
        if host == "BRX":
            self.assertTrue("BricsCAD" in name)
        elif host == "GRX":
            self.assertTrue("GstarCAD" in name)
        elif host == "ZRX":
            self.assertTrue("ZWCAD" in name)
        else:
            self.assertTrue("AutoCAD" in name)

    def test_get_dbx(self):
        if host != "ARX":
            return
        dbx = Ax.getDbx()
        path = ".\\testmedia\\06457.dwg"
        dbx.Open(path, None)
        for ent in dbx.ModelSpace:
            self.assertNotEqual(ent.ObjectID, 0)

        self.assertEqual(dbx.Name, path)
        self.assertNotEqual(dbx.ModelSpace.Count, 0)

    def test_add_point(self):
        app = Ax.getApp()
        point = app.ActiveDocument.ModelSpace.AddPoint((100, 200, 300))
        self.assertEqual(point.Coordinates, (100, 200, 300))
        point.Coordinates = (1, 2, 3)
        self.assertEqual(point.Coordinates, (1, 2, 3))
        point.Delete()

    def test_add_line(self):
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLine((100, 200, 300), (400, 500, 600))
        self.assertEqual(line.StartPoint, (100, 200, 300))
        self.assertEqual(line.EndPoint, (400, 500, 600))
        line.StartPoint = (1, 2, 3)
        line.EndPoint = (4, 5, 6)
        self.assertEqual(line.StartPoint, (1, 2, 3))
        self.assertEqual(line.EndPoint, (4, 5, 6))
        line.Delete()
    
    def test_add_circle(self):
        app = Ax.getApp()
        circle = app.ActiveDocument.ModelSpace.AddCircle((100,200,300),50)
        self.assertEqual(circle.Radius,50)
        self.assertEqual(circle.Center,(100,200,300))
        circle.Center = (400,500,600)
        circle.Radius = 100
        self.assertEqual(circle.Radius,100)
        self.assertEqual(circle.Center,(400,500,600))
        circle.Delete()

    def test_add_ellipse(self):
        app = Ax.getApp()
        ellipse = app.ActiveDocument.ModelSpace.AddEllipse((100,200,0),(200,300,0),0.5)
        self.assertEqual(ellipse.Center, (100,200,0))
        self.assertEqual(ellipse.MajorAxis, (200,300,0))
        self.assertEqual(ellipse.RadiusRatio, 0.5)
        ellipse.Center = (400,500,0)
        ellipse.MajorAxis = (500,600,0)
        self.assertEqual(ellipse.Center, (400,500,0))
        self.assertEqual(ellipse.MajorAxis, (500,600,0))
        ellipse.Delete()

    def test_add_polyline(self):
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLightWeightPolyline(
            [0, 0, 10, 10, 20, 10]
        )
        self.assertEqual(line.Coordinates, (0, 0, 10, 10, 20, 10))
        line.Coordinates = (1, 2, 3, 4, 5, 6)
        self.assertEqual(line.Coordinates, (1, 2, 3, 4, 5, 6))
        line.Delete()

    def test_add_mtext(self):
        app = Ax.getApp()
        mt = app.ActiveDocument.ModelSpace.AddMText((100, 200, 300), 40, "Hello world")
        self.assertEqual(mt.InsertionPoint, (100, 200, 300))
        mt.InsertionPoint = (400, 100, 0)
        self.assertEqual(mt.InsertionPoint, (400, 100, 0))
        mt.Delete()

    def test_Add3DFaceProps(self):
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        face = model.Add3DFace((0, 0, 0), (0, 100, 0), (100, 100, 0), (100, 0, 0))
        face.SetCoordinate(3, face.Coordinate(3))
        self.assertEqual(face.Coordinate(3), (100, 0, 0))
        face.Delete()

    def test_ent_copy(self):
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        line = model.AddLine((0, 0, 0), (100, 100, 0))
        lineCopy = line.Copy()
        self.assertEqual(line.StartPoint, lineCopy.StartPoint)
        self.assertEqual(line.EndPoint, lineCopy.EndPoint)
        line.Delete()
        lineCopy.Delete()

    def test_iter_block(self):
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

    def test_iter_selection1(self):
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

    def test_iter_selection2(self):
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

    def test_iter_selection3(self):
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
            
    def test_iter_documents(self):
        axApp = Ax.getApp()
        cnt = 0
        for doc in axApp.Documents:
            cnt +=1
        self.assertNotEqual(cnt, 0)

def PyRxCmd_pyactivex():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestActiveX)
        print("TestActiveX")
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
