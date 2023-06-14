import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = pyselectall")
print("added command = pyselectallf")

#The SelectionSet class has resources that should be cleared 
#if the class is created in the global scope, clean up when you're done
#using del

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
        #example using a filter
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

#this is just in case one of the supplied wrappers doesn't fit, roll you own
def PyRxCmd_pyuserselect():
  try:
    ssResult = Ed.Editor.ssget("F",[Ge.Point3d(0,0,0),Ge.Point3d(100,100,0)],None)
    if ssResult[0] == Ed.PromptStatus.eNormal : 
      print(len(ssResult[1].toList()))
    
  except Exception as err:
    print(err)
