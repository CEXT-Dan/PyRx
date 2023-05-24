import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

print("command = pydrawoverrule")
print("command = pystopoverrule")

class MyDrawableOverrule(PyGi.DrawableOverrule):
    def __init__(self):
        PyGi.DrawableOverrule.__init__(self)
        self.circle = PyDb.Circle(PyGe.Point3d(0, 0, 0), PyGe.Vector3d.kZAxis, 10)
        self.circle.setDatabaseDefaults()
    
    #override
    def isApplicable(self, subject):
        return True
    
    #override
    def worldDraw(self, subject, wd):
        try:
            line = PyDb.Line.copyAs(subject)#todo
            seg = PyGe.LineSeg3d(line.endPoint(), line.startPoint())
            cen = PyGe.Point3d(seg.midPoint())
            rad = seg.length() * 0.3
            self.circle.setCenter(cen)
            self.circle.setRadius(rad)
            self.circle.setColorIndex(40)
            geo = wd.worldGeometry()
            geo.draw(self.circle)
            return self.baseWorldDraw(subject,wd)
        except Exception as err:
            print(err)
    
#global       
overrule = MyDrawableOverrule()

#cmds
def PyRxCmd_pydrawoverrule():
    try:
        if overrule.addOverrule(PyDb.Line.desc(), overrule) == PyDb.ErrorStatus.eOk:
            overrule.setIsOverruling(True)
        else:
            print("fail")
    except Exception as err:
        PyRxApp.Printf(err)
        
def PyRxCmd_pystopoverrule():
    try:
        if overrule == None:
            return
        if overrule.removeOverrule(PyDb.Line.desc(), overrule) == PyDb.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
    except Exception as err:
        PyRxApp.Printf(err)