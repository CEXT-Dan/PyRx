import traceback

from pyrx import Ap, Brx, Db, Ed


@Ap.Command()
def doit():
    try:

        desc = Db.BlockReference.desc()
        ps, id, _ = Ed.Editor.entSel("\nSelect a block ref", desc)
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Oops! {}: ".format(ps))

        #check the type of the value is a kString
        val = Brx.DbProperties.getValue(id, "Northpoint_Angle~MCAD")
        print("\nDataType = {}".format(val.dataType()))

        # [in] id the ObjectId of any AcDbObject to be verified
        # [in] the unqualified or qualified property name
        
        # [out] tuple(propertyName, isReadonly) 
        # the fully qualified property name always (if found)
        # true if the property is read-only, false if write-enabled
        updatedName, isReadonly = Brx.DbProperties.isReadOnly(id, "Northpoint_Angle~MCAD")
        if isReadonly:
            print("oops {}, it's read only".format(updatedName))
            return

        # Set the Value, mind the type as of (SR198285)
        # Brx will try to convert this
        Brx.DbProperties.setValue(id, updatedName, Db.AcValue("45"))

    except Exception as err:
        traceback.print_exception(err)
