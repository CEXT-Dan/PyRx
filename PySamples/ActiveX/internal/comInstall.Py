import sys
from win32com.client import makepy
import PyRx

print("run command makeComWrappers")

def makeComAcadApplication24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acax24ENU.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComAcadDBX24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AcadDBX24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\axdb24enu.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComETransmit20():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxETransmit20.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\AcETransmit20.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComSmcomponents24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxSmcomponents24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acsmcomponents24.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    

def makeComBcadApplication24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\BxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\BRXSDKV24\inc-x64\axbricscadapp1.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComBcadDB24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\BxDb24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\BRXSDKV24\inc-x64\axbricscaddb1.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComZcadApp24():
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ZxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ZWCAD_2024_ZRXSDK\lib-x64\zwcad21.tlb"
    sys.argv = ["makepy", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def PyRxCmd_makeComWrappers():
    #makeComAcadApplication24()
    #makeComAcadDBX24()
    #makeComETransmit20()
    #makeComSmcomponents24()
    #makeComBcadApplication24()
    #makeComBcadDB24()
    makeComZcadApp24()
    print("done")

