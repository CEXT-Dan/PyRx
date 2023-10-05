import sys
from win32com.client import makepy
import PyRx

print("run command makeComWrappers")

def makeComAcadApplication24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ComAcadApplication24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acax24ENU.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComAcadDBX24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ComAcadDBX24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\axdb24enu.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()

def makeComETransmit20():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ComETransmit20.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\AcETransmit20.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComSmcomponents24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ComSmcomponents24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acsmcomponents24.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def PyRxCmd_makeComWrappers():
    makeComAcadApplication24()
    makeComAcadDBX24() # i don't know how to make these work.. boo!
    makeComETransmit20()
    makeComSmcomponents24()
    print("done")

