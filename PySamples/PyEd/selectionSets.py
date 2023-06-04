import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = pyselectall")
print("added command = pyselectallf")


def PyRxCmd_pyselectall():
    try:

        # get the Editor class
        ed = Ed.Editor()

        # returns a tuple (PromptStatus, SelectionSet)
        ssres = ed.selectAll()

        # check if we have a set
        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
            print(selection.size())

            # returns a list of objectids
            ids = selection.toList()
            print(ids)

            # check if item exists in the set
            print(selection.hasMember(ids[0]))

            # remove item from the set
            selection.remove(ids[0])
            print(selection.size())
            print(selection.hasMember(ids[0]))

            # add item to the set
            selection.add(ids[0])
            print(selection.hasMember(ids[0]))
            print(selection.size())

    except Exception as err:
	    PyRxApp.Printf(err)


def PyRxCmd_pyselectallf():
    try:
        # create a filter, a list of tuples
        filter = [(Db.DxfCode.kDxfStart, "CIRCLE"),  # type
                  (Db.DxfCode.kDxfLayerName, "0")]  # layer

        # lots of lisp samples use int for DxfCode, should work here as well
        # filter = [(0, "CIRCLE"),  # type
        #          (8, "0")]  # layer

        # get the Editor class
        ed = Ed.Editor()

        # returns a tuple (PromptStatus, SelectionSet)
        ssres = ed.selectAll(filter)

        # check if we have a set
        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
            print(selection.size())

    except Exception as err:
	    print(err)
