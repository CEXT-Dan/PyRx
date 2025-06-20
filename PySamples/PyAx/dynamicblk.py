from pyrx import Ap, Ax

print("added command PYDYN1")

@Ap.Command()
def pydyn1():
    try:
        axApp = Ap.Application.acadApplication()
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        axSet = axSets.add("PYRX")
        axSet.selectOnScreen([(0, "INSERT")])
 
        for axEnt in axSet:
            axRef = Ax.AcadBlockReference.cast(axEnt)
            if axRef.isDynamicBlock():
                for prop in axRef.dynamicBlockProperties():
                    print(prop.value(), prop.propertyName(), prop.allowedValues())
    finally:
        axSet.delete()
