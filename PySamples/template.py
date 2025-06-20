# import
import traceback

from pyrx import Ap


# called when the app is loaded
def OnPyInitApp():
    print("\nOnPyInitApp")


# called when the app is inloaded
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


# called the pyreload command ic called on THIS module
def OnPyReload():
    print("\nOnPyReload")


# called when a drawing is opened
def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


# called when a drawing is closed
def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


# CmdFlags is optional, default is modal
@Ap.Command()
def mycommand(CmdFlags=Ap.CmdFlags.TRANSPARENT):
    try:
        print("Hello world!")
    except Exception as err:
        traceback.print_exception(err)


# (mylisp '("hello world" 1 2 3 4 (1 10 100)))
@Ap.LispFunction()
def mylisp(args):
    try:
        return args
    except Exception as err:
        print(err)
