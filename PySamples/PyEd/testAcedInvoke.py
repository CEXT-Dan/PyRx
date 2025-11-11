from pyrx import Ap, Ed, Rx

# args must end with (Rx.LispType.kNone,0)


#  (defun C:ADDNUM ( x / ) (+ x x))
@Ap.Command()
def doit1(CmDFlags=Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:ADDNUM"), (Rx.LispType.kInt16, 10), (Rx.LispType.kNone, 0)]
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        print(err)

    #  (defun C:GETLASTENT () (entget(entlast)))


@Ap.Command()
def doit2(CmDFlags=Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:GETLASTENT"), (Rx.LispType.kNone, 0)]
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        print(err)


#  (defun C:GETENTSEL () (entget(car(entsel))))
@Ap.Command()
def doit3():
    try:
        args = [(Rx.LispType.kText, "C:GETENTSEL"), (Rx.LispType.kNone, 0)]
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        print(err)
