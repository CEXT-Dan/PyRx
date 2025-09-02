from pyrx import Ap, Ax, Db, Ed, Ge

@Ap.Command()
def dumpdxf():
    try:
        with open("dumpdxf.txt", "w") as f:
            db = Db.curDb()
            for id in db.objectIds():
                dbo = Db.DbObject(id)
                try:
                    dxf = Db.SnoopDxfFiler()
                    dbo.snoopdxf(dxf)
                    f.write("\n{} - {}".format(dbo.getHandle(), dxf.buffer()))
                except:
                    print("\nFailed", dbo.isA().name())
    except Exception as err:
        print(err)


@Ap.Command()
def dumpdwg():
    try:
        with open("dumpdwg.txt", "w") as f:
            db = Db.curDb()
            for id in db.objectIds():
                dbo = Db.DbObject(id)
                try:
                    dwg = Db.SnoopDwgFiler()
                    dbo.snoop(dwg)
                    f.write("\n{} - {}".format(dbo.getHandle(), dwg.buffer()))
                except:
                    print("\nFailed", dbo.isA().name())
    except Exception as err:
        print(err)
