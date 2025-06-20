import traceback

from pyrx import Ed


def PyRxCmd_entselkw():
    try:
        Ed.Editor.initGet(1, "Import Create")
        es, id, pnt = Ed.Editor.entSel("\nEnter an option [Import/Create]: ")
        if es == Ed.PromptStatus.eKeyword:
            input = Ed.Editor.getInput()
            match input:
                case "Import":
                    print("\nImport was pressed")
                case "Create":
                    print("\nCreate was pressed")
                case _:
                    print("\nSet a default value")
        elif es == Ed.PromptStatus.eNone:
            print("\noops try again")
        elif es == Ed.PromptStatus.eCancel:
            print("\nyou canceled")
        elif es == Ed.PromptStatus.eRejected:
            print("\nWrong type!")
        elif es == Ed.PromptStatus.eOk:
            print("\nWoohoo! {} {} {}".format(es, id, pnt))
        elif es == Ed.PromptStatus.eError:
            print("\nError!")
    except Exception:
        traceback.print_exc()


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


def PyRxCmd_doprompt3():
    try:
        Ed.Editor.initGet(0, "Yes No")
        mgs = "\nEnter an option [Yes/No] <{}>: ".format("No")
        ps, str = Ed.Editor.getKword(mgs)
        if ps == Ed.PromptStatus.eError or ps == Ed.PromptStatus.eCancel:
            return
        elif ps == Ed.PromptStatus.eNone:
            print("Nothing was pressed so no is default")
            return

        match str:
            case "Yes":
                print("Yes was pressed")
            case "No":
                print("No was pressed")
            case _:
                print("oof")

    except Exception as err:
        traceback.print_exception(err)
