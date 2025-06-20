import traceback

from pyrx_imp import Cv


def cvDbVAlignment_iter(objId):
    try:
        vAlignment = Cv.CvDbVAlignment(objId)
        ids = []
        elementId = vAlignment.firstElementId()
        while (elementId != 0):
            element = vAlignment.elementAtId(elementId)
            if elementId != 0:
                ids.append(elementId)
            elementId = element.nextId()
        return(ids)

    except Exception as err:
        traceback.print_exception(err)

def cvDbHAlignment_iter(objId):
    try:
        hAlignment = Cv.CvDbHAlignment(objId)
        ids = []
        elementId = hAlignment.firstElementId()
        while (elementId != 0):
            element = hAlignment.elementAtId(elementId)
            if elementId != 0:
                ids.append(elementId)
            elementId = element.nextId()
        return(ids)

    except Exception as err:
        traceback.print_exception(err)
