from pyrx import Ap, Ed, Rx


def PyRxCmd_pyofd():
    try:
        # acedGetFileD
        path = Ed.Core.getFileD("myfile.dwg", "", "dwg;eps;abc", 33)
        print(path)
    except Exception as err:
        print(err)


def PyRxCmd_pyofd2():
    try:
        # acedGetFileNavDialog
        paths = Ed.Core.getFileNavDialog(
            "myfile.dwg", "", "dwg;eps;abc", "My File Dialog", 4096
        )
        print(paths)
    except Exception as err:
        print(err)


@Ap.Command("pycmd1")
def pycmd1():
    try:
        # acedCmdS wrapper, use a typed value list as resbuf
        resbuf = [
            (Rx.LispType.kText, "_UCS"),
            (Rx.LispType.kText, "World"),
            (Rx.LispType.kNone, 0),
        ]
        Ed.Core.cmdS(resbuf)
    except Exception as err:
        print(err)
