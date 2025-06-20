from pyrx import Ed, Ge, Rx


def OnPyInitApp():
    print("\nOnPyInitApp")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


# (pylisp)
def PyRxLisp_pylisp(args):
    try:
        return [
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "Text"),
            (Rx.LispType.kDouble, 12.23),
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kInt16, 1),
            (Rx.LispType.kInt32, 2),
            (Rx.LispType.kNil, 0),
            (Rx.LispType.kT_atom, 0),
            (Rx.LispType.kListEnd, 0),
            (Rx.LispType.kPoint3d, Ge.Point3d(1, 10, 100)),
            (Rx.LispType.kListEnd, 0),
        ]
    except Exception as err:
        print(err)


# (pylisp1)
def PyRxLisp_pylisp1(args):
    try:
        return [(Rx.LispType.kText, "Text")]
    except Exception as err:
        print(err)


# (pylisprt '("hello world" 1 2 3 4 (1 10 100)))
def PyRxLisp_pylisprt(args):
    try:
        return args
    except Exception as err:
        print(err)


# (pylispvoid)
def PyRxLisp_pylispvoid(args):
    try:
        print("yay!")
    except Exception as err:
        print(err)


# (pylispbool)
def PyRxLisp_pylispbool(args):
    try:
        print("yay!")
        return True
    except Exception as err:
        print(err)


# (pylispint)
def PyRxLisp_pylispint(args):
    try:
        print("yay!")
        return 42
    except Exception as err:
        print(err)


# (pylispreal)
def PyRxLisp_pylispreal(args):
    try:
        print("yay!")
        return 1.1
    except Exception as err:
        print(err)


# (pylisp2p)
def PyRxLisp_pylisp2p(args):
    try:
        print("yay!")
        return Ge.Point2d(1.2, 1.4)
    except Exception as err:
        print(err)


# (pylisp3p)
def PyRxLisp_pylisp3p(args):
    try:
        print("yay!")
        return Ge.Point3d(1.2, 1.4, 4.5)
    except Exception as err:
        print(err)


# (pylisp3p2)
def PyRxLisp_pylisp3p2(args):
    try:
        print("yay!")
        return (Rx.LispType.kPoint3d, Ge.Point3d(1.2, 1.4, 4.5))
    except Exception as err:
        print(err)


# (pylispstr)
def PyRxLisp_pylispstr(args):
    try:
        print("yay!")
        return "woohoo"
    except Exception as err:
        print(err)


# (sslength(pylispss))
sslist = []


def PyRxLisp_pylispss(args):
    try:
        sslist.clear()
        ssres = Ed.Editor.selectAll()
        sslist.append(ssres[1])
        return sslist[0]
    except Exception as err:
        print(err)


# sample conversion utility, needs work
def iterableToResbuf(src):
    dest = []
    for item in src:
        match type(item).__name__:
            case "ObjectId":
                dest.append((Rx.LispType.kObjectId, item))
            case "Point3d":
                dest.append((Rx.LispType.kPoint3d, item))
            case "Point2d":
                dest.append((Rx.LispType.kPoint2d, item))
            case "float":
                dest.append((Rx.LispType.kDouble, item))
            case "int":
                dest.append((Rx.LispType.kInt32, item))
            case "str":
                dest.append((Rx.LispType.kText, item))
            case "list":
                dest.append((Rx.LispType.kListBegin, 0))
                dest.extend(iterableToResbuf(item))
                dest.append((Rx.LispType.kListEnd, 0))
            case "tuple":
                dest.append((Rx.LispType.kListBegin, 0))
                dest.extend(iterableToResbuf(item))
                dest.append((Rx.LispType.kListEnd, 0))
            case _:
                print("warning item not found!: ")
    return dest
