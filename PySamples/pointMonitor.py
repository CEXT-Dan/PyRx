import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback


class MyPointMonitor(Ed.InputPointMonitor):
    def __init__(self):
        Ed.InputPointMonitor.__init__(self)
        
    def swap(self, list, pos1, pos2):
        list[pos1], list[pos2] = list[pos2], list[pos1]
        return list

    def monitorInputPoint(self, input, output):
        try:
            ents = input.pickedEntities()
            if len(ents) == 0:
                return
            if not ents[0].isDerivedFrom(Db.MText.desc()):
                return
            mt = Db.MText(ents[0])
            bp = mt.getBoundingPoints()
            if len(bp) != 4:
                return
            self.swap(bp,2,3)
            input.drawContext().geometry().polygon(bp)
        except Exception as err:
            print(err)


pm = MyPointMonitor()


def PyRxCmd_doit():
    try:
        manager = Ap.curDoc().inputPointManager()
        manager.addPointMonitor(pm)

    except Exception as err:
        traceback.print_exception(err)
