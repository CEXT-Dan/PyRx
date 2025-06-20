import traceback

from pyrx import Ap, Db, Ed

print("added command pymon")
print("added command pyunmon")


# exit clean
def OnPyUnloadApp():
    PyRxCmd_pyunmon()


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

            # just get the first entity and check the type
            if not ents[0].isDerivedFrom(Db.MText.desc()):
                return

            # open the mtext for read
            mt = Db.MText(ents[0])
            bp = mt.getBoundingPoints()
            if len(bp) != 4:
                return

            # reorder the points
            self.swap(bp, 2, 3)

            # draw the geometry
            input.drawContext().geometry().polygon(bp)
        except Exception as err:
            print(err)


# global space
pm = MyPointMonitor()


def PyRxCmd_pymon():
    try:
        manager = Ap.curDoc().inputPointManager()
        manager.addPointMonitor(pm)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pyunmon():
    try:
        manager = Ap.curDoc().inputPointManager()
        manager.removePointMonitor(pm)

    except Exception as err:
        traceback.print_exception(err)
