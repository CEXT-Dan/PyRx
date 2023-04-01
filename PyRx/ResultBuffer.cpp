#include "stdafx.h"
#include "ResultBuffer.h"
#include "PyDbObjectId.h"
using namespace boost::python;

resbuf* listToResbuf(const boost::python::list& bpl)
{
    try
    {
        //NULL is valid!
        const size_t listSize = boost::python::len(bpl);
        if (listSize == 0)
            return nullptr;

        resbuf* pRbRead = acutNewRb(RTLB);
        resbuf* pTail = pRbRead;

        for (size_t idx = 0; idx < listSize; idx++)
        {
            tuple tpl = extract<tuple>(bpl[idx]);
            if (boost::python::len(tpl) != 2)
                throw PyAcadErrorStatus(Acad::eInvalidInput);

            int code = extract<int>(tpl[0]);
            if (code < 5000)
            {
                switch (acdbGroupCodeToType(code))
                {
                    case AcDb::kDwgText:
                    {
                        int _code = code == 0 ? RTDXF0 : code;
                        AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                        pTail->rbnext = acutBuildList(_code, (const TCHAR*)str, 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwgInt8:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwgInt16:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwgInt32:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwgReal:
                    {
                        pTail->rbnext = acutBuildList(code, extract<double>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwg3Real:
                    {
                        pTail->rbnext = acutBuildList(code, asDblArray(extract<AcGePoint3d>(tpl[1])), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case AcDb::kDwgHandle:
                    case AcDb::kDwgHardOwnershipId:
                    case AcDb::kDwgSoftOwnershipId:
                    case AcDb::kDwgHardPointerId:
                    case AcDb::kDwgSoftPointerId:
                    {
                        ads_name name = { 0L };
                        PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                        if (acdbGetAdsName(name, id.m_id) == eOk)
                        {
                            pTail->rbnext = acutBuildList(code, name, 0);
                            if (pTail->rbnext != nullptr)
                                pTail = pTail->rbnext;
                        }
                    }
                    break;
                }
            }
            else
            {
                switch (code)
                {
                    case RTT:
                    case RTDXF0:
                    case RTNIL:
                    case RTDOTE:
                    case RTVOID:
                    case RTLB:
                    case RTLE:
                    case RTNONE:
                    {
                        pTail->rbnext = acutBuildList(code, 0, 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTANG:
                    case RTREAL:
                    {
                        pTail->rbnext = acutBuildList(code, extract<double>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTORINT:
                    case RT3DPOINT:
                    {
                        pTail->rbnext = acutBuildList(code, asDblArray(extract<AcGePoint3d>(tpl[1])), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTPOINT:
                    {
                        pTail->rbnext = acutBuildList(code, asDblArray(extract<AcGePoint2d>(tpl[1])), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTSHORT:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTLONG:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTLONG_PTR:
                    case RTINT64:
                    {
                        pTail->rbnext = acutBuildList(code, extract<int64_t>(tpl[1]), 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTSTR:
                    {
                        AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                        pTail->rbnext = acutBuildList(code, (const TCHAR*)str, 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                        break;
                    }
                    case RTPICKS:
                    case RTENAME:
                    {
                        {
                            ads_name name = { 0L };
                            PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                            if (acdbGetAdsName(name, id.m_id) == eOk)
                            {
                                pTail->rbnext = acutBuildList(code, name, 0);
                                if (pTail->rbnext != nullptr)
                                    pTail = pTail->rbnext;
                            }
                        }
                    }
                    break;
#ifdef NEVER
                    case RTRESBUF:
                    {
                        list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rbinary.buf));
                    }
                    break;
#endif
                }
            }
        }
        //we created a RTLB, detach it and return next 
        resbuf* rbToReturn = pRbRead->rbnext;
        pRbRead->rbnext = nullptr;
        acutRelRb(pRbRead);
        return rbToReturn; 
    }
    catch (...)
    {
        //TODO: throw something here
    }
    return nullptr;
}

boost::python::list resbufToList(resbuf* pRb)
{
    boost::python::list list;
    for (resbuf* pTail = pRb; pTail != nullptr; pTail = pTail->rbnext)
    {
        if (pTail->restype < 5000)
        {
            switch (acdbGroupCodeToType(pTail->restype))
            {
                case AcDb::kDwgText:
                    list.append(boost::python::make_tuple(pTail->restype, wstr_to_utf8(pTail->resval.rstring)));
                    break;
                case AcDb::kDwgInt8:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                    break;
                case AcDb::kDwgInt16:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                    break;
                case AcDb::kDwgInt32:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rlong));
                    break;
                case AcDb::kDwgReal:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rreal));
                    break;
                case AcDb::kDwg3Real:
                    list.append(boost::python::make_tuple(pTail->restype, asPnt3d(pTail->resval.rpoint)));
                    break;
                case AcDb::kDwgHandle:
                case AcDb::kDwgHardOwnershipId:
                case AcDb::kDwgSoftOwnershipId:
                case AcDb::kDwgHardPointerId:
                case AcDb::kDwgSoftPointerId:
                {
                    AcDbObjectId id;
                    if (acdbGetObjectId(id, pTail->resval.rlname) == eOk)
                        list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
                }
                break;
            }
        }
        else
        {
            switch (pTail->restype)
            {
                case RTT:
                case RTDXF0:
                case RTNIL:
                case RTDOTE:
                case RTVOID:
                case RTLB:
                case RTLE:
                case RTNONE:
                    list.append(boost::python::make_tuple(pTail->restype, 0));
                    break;
                case RTANG:
                case RTREAL:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rreal));
                    break;
                case RTORINT:
                case RT3DPOINT:
                    list.append(boost::python::make_tuple(pTail->restype, asPnt3d(pTail->resval.rpoint)));
                    break;
                case RTPOINT:
                    list.append(boost::python::make_tuple(pTail->restype, asPnt2d(pTail->resval.rpoint)));
                    break;
                case RTSHORT:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                    break;
                case RTLONG:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rlong));
                    break;
                case RTLONG_PTR:
                case RTINT64:
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.mnInt64));
                    break;
                case RTSTR:
                    list.append(boost::python::make_tuple(pTail->restype, wstr_to_utf8(pTail->resval.rstring)));
                    break;
                case RTPICKS:
                case RTENAME:
                {
                    AcDbObjectId id;
                    if (acdbGetObjectId(id, pTail->resval.rlname) == eOk)
                        list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
                }
                break;
#ifdef NEVER
                case RTRESBUF:
                {
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rbinary.buf));
                }
                break;
#endif
            }
        }
    }
    return list;
}
