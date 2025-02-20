from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax
import traceback


def PyRxCmd_doit():
    try:
        Ed.Core.setStatusBarProgressMeter("Calculating", 0, 100)
        for i in range(100):
            Ed.Core.setStatusBarProgressMeterPos(i)
        Ed.Core.restoreStatusBar()
    except Exception as err:
        traceback.print_exception(err)
