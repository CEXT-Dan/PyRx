from pyrx import Ap, Ed, Ge, Rx


def OnPyInitApp():
    print("\nOnPyInitApp")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


# (mylispfunc '("hello world" 1 2 3 4 (1 10 100)))
@Ap.LispFunction()
def mylispfunc(args):
    try:
        return args
    except Exception as err:
        print(err)


# (pylisp)
@Ap.LispFunction()
def pylisp(args):
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
@Ap.LispFunction()
def pylisp1(args):
    try:
        return [(Rx.LispType.kText, "Text")]
    except Exception as err:
        print(err)


# (pylisprt '("hello world" 1 2 3 4 (1 10 100)))
@Ap.LispFunction()
def pylisprt(args):
    try:
        return args
    except Exception as err:
        print(err)


# (pylispvoid)
@Ap.LispFunction()
def pylispvoid(args):
    try:
        print("yay!")
    except Exception as err:
        print(err)


# (pylispbool)
@Ap.LispFunction()
def pylispbool(args):
    try:
        print("yay!")
        return True
    except Exception as err:
        print(err)


# (pylispint)
@Ap.LispFunction()
def pylispint(args):
    try:
        print("yay!")
        return 42
    except Exception as err:
        print(err)


# (pylispreal)
@Ap.LispFunction()
def pylispreal(args):
    try:
        print("yay!")
        return 1.1
    except Exception as err:
        print(err)


# (pylisp2p)
@Ap.LispFunction()
def pylisp2p(args):
    try:
        print("yay!")
        return Ge.Point2d(1.2, 1.4)
    except Exception as err:
        print(err)


# (pylisp3p)
@Ap.LispFunction()
def pylisp3p(args):
    try:
        print("yay!")
        return Ge.Point3d(1.2, 1.4, 4.5)
    except Exception as err:
        print(err)


# (pylisp3p2)
@Ap.LispFunction()
def pylisp3p2(args):
    try:
        print("yay!")
        return (Rx.LispType.kPoint3d, Ge.Point3d(1.2, 1.4, 4.5))
    except Exception as err:
        print(err)


# (pylispstr)
@Ap.LispFunction()
def pylispstr(args):
    try:
        print("yay!")
        return "woohoo"
    except Exception as err:
        print(err)


# (sslength(pylispss))
sslist = []


@Ap.LispFunction()
def pylispss(args):
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
