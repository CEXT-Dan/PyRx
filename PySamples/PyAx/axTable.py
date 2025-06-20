from pyrx import Ap, Ax, Ge, command

print("added command - axTable")

@command
def axTable():
    axApp = Ap.Application.acadApplication()
    axDoc = axApp.activeDocument()
    axModel = axDoc.modelSpace()
    axTable = axModel.addTable(Ge.Point3d(0, 0, 0), 7, 5, 1, 5)

    axTable.setText(0, 0, "woowhoo")
    print(axTable.text(0, 0))

    cex11 = axTable.cellExtents(1, 1, False)
    cex43 = axTable.cellExtents(4, 3, False)

    sssub = axTable.selectSubRegion(
        cex11[0],
        cex43[3],
        Ge.Vector3d.kZAxis,
        Ge.Vector3d.kXAxis,
        Ax.AcSelectType.acTableSelectCrossing,
        False,
    )

    axTable.setSubSelection(*sssub)

    pnt = cex11[0] + (cex43[3] - cex11[0]) * 0.5
    bhit, row, col = axTable.hitTest(pnt, Ge.Vector3d.kZAxis)

    axTable.setCellTextHeight(row, col, 0.8)
    axTable.setText(row, col, "Bingo")
