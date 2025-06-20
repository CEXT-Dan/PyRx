import traceback

from pyrx import Cv, Db, Ed, Ge

# https://stackoverflow.com/questions/1243614/how-do-i-calculate-the-normal-vector-of-a-line-segment#1243676
# https://stackoverflow.com/questions/8885663/how-to-format-a-floating-number-to-fixed-width-in-python

print("added command - cvaddsectionhalignment")

drawProps = {'stShift': .01, 'offset': 500, 'heightAbove': 5, 'heightBelow': 1}
# some day this may be transformed into command line prompts

def getNormalPts(db: Db.Database, halign: Cv.CvDbHAlignment, station: float):
    # preparing info from halignment and station
    pt = halign.getPointAtStation(station)
    steq = halign.stationEquations()
    fst = steq.getStartingStation()
    rest = steq.getRawStationFromLength(halign.length()) # check for shift in stationing
    lst = steq.getStation(rest) # get last station
    # check if we are close to finish or too short
    if station + drawProps["stShift"] < lst:
        ptv = halign.getPointAtStation(station + drawProps["stShift"])
    elif station - drawProps["stShift"] > fst:
        ptv = halign.getPointAtStation(station - drawProps["stShift"])
    else:
        print("\nbreaking, since alignment too short")
        return False
    normal = Ge.Vector3d(-(ptv[1].y-pt[1].y), (ptv[1].x-pt[1].x), 0)
    pts = []
    pts.append(Ge.Point3d(pt[1].x, pt[1].y, 0) + (normal * drawProps["offset"]))
    pts.append(Ge.Point3d(pt[1].x, pt[1].y, 0) - (normal * drawProps["offset"]))
    return pts

def PyRxCmd_cvaddsectionhalignment():
    try:
        # select entity
        esel = Ed.Editor.entSel("\nSelect Horizontal Alignment: ", Cv.CvDbHAlignment.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Not a Horizontal Alignment{}: ".format(esel[0])) 
            return
        
        # get station as positive float
        while True:
            ssResult = Ed.Editor.getDouble("\nEnter station: ")
            if ssResult[0] == Ed.PromptStatus.eNormal : 
                if ssResult[1] > 0 :
                    break
                print("\nEnter a positive value")
        station = ssResult[1]

        halign = Cv.CvDbHAlignment(esel[1], Db.OpenMode.kForRead)
        db = Db.curDb()
        pts = getNormalPts(db, halign, station)

        # draw section
        _st = Db.SectionType.k3dSection
        sec = Db.Section(pts, Ge.Vector3d.kZAxis)
        sec.setState(Db.SectionState.kPlane)
        sec.enableLiveSection(False)
        sec.setHeight(Db.SectionHeight.kHeightAboveSectionLine, drawProps["heightAbove"])
        sec.setHeight(Db.SectionHeight.kHeightBelowSectionLine, drawProps["heightBelow"])  
        sec.setName(str(halign.name())+' - '+'{:08.1f}'.format(station))
        _secid = db.addToModelspace(sec)

    except Exception as err:
        traceback.print_exception(err)
