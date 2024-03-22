from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
from pyrx_imp import Cv

import pandas as pd

# assembling sample in the style of BRX SDK samples\CsBrxMgdCivil\CsBrxMgdCivil\AlignmentSample.cs
# only samp_createalignment, samp_reportalignment
# missing do_CreateAlignmentFromPolyline, do_ReplaceAlignmentElement, do_StationsAndParamRelations, do_StationEquations, do_AlignmentJig

print("added command - samp_createalignment")
print("added command - samp_reportalignment")

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

# define helper function
def angle_to(point1, point2):
    pa = Ge.Point3d(point1[0],point1[1],0)
    pb = Ge.Point3d(point2[0],point2[1],0)
    res = (pa-pb).angleTo(Ge.Vector3d.kYAxis,Ge.Vector3d.kZAxis)
    return res

# define a command
def PyRxCmd_samp_createalignment():
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        
        # create a horizontal alignment
        halignment = Cv.CvDbHAlignment()
        # adding information to the alignment
        lineId1 = halignment.addLineFixed(Ge.Point2d(0,0),Ge.Point2d(5.0,0))
        lineId2 = halignment.addLineFixed(Ge.Point2d(10,10),Ge.Point2d(10,15))
        autoSCSId = halignment.addSCSAuto(lineId1, lineId2)
        halignmentId = model.appendAcDbEntity(halignment)

        # create a vertical alignment
        valignment = Cv.CvDbVAlignment()
        # adding information to the alignment
        tangentId1 = valignment.addTangentFixed(Ge.Point2d(0,0),Ge.Point2d(4,4))
        tangentId2 = valignment.addTangentFixed(Ge.Point2d(10,8),Ge.Point2d(50,4))
        autoParabola1 = valignment.addParabolaAuto(tangentId1, tangentId2)
        valignment.setBaseHAlignment(halignmentId)
        valignmentId = model.appendAcDbEntity(valignment)

        # creating a vertical alignment view
        valignmentView = Cv.CvDbVAlignmentView()
        valignmentView.setBaseHAlignment(halignmentId)
        valignmentView.setOrigin(Ge.Point2d(0,-15))
        valignmentVIewId = model.appendAcDbEntity(valignmentView)

        # create 3d alignment from horizontal and vertical alignment
        alignment3d = Cv.CvDb3dAlignment()
        alignment3d.setBaseHAlignment(halignmentId)
        alignment3d.setVAlignment(valignmentId)
        valignmentViewId = model.appendAcDbEntity(alignment3d)

        # change colors
        halignment.setLineElementColor(256)
        halignment.setCurveElementColor(2)
        halignment.setSpiralElementColor(3)
        halignment.setTangentExtensionColor(4)
        style = (
            Cv.HAlignmentVisualStyle.eElements
            | Cv.HAlignmentVisualStyle.eTangentExtensions
            | Cv.HAlignmentVisualStyle.eElementExtensions
        )
        halignment.setStyle(style)

        valignment.setLineElementColor(256)
        valignment.setCurveElementColor(5)
        valignment.setTangentPolygonColor(6)
        style = (
            Cv.VAlignmentVisualStyle.eElements
            | Cv.VAlignmentVisualStyle.eTangents
            | Cv.VAlignmentVisualStyle.eElements
        )
        valignment.setStyle(style)

        # add another vertical aligment to horizontal alignment and the same view
        valignment2 = Cv.CvDbVAlignment()
        # adding information to the alignment
        tangentId1 = valignment2.addTangentFixed(Ge.Point2d(5,5),Ge.Point2d(9,6))
        tangentId2 = valignment2.addTangentFixed(Ge.Point2d(9,6),Ge.Point2d(15,5))
        valignment2.setBaseHAlignment(halignmentId)
        valignment2Id = model.appendAcDbEntity(valignment2)

        # set name and description for horizontal alignment
        halignment.setName("Sample name")
        halignment.setDescription("This is sample description")

        # set starting station for horizontal alignment
        stationEquations = halignment.stationEquations()
        refStartLength = stationEquations.getRefStartingLength()
        newStartingStation = 10.5
        stationEquations.setRefRawStartingStation(newStartingStation+refStartLength)
        halignment.setStationEquations(stationEquations)

    except Exception as err:
        print(err)

def PyRxCmd_samp_alignmentreport():
    try:
        data = {
            "Element": [],
            "Length": [],
            "Radius": [],
            "A Value": [],
            "Direction": [],
            "Start Point": [],
            "End Point": [],
        }
                
        db = Db.curDb()
        
        esel = Ed.Editor.entSel("\nSelect Horizontal Alignment: ", Cv.CvDbHAlignment.desc())
        if esel[0] != Ed.PromptStatus.eOk:
            print("Not a Horizontal Alignment{}: ".format(esel[0])) 
            return

        # fetching basic alignment info
        hAlignment = Cv.CvDbHAlignment(esel[1], Db.OpenMode.kForRead)
        stationEquations = hAlignment.stationEquations()
        startStation = stationEquations.getStartingStation()
        rawEndStation = stationEquations.getRawStationFromLength(hAlignment.length())
        stopStation = stationEquations.getStation(rawEndStation)

        # looping through alignment elements (only line+scs)
        for i in range(1, hAlignment.elementCount()+1):
            element : Cv.CvDbHAlignmentElement = hAlignment.elementAtId(hAlignment.getElementId(i))
            if Cv.HAlignmentElementType.eLine == element.type():
                line: Cv.CvDbHAlignmentLine = Cv.CvDbHAlignmentLine.cast(element)
                data["Element"].append("L"+str(i))
                data["Length"].append(line.length())
                data["Radius"].append(None)
                data["A Value"].append(None)
                data["Direction"].append(angle_to(line.startPoint(), line.endPoint()))
                data["Start Point"].append(line.startPoint().toTuple())
                data["End Point"].append(line.endPoint().toTuple())
            elif Cv.HAlignmentElementType.eSpiralCurveSpiral == element.type():
                scs: Cv.CvDbHAlignmentSCS = Cv.CvDbHAlignmentSCS.cast(element)
                try:
                    spiralIn: Cv.CvDbHAlignmentSpiral = scs.spiralIn()
                    data["Element"].append("Sin"+str(i))
                    data["Length"].append(spiralIn.length())
                    data["Radius"].append("Infinity")
                    data["A Value"].append(spiralIn.paramA())
                    data["Direction"].append(angle_to(spiralIn.startPoint(), spiralIn.endPoint()))
                    data["Start Point"].append(spiralIn.startPoint().toTuple())
                    data["End Point"].append(spiralIn.endPoint().toTuple())
                except Exception as err:
                    print(err)
                try:
                    arc: Cv.CvDbHAlignmentArc = scs.arc()
                    data["Element"].append("C"+str(i))
                    data["Length"].append(arc.length())
                    data["Radius"].append(arc.radius())
                    data["A Value"].append(None)
                    data["Direction"].append(angle_to(arc.startPoint(), arc.endPoint()))
                    data["Start Point"].append(arc.startPoint().toTuple())
                    data["End Point"].append(arc.endPoint().toTuple())
                except Exception as err:
                    print(err)
                try:
                    spiralOut: Cv.CvDbHAlignmentSpiral = scs.spiralOut()
                    data["Element"].append("Sout"+str(i))
                    data["Length"].append(spiralOut.length())
                    data["Radius"].append("Infinity")
                    data["A Value"].append(spiralOut.paramA())
                    data["Direction"].append(angle_to(spiralOut.startPoint(), spiralOut.endPoint()))
                    data["Start Point"].append(spiralOut.startPoint().toTuple())
                    data["End Point"].append(spiralOut.endPoint().toTuple())
                except Exception as err:
                    print(err)
            else:
                print("Not checking on " + element.type())
                # fill empty table values to conform with layout
                data["Element"].append("N"+str(i))
                data["Length"].append(None)
                data["Radius"].append(None)
                data["A Value"].append(None)
                data["Direction"].append(None)
                data["Start Point"].append(None)
                data["End Point"].append(None)

        df = pd.DataFrame(data)
        print(df)

        table = Db.Table()
        # add one for the title and header
        table.setSize(df.shape[0]+3, df.shape[1])
        table.setColumnWidth(130)
        table.setRowHeight(20)
        titleColor = Db.Color()
        titleColor.setRGB(0,63,255)        
        titleTextColor = Db.Color()
        titleTextColor.setRGB(255,63,255)
        table.generateLayout()
        table.setDatabaseDefaults()

        # title
        if hAlignment.name != "":
            table.setTextString(0, 0, "Alignment " + hAlignment.name())
            table.mergeCells(0,0,0,table.numColumns()-1)
            table.setBackgroundColor(0,0, titleColor)
            table.setContentColor(0,0,0, titleTextColor)

        # subtitle
        if stopStation:
            table.setTextString(1, 0, "Starting station: " + str(startStation) + ", Stop station: " + str(stopStation))
            table.mergeCells(1,1,0,table.numColumns()-1)
            table.setBackgroundColor(1,0, titleColor)
            table.setContentColor(1,0,0, titleTextColor)

        headers = df.columns.values.tolist()
        datas = df.values.tolist()
 
        for col, value in enumerate(headers):
            table.setTextString(2, col, "{}".format(value))
 
        for row, data in enumerate(datas):
            for col, value in enumerate(data):
                table.setTextString(row+3, col, "{}".format(value))
 
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(table)

    except Exception as err:
        print(err)
