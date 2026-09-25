import traceback
from pyrx import Ap, Db, Ge, Ed


@Ap.Command()
def CreateNewDynamicBlock():
    try:
        db = Db.curDb()

        # Prompt for the new dynamic block name
        ps, blkname = Ed.Editor.getString("\nEnter new dynamic block name to create: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError(f"Prompt status failed: {ps}")

        # Check if the block already exists; if not, create a new one
        bt = Db.BlockTable(db.blockTableId(), Db.OpenMode.kForWrite)
        if bt.has(blkname):
            raise RuntimeError(f"Block '{blkname}' already exists. Please choose a new name.")

        btr = Db.BlockTableRecord()
        btr.setName(blkname)
        blkid = bt.add(btr)

        # add something visible
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 5)
        btr.appendAcDbEntity(circle)

        # Initialize/Retrieve the modern ACAD_ASSOCNETWORK
        networkId = Db.AssocNetwork.getInstanceFromObject(blkid, True, True, "ACAD_ASSOCNETWORK")
        network = Db.AssocNetwork(networkId, Db.OpenMode.kForWrite)

        # Create and attach the legacy ACAD_ENHANCEDBLOCK Graph
        if not Db.EvalGraph.hasGraph(btr, "ACAD_ENHANCEDBLOCK"):
            Db.EvalGraph.createGraph(btr, "ACAD_ENHANCEDBLOCK")
        graph = Db.EvalGraph.getGraph(btr, "ACAD_ENHANCEDBLOCK", Db.OpenMode.kForWrite)

        # Instantiate and configure the Associative Variable
        newvar = Db.AssocVariable()
        newvar.setName("Slope_Factor", False)
        newvar.setValue(Db.EvalVariant(10.00))
        newvar.setEvaluatorId("AcDbCalc:1.0")
        newvar.setDescription("Calculates height variants based on slope run.")

        # Post the variable object directly to the database
        varId = db.addObject(newvar)
        network.addAction(varId, True)

        # Bridge the variable into the Dynamic Block EvalGraph
        param = Db.BlockUserParameter()
        param.setAssocVarId(varId)
        param.setName(newvar.name())
        param.setUserVarDescription(newvar.description())
        nodeid = graph.addNode(param)

        # create a ref and add it
        ref = Db.BlockReference(Ge.Point3d(0, 0, 0), blkid)
        model = db.modelSpace(Db.OpenMode.kForWrite)
        model.appendAcDbEntity(ref)

        print(f"\nSuccessfully created dynamic block '{blkname}'!")
        print(f"Graph Node ID: {nodeid} Linked Param ID: {varId}")

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def checkNewDynamicBlock():
    try:
        # Prompt for the new dynamic block name
        ps, blkname = Ed.Editor.getString("\nEnter dynamic block name: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Prompt status failed: {}".format(ps))

        db = Db.curDb()
        bt = Db.BlockTable(db.blockTableId())

        if not bt.has(blkname):
            raise RuntimeError("Block not found: {}".format(blkname))

        blkid = bt.getAt(blkname)
        btr = Db.BlockTableRecord(blkid)

        if not Db.EvalGraph.hasGraph(btr, "ACAD_ENHANCEDBLOCK"):
            raise RuntimeError("Ooooof yeeet: {}")

        gr = Db.EvalGraph.getGraph(btr, "ACAD_ENHANCEDBLOCK", Db.OpenMode.kForRead)
        for node in gr.getAllNodes():
            dbo = gr.getNode(node, Db.OpenMode.kForRead)
            if dbo.isA() == Db.BlockUserParameter.desc():
                ub = Db.BlockUserParameter.cast(dbo)
                var = Db.AssocVariable(ub.assocVarId())
                print(var.name(), var.description(), var.value().toString())

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def dyndump():
    try:
        db = Db.curDb()
        for id in db.objectIds(Db.BlockUserParameter.desc()):
            dbo = Db.DbObject(id)
            idx = 0
            for item, var in dbo.dwgDump():
                print((idx, item, var))
                idx += 1
    except Exception as err:
        print(f"Error : {err}")
 