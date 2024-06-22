from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
import traceback


def PyRxCmd_doprompt1():
    try:

        Ed.Editor.initGet(1, "Merge Create")
        res = Ed.Editor.getKword("\nEnter an option [Merge/Create]: ")
        if res[0] != Ed.PromptStatus.eOk:
            raise Exception(res)

        match res[1]:
            case "Merge":
                print("Merge was pressed")
            case "Create":
                print("Create was pressed")
            case _:
                print("Set a default value")

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_doprompt2():
    try:

        Ed.Editor.initGet(0, "Merge Create")
        mgs = "\nEnter an option [Merge/Create] <{}>: ".format("Create")
        res = Ed.Editor.getKword(mgs)
        if res[0] == Ed.PromptStatus.eError or res[0] == Ed.PromptStatus.eCancel:
            return
        elif res[0] == Ed.PromptStatus.eNone:
            print("Create was pressed")
            return

        match res[1]:
            case "Merge":
                print("Merge was pressed")
            case "Create":
                print("Create was pressed")
            case _:
                print("Set a default value")

    except Exception as err:
        traceback.print_exception(err)
