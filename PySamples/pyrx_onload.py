# loads the first found!
# put this next to the main module or somewhere in your AutoCAD's search path

# # import
# import traceback;

# def OnPyInitApp() -> None:
#     print("\nOnPyInitApp")

# def OnPyUnloadApp() -> None:
#     print("\nOnPyUnloadApp")

# def OnPyReload() -> None:
#     print("\nOnPyReload")

# def OnPyLoadDwg() -> None:
#     print("\nOnPyLoadDwg")

# def OnPyUnloadDwg() -> None:
#     print("\nOnPyUnloadDwg")

# def PyRxCmd_mycommand(CmdFlags=Ap.CmdFlags.TRANSPARENT) -> None:
#     try:
#         print("Hello world!")
#     except Exception as err:
#         traceback.print_exception(err)

# def PyRxLisp_mylisp(args):
#     try:
#         return args
#     except Exception as err:
#         print(err)

print("PY_ONLOAD")
