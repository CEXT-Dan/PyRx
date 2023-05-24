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
        self.circle.setColorIndex(40)
    
    #override
    def isApplicable(self, subject):
        return True
    
    #override
    def worldDraw(self, subject, wd):
        try:
            #draw the subject first
            flag = self.baseWorldDraw(subject,wd)
            
            #no cast in python, create a clone
            line = PyDb.Line.cloneFrom(subject)
            
            #modify the circle
            seg = PyGe.LineSeg3d(line.endPoint(), line.startPoint())
            cen = PyGe.Point3d(seg.midPoint())
            rad = seg.length() * 0.3
            self.circle.setCenter(cen)
            self.circle.setRadius(rad)
            
            #draw the custom stuff
            geo = wd.worldGeometry()
            geo.draw(self.circle)
            
            #returing false here will go to viewport
            return flag
        except Exception as err:
            print(err)
    
#put this in global space   
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