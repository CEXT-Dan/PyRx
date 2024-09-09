import traceback
from pyrx_imp import Ap, Db, Ed, Ge, Gi, Gs, Rx
import time;


print("command = pydrawjig")

WM_MOUSEMOVE = 0x0200

class MyDrawJig(Ed.DrawJig):
    def __init__(self, basepoint):
            Ed.DrawJig.__init__(self)
            self.winMsgWatchFn = self.winMsgWatch
            self.curpoint = basepoint
            self.wm_events = 1
            self.st = time.time()
            
    def winMsgWatch(self, message):
        if message[0] != WM_MOUSEMOVE:
            return
        #print(message)
        self.wm_events += 1
    
    def sampler(self):
            self.setUserInputControls(Ed.UserInputControls.kAccept3dCoordinates)
            ds, self.curpoint = self.acquirePoint()
            ps = (time.time() - self.st) * self.wm_events
            print(ps)
            return ds

    def update(self):
        return True

    def worldDraw(self, wd : Gi.WorldDraw):
        try:
            geo = wd.geometry()
            geo.circle(self.curpoint,10,Ge.Vector3d.kZAxis)
            return True
        except Exception as err:
            print(err)

def PyRxCmd_pydrawjig():
    try:
        jig = MyDrawJig(Ge.Point3d(0, 0, 0))
        Ap.Application.registerWatchWinMsg(jig.winMsgWatchFn)
        jig.setDispPrompt("\nPick endPoint:\n")
        print("done", jig.drag())
    except Exception as err:
        print(err)
    finally:
        Ap.Application.removeWatchWinMsg(jig.winMsgWatchFn)
