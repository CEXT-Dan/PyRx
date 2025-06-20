import traceback

from pyrx import Db, Ge, Rx

fragKeyNames = list(Db.MTextFragmentType.names.keys())


def objectToTypedValue(obj, result) -> tuple[Rx.LispType, object]:
    if obj is None:
        result.append((Rx.LispType.kNil, 0))
    elif isinstance(obj, str):
        result.append((Rx.LispType.kText, obj))
    elif isinstance(obj, bool):
        result.append((Rx.LispType.kInt32, obj))
    elif isinstance(obj, int):
        result.append((Rx.LispType.kInt32, obj))
    elif isinstance(obj, float):
        result.append((Rx.LispType.kDouble, obj))
    elif isinstance(obj, Ge.Point3d):
        result.append((Rx.LispType.kPoint3d, obj))
    elif isinstance(obj, Ge.Vector3d):
        result.append((Rx.LispType.kVector3d, obj))
    elif isinstance(obj, Ge.Point2d):
        result.append((Rx.LispType.kPoint2d, obj))
    elif isinstance(obj, Ge.Vector2d):
        result.append((Rx.LispType.kVector2d, obj))
    elif isinstance(obj, Db.EntityColor):
        result.append((Rx.LispType.kInt32, obj.getRGB()))
    elif isinstance(obj, list):
        for item in obj:
            objectToTypedValue(item, result)
    else:
        result.append((Rx.LispType.kText, str(obj)))


def fragToList(frags, result):
    result.append((Rx.LispType.kListBegin, 0))
    for idx, frag in enumerate(frags):
        result.append((Rx.LispType.kListBegin, 0))
        result.append((Rx.LispType.kText, fragKeyNames[idx]))
        objectToTypedValue(frag, result)
        result.append((Rx.LispType.kListEnd, 0))
    result.append((Rx.LispType.kListEnd, 0))


# (pydoit (car(entsel)))
def PyRxLisp_pydoit(args):
    try:
        if len(args) < 1 or args[0][0] != int(Rx.LispType.kObjectId):
            print("Bad args")
            return None

        id: Db.ObjectId = args[0][1]
        if not id.isDerivedFrom(Db.MText.desc()):
            print("Not a mtext")
            return None

        mt = Db.MText(id)
        frags = mt.getFragments()

        result = []
        for fr in frags:
            fragToList(fr, result)

        return result

    except Exception as err:
        traceback.print_exception(err)
