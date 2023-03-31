#include "stdafx.h"
#include "ResultBuffer.h"
#include "PyDbObjectId.h"

boost::python::list resbufToList(resbuf* pRb)
{
    boost::python::list list;
    for (resbuf* pTail = pRb; pTail != pRb; pTail = pTail->rbnext)
    {
        if (pTail->restype < 5000)
        {
            switch (acdbGroupCodeToType(pTail->restype))
            {
                case AcDb::kDwgText:
                    list.append(boost::python::make_tuple(pTail->restype, wstr_to_utf8(pRb->resval.rstring)));
                    break;
                case AcDb::kDwgInt8:
                    list.append(boost::python::make_tuple(pTail->restype, pRb->resval.rint));
                    break;
                case AcDb::kDwgInt16:
                    list.append(boost::python::make_tuple(pTail->restype, pRb->resval.rint));
                    break;
                case AcDb::kDwgInt32:
                    list.append(boost::python::make_tuple(pTail->restype, pRb->resval.rlong));
                    break;
                case AcDb::kDwgReal:
                    list.append(boost::python::make_tuple(pTail->restype, pRb->resval.rreal));
                    break;
                case AcDb::kDwg3Real:
                    list.append(boost::python::make_tuple(pTail->restype, asPnt3d(pRb->resval.rpoint)));
                    break;
                case AcDb::kDwgHandle:
                case AcDb::kDwgHardOwnershipId:
                case AcDb::kDwgSoftOwnershipId:
                case AcDb::kDwgHardPointerId:
                case AcDb::kDwgSoftPointerId:
                {
                    AcDbObjectId id;
                    if (acdbGetObjectId(id, pRb->resval.rlname) == eOk)
                        list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
                }
                break;
            }
        }
    }
    return list;
}
