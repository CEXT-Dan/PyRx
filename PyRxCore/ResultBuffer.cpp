#include "stdafx.h"
#include "ResultBuffer.h"
#include "PyDbObjectId.h"
#include "PyEdSelectionSet.h"
#include "PyRxApp.h"
using namespace boost::python;

static resbuf* makebin(const boost::python::object& bpl, int code)
{
    boost::python::object inbuf = bpl;
    if (!PyObject_CheckBuffer(inbuf.ptr()))
        PyThrowBadEs(eInvalidInput);
    Py_buffer view;
    if (PyObject_GetBuffer(inbuf.ptr(), &view, PyBUF_SIMPLE) == -1)
        PyThrowBadEs(eInvalidInput);
    resbuf* pRb = acutNewRb(code);
    pRb->rbnext = nullptr;
    acutNewBuffer(pRb->resval.rbinary.buf, view.len);
    memcpy_s(pRb->resval.rbinary.buf, view.len, view.buf, view.len);
    pRb->resval.rbinary.clen = static_cast<short>(view.len);
    PyBuffer_Release(&view);
    return pRb;
}

resbuf* listToResbuf(const boost::python::object& bpl)
{
    struct ResbufGuard
    {
        resbuf* head = nullptr;

        ~ResbufGuard()
        {
            if (head != nullptr)
                acutRelRb(head);
        }

        resbuf* release()
        {
            resbuf* tmp = head;
            head = nullptr;
            return tmp;
        }
    };

    PyAutoLockGIL lock;

    try
    {
        const size_t listSize = boost::python::len(bpl);
        if (listSize == 0)
            return nullptr;

        ResbufGuard guard;
        guard.head = acutNewRb(RTLB);
        resbuf* pTail = guard.head;

        auto appendRb = [&](int code) -> resbuf*
            {
                pTail->rbnext = acutNewRb(code);
                pTail = pTail->rbnext;
                return pTail;
            };

        for (size_t idx = 0; idx < listSize; ++idx)
        {
            tuple tpl = extract<tuple>(bpl[idx]);
            if (boost::python::len(tpl) != 2)
                throw PyErrorStatusException(Acad::eInvalidInput);

            const int code = extract<int>(tpl[0]);

            if (code < 5000)
            {
                switch (acdbGroupCodeToType(code))
                {
                    case AcDb::kDwgText:
                    {
                        std::wstring str;
                        if (extract<std::string>(tpl[1]).check())
                            str = utf8_to_wstr(extract<std::string>(tpl[1]));
                        else
                            str = L"";
                        appendRb(code)->resval.rstring = wcsdup(str.c_str());
                        break;
                    }
                    case AcDb::kDwgInt8:
                    case AcDb::kDwgInt16:
                    {
                        const int val = extract<int>(tpl[1]);
                        if (val < SHRT_MIN || val > SHRT_MAX)
                            throw PyErrorStatusException(Acad::eInvalidInput);
                        appendRb(code)->resval.rint = static_cast<short>(val);
                        break;
                    }
                    case AcDb::kDwgInt32:
                    {
                        appendRb(code)->resval.rlong = extract<int>(tpl[1]);
                        break;
                    }
                    case AcDb::kDwgReal:
                    {
                        appendRb(code)->resval.rreal = extract<double>(tpl[1]);
                        break;
                    }
                    case AcDb::kDwg3Real:
                    {
                        if (extract<AcGePoint3d>(tpl[1]).check())
                        {
                            const auto val = asDblArray(extract<AcGePoint3d>(tpl[1]));
                            memcpy(appendRb(code)->resval.rpoint, val, sizeof(ads_point));
                        }
                        else if (extract<AcGeVector3d>(tpl[1]).check())
                        {
                            const auto val = asDblArray(extract<AcGeVector3d>(tpl[1]));
                            memcpy(appendRb(code)->resval.rpoint, val, sizeof(ads_point));
                        }
                        else
                        {
                            throw PyErrorStatusException(Acad::eInvalidInput);
                        }
                        break;
                    }
                    case AcDb::kDwgBChunk:
                    {
                        pTail = pTail->rbnext = makebin(tpl[1], code);
                        break;
                    }
                    case AcDb::kDwgHandle:
                    {
                        const PyDbHandle hnd = extract<PyDbHandle>(tpl[1]);
                        hnd.m_hnd.copyToOldType(appendRb(code)->resval.ihandle);
                        break;
                    }
                    case AcDb::kDwgHardOwnershipId:
                    case AcDb::kDwgSoftOwnershipId:
                    case AcDb::kDwgHardPointerId:
                    case AcDb::kDwgSoftPointerId:
                    {
                        const PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                        if (acdbGetAdsName(appendRb(code)->resval.rlname, id.m_id) != eOk)
                            throw PyErrorStatusException(Acad::eInvalidInput);
                        break;
                    }
                    default:
                        throw PyErrorStatusException(Acad::eInvalidInput);
                }
            }
            else
            {
                switch (code)
                {
                    case RTT:
                    case RTNIL:
                    case RTDOTE:
                    case RTVOID:
                    case RTLB:
                    case RTLE:
                    case RTNONE:
                    {
                        appendRb(code);
                        break;
                    }
                    case RTANG:
                    case RTREAL:
                    {
                        appendRb(code)->resval.rreal = extract<double>(tpl[1]);
                        break;
                    }
                    case RTORINT:
                    {
                        const auto val = asDblArray(extract<AcGeVector3d>(tpl[1]));
                        memcpy(appendRb(code)->resval.rpoint, val, sizeof(ads_point));
                        break;
                    }
                    case RT3DPOINT:
                    {
                        const auto val = asDblArray(extract<AcGePoint3d>(tpl[1]));
                        memcpy(appendRb(code)->resval.rpoint, val, sizeof(ads_point));

                        break;
                    }
                    case RTPOINT:
                    {
                        const auto val = asDblArray(extract<AcGePoint2d>(tpl[1]));
                        auto* rb = appendRb(code);
                        memcpy(rb->resval.rpoint, val, sizeof(double) * 2);
                        rb->resval.rpoint[2] = 0.0;
                        break;
                    }
                    case RTSHORT:
                    {
                        const int val = extract<int>(tpl[1]);
                        if (val < SHRT_MIN || val > SHRT_MAX)
                            throw PyErrorStatusException(Acad::eInvalidInput);
                        appendRb(code)->resval.rint = static_cast<short>(val);
                        break;
                    }
                    case RTLONG:
                    {
                        appendRb(code)->resval.rlong = extract<int>(tpl[1]);
                        break;
                    }
                    case RTLONG_PTR:
                    case RTINT64:
                    {
                        appendRb(code)->resval.mnInt64 = extract<int64_t>(tpl[1]);
                        break;
                    }
                    case RTSTR:
                    {
                        std::wstring str;
                        if (extract<std::string>(tpl[1]).check())
                            str = utf8_to_wstr(extract<std::string>(tpl[1]));
                        else
                            str = L"";
                        appendRb(code)->resval.rstring = wcsdup(str.c_str());
                        break;
                    }
                    case RTPICKS:
                    {
                        const PyEdSelectionSet ss = extract<PyEdSelectionSet>(tpl[1]);
                        const auto& adsn = ss.adsname();
                        memcpy_s(appendRb(code)->resval.rlname, sizeof(ads_name), adsn.m_data.data(), sizeof(adsn.m_data));
                        break;
                    }
                    case RTENAME:
                    {
                        const PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                        if (acdbGetAdsName(appendRb(code)->resval.rlname, id.m_id) != eOk)
                            throw PyErrorStatusException(Acad::eInvalidInput);
                        break;
                    }
                    default:
                        throw PyErrorStatusException(Acad::eInvalidInput);
                }
            }
        }
        //detach RTLB
        resbuf* result = guard.head->rbnext;
        {
            guard.head->rbnext = nullptr;
            acutRelRb(guard.head);
            guard.head = nullptr;
        }
        return result;
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return nullptr;
}

boost::python::list resbufToList(const resbuf* pRb)
{
    PyAutoLockGIL lock;
    boost::python::list list;
    for (resbuf* pTail = const_cast<resbuf*>(pRb); pTail != nullptr; pTail = pTail->rbnext)
    {
        if (pTail->restype < 5000)
        {
            if (pTail->restype == AcDb::kDxfXdWorldXDisp || pTail->restype == AcDb::kDxfXdWorldXDir)
            {
                list.append(boost::python::make_tuple(pTail->restype, asVec3d(pTail->resval.rpoint)));
                continue;
            }
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
                case AcDb::kDwgBChunk:
                {
                    PyObjectPtr pObj(PyMemoryView_FromMemory(pTail->resval.rbinary.buf, pTail->resval.rbinary.clen, PyBUF_READ));
                    list.append(boost::python::make_tuple(pTail->restype, boost::python::object{ boost::python::handle<>(PyBytes_FromObject(pObj.get())) }));
                    break;
                }
                case AcDb::kDwgHandle:
                {
                    PyDbHandle hand;
                    hand.m_hnd.copyFromOldType(pTail->resval.ihandle);
                    list.append(boost::python::make_tuple(pTail->restype, hand));
                    break;
                }
                case AcDb::kDwgHardOwnershipId:
                case AcDb::kDwgSoftOwnershipId:
                case AcDb::kDwgHardPointerId:
                case AcDb::kDwgSoftPointerId:
                {
                    PyDbObjectId id;
                    acdbGetObjectId(id.m_id, pTail->resval.rlname);
                    list.append(boost::python::make_tuple(pTail->restype, id));
                    break;
                }
            }
        }
        else
        {
            switch (pTail->restype)
            {
                case RTT:
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
                    list.append(boost::python::make_tuple(pTail->restype, asVec3d(pTail->resval.rpoint)));
                    break;
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
                {
                    list.append(boost::python::make_tuple(pTail->restype, PyEdSelectionSet(pTail->resval.rlname, false)));
                    break;
                }
                case RTENAME:
                {
                    AcDbObjectId id;
                    acdbGetObjectId(id, pTail->resval.rlname);
                    list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
                    break;
                }
            }
        }
    }
    return list;
}

resbuf* AcGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS)
{
    resbuf* phead = nullptr;
    resbuf* ptail = nullptr;
    constexpr size_t memsize = sizeof(AcGePoint3d);
    for (size_t idx = 0; idx < ptArrayWCS.length(); idx++)
    {
        if (idx == 0)
        {
            phead = acutNewRb(RT3DPOINT);
            ptail = phead;
        }
        else
        {
            ptail = ptail->rbnext = acutNewRb(RT3DPOINT);
        }
        memcpy_s(ptail->resval.rpoint, memsize, asDblArray(ptArrayWCS[idx]), memsize);
    }
    return phead;
}

resbuf* PyDbObjectIdArrayToResbuf(const PyDbObjectIdArray& vec)
{
    resbuf* phead = nullptr;
    resbuf* ptail = nullptr;
    for (size_t idx = 0; idx < vec.size(); idx++)
    {
        if (idx == 0)
        {
            phead = acutNewRb(RTENAME);
            ptail = phead;
        }
        else
        {
            ptail = ptail->rbnext = acutNewRb(RTENAME);
        }
        acdbGetAdsName(ptail->resval.rlname, vec[idx].m_id);
    }
    return phead;
}
