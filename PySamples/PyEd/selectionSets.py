from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command = pyselectall")
print("added command = pyselectallf")

#The SelectionSet class has resources that should be cleared 
#if the class is created in the global scope, clean up when you're done
#using del

def PyRxCmd_pyselectall():
    try:
        # returns a tuple (PromptStatus, SelectionSet)
        ssres =Ed.Editor.selectAll()

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
	     print(err)


def PyRxCmd_pyselectallf():
    try:
        #example using a filter
        # create a filter, a list of tuples
        filter = [(Db.DxfCode.kDxfStart, "CIRCLE"),  # type
                  (Db.DxfCode.kDxfLayerName, "0")]  # layer

        # lots of lisp samples use int for DxfCode, should work here as well
        # filter = [(0, "CIRCLE"),  # type
        #          (8, "0")]  # layer

        # returns a tuple (PromptStatus, SelectionSet)
        ssres = Ed.Editor.selectAll(filter)

        # check if we have a set
        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
            print(selection.size())

    except Exception as err:
	    print(err)
     
def PyRxCmd_pyselectf():
    try:
        # example using a filter
        # create a filter, a list of tuples
        filter = [(Db.DxfCode.kDxfStart, "LINE,CIRCLE"),  # type
                  (Db.DxfCode.kDxfLayerName, "0")]  # layer

        # lots of lisp samples use int for DxfCode, should work here as well
        # filter = [(0, "LINE,CIRCLE"),  # type
        #          (8, "0")]  # layer
        
        # returns a tuple (PromptStatus, SelectionSet)
        ssres = Ed.Editor.select(filter)

        # check if we have a set
        if ssres[0] == Ed.PromptStatus.eNormal:
          
            #get all Ids
            ids = ssres[1].objectIds()
          
            #just get the lines
            lineIds = ssres[1].objectIds(Db.Line.desc())
            
            #just get the circles
            circleIds = ssres[1].objectIds(Db.Circle.desc())
            
            print("call = {}".format(len(ids)))
            print("Lines = {}".format(len(lineIds)))
            print("Circles = {}".format(len(circleIds)))

    except Exception as err:
	    print(err)

#this is just in case one of the supplied wrappers doesn't fit, roll you own
def PyRxCmd_pyssget1():
  try:
    #pass points using a list
    ssResult = Ed.Editor.ssget("F",[Ge.Point3d(0,0,0),Ge.Point3d(100,100,0)],None)
    if ssResult[0] == Ed.PromptStatus.eNormal : 
      print(len(ssResult[1].toList()))
  except Exception as err:
    print(err)

def PyRxCmd_pyssget2():
  try:
    #note this is a tuple
    ssResult = Ed.Editor.ssget("_:$",("MYADD","MYREMOVE"),None)
    if ssResult[0] == Ed.PromptStatus.eNormal : 
      print(len(ssResult[1].toList()))
  except Exception as err:
    print(err)

def PyRxCmd_pyssget3():
  try:
    ssResult = Ed.Editor.ssget("_:n",None,None)
    if ssResult[0] != Ed.PromptStatus.eNormal :
      return 
    ss = ssResult[1]
    nestedInfo = ss.ssNameX()
    print(nestedInfo)
  except Exception as err:
    print(err)
    
def PyRxCmd_pyssget4():
  try:
    ssResult = Ed.Editor.selectPrompt("Add", "Remove")
    if ssResult[0] == Ed.PromptStatus.eNormal : 
      print(len(ssResult[1].toList()))
  except Exception as err:
    print(err)