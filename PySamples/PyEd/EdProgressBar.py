import traceback
from time import sleep

from pyrx import Ed


def PyRxCmd_doit():
    try:
        Ed.Core.setStatusBarProgressMeter("Calculating", 0, 100)
        for i in range(100):
            sleep(0.05)
            Ed.Core.setStatusBarProgressMeterPos(i)
        Ed.Core.restoreStatusBar()
    except Exception as err:
        traceback.print_exception(err)
