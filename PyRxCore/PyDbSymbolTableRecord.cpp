#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbEntity.h"
#include "PyDbObjectContext.h"
#include "PyGsView.h"

#include <wx/mstream.h>
using namespace boost::python;

#if defined(_BRXTARGET) && _BRXTARGET >= 250
#include "AcDb/AcDbEvalGraph.h"
#endif

#if defined(_BRXTARGET)
#include "AcConstraints3d.h"
#endif

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makePyDbSymbolTableRecordWrapper()
{
    PyDocString DS("SymbolTableRecord");
    class_<PyDbSymbolTableRecord, bases<PyDbObject>>("SymbolTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("getName", &PyDbSymbolTableRecord::getName, DS.ARGS(9062))
        .def("setName", &PyDbSymbolTableRecord::setName, DS.ARGS({ "name: str" }, 9068))
        .def("isDependent", &PyDbSymbolTableRecord::isDependent, DS.ARGS(9064))
        .def("isResolved", &PyDbSymbolTableRecord::isResolved, DS.ARGS(9066))
        .def("isRenamable", &PyDbSymbolTableRecord::isRenamable, DS.ARGS(9065))
        .def("name", &PyDbSymbolTableRecord::name, DS.ARGS(9067))
        .def("className", &PyDbSymbolTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSymbolTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSymbolTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSymbolTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbSymbolTableRecord>(id), false)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbSymbolTableRecord>(id, mode), false)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbSymbolTableRecord>(id, mode, erased), false)
{
}

std::string PyDbSymbolTableRecord::getName() const
{
    AcString arxName;
    PyThrowBadEs(impObj()->getName(arxName));
    return wstr_to_utf8(arxName);
}

void PyDbSymbolTableRecord::setName(const std::string& name) const
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    return PyThrowBadEs(impObj()->setName(utf8_to_wstr(name).c_str()));
}

bool PyDbSymbolTableRecord::isDependent() const
{
    return impObj()->isDependent();
}

bool PyDbSymbolTableRecord::isResolved() const
{
    return impObj()->isResolved();
}

bool PyDbSymbolTableRecord::isRenamable() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isRenamable();
#endif
}

std::string PyDbSymbolTableRecord::name() const
{
#if defined(_ARXTARGET) && _ARXTARGET >= 250
    Acad::ErrorStatus pE = eOk;
    const auto val = wstr_to_utf8(impObj()->name(&pE));
    PyThrowBadEs(pE);
    return val;
#else
    return this->getName();
#endif
}

std::string PyDbSymbolTableRecord::className()
{
    return "AcDbSymbolTableRecord";
}

PyRxClass PyDbSymbolTableRecord::desc()
{
    return PyRxClass(AcDbSymbolTableRecord::desc(), false);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSymbolTableRecord, AcDbSymbolTableRecord>(src);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSymbolTableRecord>(src);
}

AcDbSymbolTableRecord* PyDbSymbolTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSymbolTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makePyDbDimStyleTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("DimStyleTableRecord");
    class_<PyDbDimStyleTableRecord, bases<PyDbSymbolTableRecord>>("DimStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords,4030)))
        .def("arrowId", &PyDbDimStyleTableRecord::arrowId, DS.ARGS({ "val: PyDb.DimArrowFlags" }))
        .def("dimadec", &PyDbDimStyleTableRecord::dimadec, DS.ARGS())
        .def("dimalt", &PyDbDimStyleTableRecord::dimalt, DS.ARGS())
        .def("dimaltd", &PyDbDimStyleTableRecord::dimaltd, DS.ARGS())
        .def("dimaltf", &PyDbDimStyleTableRecord::dimaltf, DS.ARGS())
        .def("dimaltrnd", &PyDbDimStyleTableRecord::dimaltrnd, DS.ARGS())
        .def("dimalttd", &PyDbDimStyleTableRecord::dimalttd, DS.ARGS())
        .def("dimalttz", &PyDbDimStyleTableRecord::dimalttz, DS.ARGS())
        .def("dimaltu", &PyDbDimStyleTableRecord::dimaltu, DS.ARGS())
        .def("dimaltz", &PyDbDimStyleTableRecord::dimaltz, DS.ARGS())
        .def("dimapost", &PyDbDimStyleTableRecord::dimapost, DS.ARGS())
        .def("dimarcsym", &PyDbDimStyleTableRecord::dimarcsym, DS.ARGS())
        .def("dimasz", &PyDbDimStyleTableRecord::dimasz, DS.ARGS())
        .def("dimatfit", &PyDbDimStyleTableRecord::dimatfit, DS.ARGS())
        .def("dimaunit", &PyDbDimStyleTableRecord::dimaunit, DS.ARGS())
        .def("dimazin", &PyDbDimStyleTableRecord::dimazin, DS.ARGS())
        .def("dimblk", &PyDbDimStyleTableRecord::dimblk, DS.ARGS())
        .def("dimblk1", &PyDbDimStyleTableRecord::dimblk1, DS.ARGS())
        .def("dimblk2", &PyDbDimStyleTableRecord::dimblk2, DS.ARGS())
        .def("dimcen", &PyDbDimStyleTableRecord::dimcen, DS.ARGS())
        .def("dimclrd", &PyDbDimStyleTableRecord::dimclrd, DS.ARGS())
        .def("dimclre", &PyDbDimStyleTableRecord::dimclre, DS.ARGS())
        .def("dimclrt", &PyDbDimStyleTableRecord::dimclrt, DS.ARGS())
        .def("dimdec", &PyDbDimStyleTableRecord::dimdec, DS.ARGS())
        .def("dimdle", &PyDbDimStyleTableRecord::dimdle, DS.ARGS())
        .def("dimdli", &PyDbDimStyleTableRecord::dimdli, DS.ARGS())
        .def("dimdsep", &PyDbDimStyleTableRecord::dimdsep, DS.ARGS())
        .def("dimexe", &PyDbDimStyleTableRecord::dimexe, DS.ARGS())
        .def("dimexo", &PyDbDimStyleTableRecord::dimexo, DS.ARGS())
        .def("dimfrac", &PyDbDimStyleTableRecord::dimfrac, DS.ARGS())
        .def("dimgap", &PyDbDimStyleTableRecord::dimgap, DS.ARGS())
        .def("dimjogang", &PyDbDimStyleTableRecord::dimjogang, DS.ARGS())
        .def("dimjust", &PyDbDimStyleTableRecord::dimjust, DS.ARGS())
        .def("dimldrblk", &PyDbDimStyleTableRecord::dimldrblk, DS.ARGS())
        .def("dimlfac", &PyDbDimStyleTableRecord::dimlfac, DS.ARGS())
        .def("dimlim", &PyDbDimStyleTableRecord::dimlim, DS.ARGS())
        .def("dimltex1", &PyDbDimStyleTableRecord::dimltex1, DS.ARGS())
        .def("dimltex2", &PyDbDimStyleTableRecord::dimltex2, DS.ARGS())
        .def("dimltype", &PyDbDimStyleTableRecord::dimltype, DS.ARGS())
        .def("dimlunit", &PyDbDimStyleTableRecord::dimlunit, DS.ARGS())
        .def("dimlwd", &PyDbDimStyleTableRecord::dimlwd, DS.ARGS())
        .def("dimlwe", &PyDbDimStyleTableRecord::dimlwe, DS.ARGS())
        .def("dimpost", &PyDbDimStyleTableRecord::dimpost, DS.ARGS())
        .def("dimrnd", &PyDbDimStyleTableRecord::dimrnd, DS.ARGS())
        .def("dimsah", &PyDbDimStyleTableRecord::dimsah, DS.ARGS())
        .def("dimscale", &PyDbDimStyleTableRecord::dimscale, DS.ARGS())
        .def("dimsd1", &PyDbDimStyleTableRecord::dimsd1, DS.ARGS())
        .def("dimsd2", &PyDbDimStyleTableRecord::dimsd2, DS.ARGS())
        .def("dimse1", &PyDbDimStyleTableRecord::dimse1, DS.ARGS())
        .def("dimse2", &PyDbDimStyleTableRecord::dimse2, DS.ARGS())
        .def("dimsoxd", &PyDbDimStyleTableRecord::dimsoxd, DS.ARGS())
        .def("dimtad", &PyDbDimStyleTableRecord::dimtad, DS.ARGS())
        .def("dimtdec", &PyDbDimStyleTableRecord::dimtdec, DS.ARGS())
        .def("dimtfac", &PyDbDimStyleTableRecord::dimtfac, DS.ARGS())
        .def("dimtfill", &PyDbDimStyleTableRecord::dimtfill, DS.ARGS())
        .def("dimtfillclr", &PyDbDimStyleTableRecord::dimtfillclr, DS.ARGS())
        .def("dimtih", &PyDbDimStyleTableRecord::dimtih, DS.ARGS())
        .def("dimtix", &PyDbDimStyleTableRecord::dimtix, DS.ARGS())
        .def("dimtm", &PyDbDimStyleTableRecord::dimtm, DS.ARGS())
        .def("dimtmove", &PyDbDimStyleTableRecord::dimtmove, DS.ARGS())
        .def("dimtofl", &PyDbDimStyleTableRecord::dimtofl, DS.ARGS())
        .def("dimtoh", &PyDbDimStyleTableRecord::dimtoh, DS.ARGS())
        .def("dimtol", &PyDbDimStyleTableRecord::dimtol, DS.ARGS())
        .def("dimtolj", &PyDbDimStyleTableRecord::dimtolj, DS.ARGS())
        .def("dimtp", &PyDbDimStyleTableRecord::dimtp, DS.ARGS())
        .def("dimtsz", &PyDbDimStyleTableRecord::dimtsz, DS.ARGS())
        .def("dimtvp", &PyDbDimStyleTableRecord::dimtvp, DS.ARGS())
        .def("dimtxsty", &PyDbDimStyleTableRecord::dimtxsty, DS.ARGS())
        .def("dimtxt", &PyDbDimStyleTableRecord::dimtxt, DS.ARGS())
        .def("dimtzin", &PyDbDimStyleTableRecord::dimtzin, DS.ARGS())
        .def("dimupt", &PyDbDimStyleTableRecord::dimupt, DS.ARGS())
        .def("dimzin", &PyDbDimStyleTableRecord::dimzin, DS.ARGS())
        .def("dimfxlenOn", &PyDbDimStyleTableRecord::dimfxlenOn, DS.ARGS())
        .def("dimfxlen", &PyDbDimStyleTableRecord::dimfxlen, DS.ARGS())
        .def("dimtxtdirection", &PyDbDimStyleTableRecord::dimtxtdirection, DS.ARGS())
        .def("dimmzf", &PyDbDimStyleTableRecord::dimmzf, DS.ARGS())
        .def("dimmzs", &PyDbDimStyleTableRecord::dimmzs, DS.ARGS())
        .def("dimaltmzf", &PyDbDimStyleTableRecord::dimaltmzf, DS.ARGS())
        .def("dimaltmzs", &PyDbDimStyleTableRecord::dimaltmzs, DS.ARGS())

        .def("setDimadec", &PyDbDimStyleTableRecord::setDimadec, DS.ARGS({ "val : int" }))
        .def("setDimalt", &PyDbDimStyleTableRecord::setDimalt, DS.ARGS({ "val : bool" }))
        .def("setDimaltd", &PyDbDimStyleTableRecord::setDimaltd, DS.ARGS({ "val : int" }))
        .def("setDimaltf", &PyDbDimStyleTableRecord::setDimaltf, DS.ARGS({ "val : float" }))
        .def("setDimaltmzf", &PyDbDimStyleTableRecord::setDimaltmzf, DS.ARGS({ "val : float" }))
        .def("setDimaltmzs", &PyDbDimStyleTableRecord::setDimaltmzs, DS.ARGS({ "val : str" }))
        .def("setDimaltrnd", &PyDbDimStyleTableRecord::setDimaltrnd, DS.ARGS({ "val : float" }))
        .def("setDimalttd", &PyDbDimStyleTableRecord::setDimalttd, DS.ARGS({ "val : int" }))
        .def("setDimalttz", &PyDbDimStyleTableRecord::setDimalttz, DS.ARGS({ "val : int" }))
        .def("setDimaltu", &PyDbDimStyleTableRecord::setDimaltu, DS.ARGS({ "val : int" }))
        .def("setDimaltz", &PyDbDimStyleTableRecord::setDimaltz, DS.ARGS({ "val : int" }))
        .def("setDimapost", &PyDbDimStyleTableRecord::setDimapost, DS.ARGS({ "val : str" }))
        .def("setDimarcsym", &PyDbDimStyleTableRecord::setDimarcsym, DS.ARGS({ "val : int" }))
        .def("setDimasz", &PyDbDimStyleTableRecord::setDimasz, DS.ARGS({ "val : float" }))
        .def("setDimatfit", &PyDbDimStyleTableRecord::setDimatfit, DS.ARGS({ "val : int" }))
        .def("setDimaunit", &PyDbDimStyleTableRecord::setDimaunit, DS.ARGS({ "val : int" }))
        .def("setDimazin", &PyDbDimStyleTableRecord::setDimazin, DS.ARGS({ "val : int" }))
        .def("setDimblk", &PyDbDimStyleTableRecord::setDimblkId, DS.ARGS({ "val : str|PyDb.ObjectId" }))
        .def("setDimblk1", &PyDbDimStyleTableRecord::setDimblk1Id, DS.ARGS({ "val : str|PyDb.ObjectId" }))
        .def("setDimblk2", &PyDbDimStyleTableRecord::setDimblk2Id, DS.ARGS({ "val : str|PyDb.ObjectId" }))
        .def("setDimcen", &PyDbDimStyleTableRecord::setDimcen, DS.ARGS({ "val : float" }))
        .def("setDimclrd", &PyDbDimStyleTableRecord::setDimclrd, DS.ARGS({ "val : PyDb.AcCmColor" }))
        .def("setDimclre", &PyDbDimStyleTableRecord::setDimclre, DS.ARGS({ "val : PyDb.AcCmColor" }))
        .def("setDimclrt", &PyDbDimStyleTableRecord::setDimclrt, DS.ARGS({ "val : PyDb.AcCmColor" }))
        .def("setDimdec", &PyDbDimStyleTableRecord::setDimdec, DS.ARGS({ "val : int" }))
        .def("setDimdle", &PyDbDimStyleTableRecord::setDimdle, DS.ARGS({ "val : float" }))
        .def("setDimdli", &PyDbDimStyleTableRecord::setDimdli, DS.ARGS({ "val : float" }))
        .def("setDimdsep", &PyDbDimStyleTableRecord::setDimdsep, DS.ARGS({ "val : int" }))
        .def("setDimexe", &PyDbDimStyleTableRecord::setDimexe, DS.ARGS({ "val : float" }))
        .def("setDimexo", &PyDbDimStyleTableRecord::setDimexo, DS.ARGS({ "val : float" }))
        .def("setDimfrac", &PyDbDimStyleTableRecord::setDimfrac, DS.ARGS({ "val : int" }))
        .def("setDimgap", &PyDbDimStyleTableRecord::setDimgap, DS.ARGS({ "val : float" }))
        .def("setDimjogang", &PyDbDimStyleTableRecord::setDimjogang, DS.ARGS({ "val : float" }))
        .def("setDimjust", &PyDbDimStyleTableRecord::setDimjust, DS.ARGS({ "val : int" }))
        .def("setDimldrblk", &PyDbDimStyleTableRecord::setDimldrblkId, DS.ARGS({ "val : str|PyDb.ObjectId" }))
        .def("setDimlfac", &PyDbDimStyleTableRecord::setDimlfac, DS.ARGS({ "val : float" }))
        .def("setDimlim", &PyDbDimStyleTableRecord::setDimlim, DS.ARGS({ "val : bool" }))
        .def("setDimltex1", &PyDbDimStyleTableRecord::setDimltex1, DS.ARGS({ "val: PyDb.ObjectId" }))
        .def("setDimltex2", &PyDbDimStyleTableRecord::setDimltex2, DS.ARGS({ "val: PyDb.ObjectId" }))
        .def("setDimltype", &PyDbDimStyleTableRecord::setDimltype, DS.ARGS({ "val: PyDb.ObjectId" }))
        .def("setDimlunit", &PyDbDimStyleTableRecord::setDimlunit, DS.ARGS({ "val : int" }))
        .def("setDimlwd", &PyDbDimStyleTableRecord::setDimlwd, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("setDimlwe", &PyDbDimStyleTableRecord::setDimlwe, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("setDimmzf", &PyDbDimStyleTableRecord::setDimmzf, DS.ARGS({ "val : float" }))
        .def("setDimmzs", &PyDbDimStyleTableRecord::setDimmzs, DS.ARGS({ "val : str" }))
        .def("setDimpost", &PyDbDimStyleTableRecord::setDimpost, DS.ARGS({ "val : str" }))
        .def("setDimrnd", &PyDbDimStyleTableRecord::setDimrnd, DS.ARGS({ "val : float" }))
        .def("setDimsah", &PyDbDimStyleTableRecord::setDimsah, DS.ARGS({ "val : bool" }))
        .def("setDimscale", &PyDbDimStyleTableRecord::setDimscale, DS.ARGS({ "val : float" }))
        .def("setDimsd1", &PyDbDimStyleTableRecord::setDimsd1, DS.ARGS({ "val : bool" }))
        .def("setDimsd2", &PyDbDimStyleTableRecord::setDimsd2, DS.ARGS({ "val : bool" }))
        .def("setDimse1", &PyDbDimStyleTableRecord::setDimse1, DS.ARGS({ "val : bool" }))
        .def("setDimse2", &PyDbDimStyleTableRecord::setDimse2, DS.ARGS({ "val : bool" }))
        .def("setDimsoxd", &PyDbDimStyleTableRecord::setDimsoxd, DS.ARGS({ "val : bool" }))
        .def("setDimtad", &PyDbDimStyleTableRecord::setDimtad, DS.ARGS({ "val : int" }))
        .def("setDimtdec", &PyDbDimStyleTableRecord::setDimtdec, DS.ARGS({ "val : int" }))
        .def("setDimtfac", &PyDbDimStyleTableRecord::setDimtfac, DS.ARGS({ "val : float" }))
        .def("setDimtfill", &PyDbDimStyleTableRecord::setDimtfill, DS.ARGS({ "val : int" }))
        .def("setDimtfillclr", &PyDbDimStyleTableRecord::setDimtfillclr, DS.ARGS({ "val : PyDb.AcCmColor" }))
        .def("setDimtih", &PyDbDimStyleTableRecord::setDimtih, DS.ARGS({ "val : bool" }))
        .def("setDimtix", &PyDbDimStyleTableRecord::setDimtix, DS.ARGS({ "val : bool" }))
        .def("setDimtm", &PyDbDimStyleTableRecord::setDimtm, DS.ARGS({ "val : float" }))
        .def("setDimtmove", &PyDbDimStyleTableRecord::setDimtmove, DS.ARGS({ "val : int" }))
        .def("setDimtofl", &PyDbDimStyleTableRecord::setDimtofl, DS.ARGS({ "val : bool" }))
        .def("setDimtoh", &PyDbDimStyleTableRecord::setDimtoh, DS.ARGS({ "val : bool" }))
        .def("setDimtol", &PyDbDimStyleTableRecord::setDimtol, DS.ARGS({ "val : bool" }))
        .def("setDimtolj", &PyDbDimStyleTableRecord::setDimtolj, DS.ARGS({ "val : int" }))
        .def("setDimtp", &PyDbDimStyleTableRecord::setDimtp, DS.ARGS({ "val : float" }))
        .def("setDimtsz", &PyDbDimStyleTableRecord::setDimtsz, DS.ARGS({ "val : float" }))
        .def("setDimtvp", &PyDbDimStyleTableRecord::setDimtvp, DS.ARGS({ "val : float" }))
        .def("setDimtxsty", &PyDbDimStyleTableRecord::setDimtxsty, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("setDimtxt", &PyDbDimStyleTableRecord::setDimtxt, DS.ARGS({ "val: float" }))
        .def("setDimtxtdirection", &PyDbDimStyleTableRecord::setDimtxtdirection, DS.ARGS({ "val : bool" }))
        .def("setDimtzin", &PyDbDimStyleTableRecord::setDimtzin, DS.ARGS({ "val : int" }))
        .def("setDimupt", &PyDbDimStyleTableRecord::setDimupt, DS.ARGS({ "val : bool" }))
        .def("setDimzin", &PyDbDimStyleTableRecord::setDimzin, DS.ARGS({ "val : int" }))
        .def("setDimblk", &PyDbDimStyleTableRecord::setDimblk, DS.ARGS({ "val: str" }))
        .def("setDimblk1", &PyDbDimStyleTableRecord::setDimblk1, DS.ARGS({ "val: str" }))
        .def("setDimblk2", &PyDbDimStyleTableRecord::setDimblk2, DS.ARGS({ "val: str" }))
        .def("setDimldrblk", &PyDbDimStyleTableRecord::setDimldrblk, DS.ARGS({ "val: str" }))
        .def("setDimfxlenOn", &PyDbDimStyleTableRecord::setDimfxlenOn, DS.ARGS({ "val : bool" }))
        .def("setDimfxlen", &PyDbDimStyleTableRecord::setDimfxlen, DS.ARGS({ "val : float" }))
        .def("isModifiedForRecompute", &PyDbDimStyleTableRecord::isModifiedForRecompute, DS.ARGS())

        .def("className", &PyDbDimStyleTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimStyleTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbDimStyleTableRecord(), true)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbDimStyleTableRecord>(id), false)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbDimStyleTableRecord>(id, mode), false)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbDimStyleTableRecord>(id, mode, erased), false)
{
}

PyDbObjectId PyDbDimStyleTableRecord::arrowId(AcDb::DimArrowFlags whichArrow) const
{
    return PyDbObjectId(impObj()->arrowId(whichArrow));
}

int PyDbDimStyleTableRecord::dimadec() const
{
    return impObj()->dimadec();
}

bool PyDbDimStyleTableRecord::dimalt() const
{
    return impObj()->dimalt();
}

int PyDbDimStyleTableRecord::dimaltd() const
{
    return impObj()->dimaltd();
}

double PyDbDimStyleTableRecord::dimaltf() const
{
    return impObj()->dimaltf();
}

double PyDbDimStyleTableRecord::dimaltrnd() const
{
    return impObj()->dimaltrnd();
}

int PyDbDimStyleTableRecord::dimalttd() const
{
    return impObj()->dimalttd();
}

int PyDbDimStyleTableRecord::dimalttz() const
{
    return impObj()->dimalttz();
}

int PyDbDimStyleTableRecord::dimaltu() const
{
    return impObj()->dimaltu();
}

int PyDbDimStyleTableRecord::dimaltz() const
{
    return impObj()->dimaltz();
}

std::string PyDbDimStyleTableRecord::dimapost() const
{
    return wstr_to_utf8(impObj()->dimapost());
}

int PyDbDimStyleTableRecord::dimarcsym() const
{
    return impObj()->dimarcsym();
}

double PyDbDimStyleTableRecord::dimasz() const
{
    return impObj()->dimasz();
}

int PyDbDimStyleTableRecord::dimatfit() const
{
    return impObj()->dimatfit();
}

int PyDbDimStyleTableRecord::dimaunit() const
{
    return impObj()->dimaunit();
}

int PyDbDimStyleTableRecord::dimazin() const
{
    return impObj()->dimazin();
}

PyDbObjectId PyDbDimStyleTableRecord::dimblk() const
{
    return PyDbObjectId(impObj()->dimblk());
}

PyDbObjectId PyDbDimStyleTableRecord::dimblk1() const
{
    return PyDbObjectId(impObj()->dimblk1());
}

PyDbObjectId PyDbDimStyleTableRecord::dimblk2() const
{
    return PyDbObjectId(impObj()->dimblk2());
}

double PyDbDimStyleTableRecord::dimcen() const
{
    return impObj()->dimcen();
}

AcCmColor PyDbDimStyleTableRecord::dimclrd() const
{
    return impObj()->dimclrd();
}

AcCmColor PyDbDimStyleTableRecord::dimclre() const
{
    return impObj()->dimclre();
}

AcCmColor PyDbDimStyleTableRecord::dimclrt() const
{
    return impObj()->dimclrt();
}

int PyDbDimStyleTableRecord::dimdec() const
{
    return impObj()->dimdec();
}

double PyDbDimStyleTableRecord::dimdle() const
{
    return impObj()->dimdle();
}

double PyDbDimStyleTableRecord::dimdli() const
{
    return impObj()->dimdli();
}

char PyDbDimStyleTableRecord::dimdsep() const
{
    return (char)impObj()->dimdsep();
}

double PyDbDimStyleTableRecord::dimexe() const
{
    return impObj()->dimexe();
}

double PyDbDimStyleTableRecord::dimexo() const
{
    return impObj()->dimexo();
}

int PyDbDimStyleTableRecord::dimfrac() const
{
    return impObj()->dimfrac();
}

double PyDbDimStyleTableRecord::dimgap() const
{
    return impObj()->dimgap();
}

double PyDbDimStyleTableRecord::dimjogang() const
{
    return impObj()->dimjogang();
}

int PyDbDimStyleTableRecord::dimjust() const
{
    return impObj()->dimjust();
}

PyDbObjectId PyDbDimStyleTableRecord::dimldrblk() const
{
    return PyDbObjectId(impObj()->dimldrblk());
}

double PyDbDimStyleTableRecord::dimlfac() const
{
    return impObj()->dimlfac();
}

bool PyDbDimStyleTableRecord::dimlim() const
{
    return impObj()->dimlim();
}

PyDbObjectId PyDbDimStyleTableRecord::dimltex1() const
{
    return PyDbObjectId(impObj()->dimltex1());
}

PyDbObjectId PyDbDimStyleTableRecord::dimltex2() const
{
    return PyDbObjectId(impObj()->dimltex2());
}

PyDbObjectId PyDbDimStyleTableRecord::dimltype() const
{
    return PyDbObjectId(impObj()->dimltype());
}

int PyDbDimStyleTableRecord::dimlunit() const
{
    return impObj()->dimlunit();
}

AcDb::LineWeight PyDbDimStyleTableRecord::dimlwd() const
{
    return impObj()->dimlwd();
}

AcDb::LineWeight PyDbDimStyleTableRecord::dimlwe() const
{
    return impObj()->dimlwe();
}

std::string PyDbDimStyleTableRecord::dimpost() const
{
    return wstr_to_utf8(impObj()->dimpost());
}

double PyDbDimStyleTableRecord::dimrnd() const
{
    return impObj()->dimrnd();
}

bool PyDbDimStyleTableRecord::dimsah() const
{
    return impObj()->dimsah();
}

double PyDbDimStyleTableRecord::dimscale() const
{
    return impObj()->dimscale();
}

bool PyDbDimStyleTableRecord::dimsd1() const
{
    return impObj()->dimsd1();
}

bool PyDbDimStyleTableRecord::dimsd2() const
{
    return impObj()->dimsd2();
}

bool PyDbDimStyleTableRecord::dimse1() const
{
    return impObj()->dimse1();
}

bool PyDbDimStyleTableRecord::dimse2() const
{
    return impObj()->dimse2();
}

bool PyDbDimStyleTableRecord::dimsoxd() const
{
    return impObj()->dimsoxd();
}

int PyDbDimStyleTableRecord::dimtad() const
{
    return impObj()->dimtad();
}

int PyDbDimStyleTableRecord::dimtdec() const
{
    return impObj()->dimtdec();
}

double PyDbDimStyleTableRecord::dimtfac() const
{
    return impObj()->dimtfac();
}

int PyDbDimStyleTableRecord::dimtfill() const
{
    return impObj()->dimtfill();
}

AcCmColor PyDbDimStyleTableRecord::dimtfillclr() const
{
    return impObj()->dimtfillclr();
}

bool PyDbDimStyleTableRecord::dimtih() const
{
    return impObj()->dimtih();
}

bool PyDbDimStyleTableRecord::dimtix() const
{
    return impObj()->dimtix();
}

double PyDbDimStyleTableRecord::dimtm() const
{
    return impObj()->dimtm();
}

int PyDbDimStyleTableRecord::dimtmove() const
{
    return impObj()->dimtmove();
}

bool PyDbDimStyleTableRecord::dimtofl() const
{
    return impObj()->dimtofl();
}

bool PyDbDimStyleTableRecord::dimtoh() const
{
    return impObj()->dimtoh();
}

bool PyDbDimStyleTableRecord::dimtol() const
{
    return impObj()->dimtol();
}

int PyDbDimStyleTableRecord::dimtolj() const
{
    return impObj()->dimtolj();
}

double PyDbDimStyleTableRecord::dimtp() const
{
    return impObj()->dimtp();
}

double PyDbDimStyleTableRecord::dimtsz() const
{
    return impObj()->dimtsz();
}

double PyDbDimStyleTableRecord::dimtvp() const
{
    return impObj()->dimtvp();
}

PyDbObjectId PyDbDimStyleTableRecord::dimtxsty() const
{
    return PyDbObjectId(impObj()->dimtxsty());
}

double PyDbDimStyleTableRecord::dimtxt() const
{
    return impObj()->dimtxt();
}

int PyDbDimStyleTableRecord::dimtzin() const
{
    return impObj()->dimtzin();
}

bool PyDbDimStyleTableRecord::dimupt() const
{
    return impObj()->dimupt();
}

int PyDbDimStyleTableRecord::dimzin() const
{
    return impObj()->dimzin();
}

bool PyDbDimStyleTableRecord::dimfxlenOn() const
{
    return impObj()->dimfxlenOn();
}

double PyDbDimStyleTableRecord::dimfxlen() const
{
    return impObj()->dimfxlen();
}

bool PyDbDimStyleTableRecord::dimtxtdirection() const
{
    return impObj()->dimtxtdirection();
}

double PyDbDimStyleTableRecord::dimmzf() const
{
    return impObj()->dimmzf();
}

std::string PyDbDimStyleTableRecord::dimmzs() const
{
    return wstr_to_utf8(impObj()->dimmzs());
}

double PyDbDimStyleTableRecord::dimaltmzf() const
{
    return impObj()->dimaltmzf();
}

std::string PyDbDimStyleTableRecord::dimaltmzs() const
{
    return wstr_to_utf8(impObj()->dimaltmzs());
}

void PyDbDimStyleTableRecord::setDimadec(int v) const
{
    PyThrowBadEs(impObj()->setDimadec(v));
}

void PyDbDimStyleTableRecord::setDimalt(bool v) const
{
    PyThrowBadEs(impObj()->setDimalt(v));
}

void PyDbDimStyleTableRecord::setDimaltd(int v) const
{
    PyThrowBadEs(impObj()->setDimaltd(v));
}

void PyDbDimStyleTableRecord::setDimaltf(double v) const
{
    PyThrowBadEs(impObj()->setDimaltf(v));
}

void PyDbDimStyleTableRecord::setDimaltmzf(double v) const
{
    PyThrowBadEs(impObj()->setDimaltmzf(v));
}

void PyDbDimStyleTableRecord::setDimaltmzs(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimaltmzs(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimaltrnd(double v) const
{
    PyThrowBadEs(impObj()->setDimaltrnd(v));
}

void PyDbDimStyleTableRecord::setDimalttd(int v) const
{
    PyThrowBadEs(impObj()->setDimalttd(v));
}

void PyDbDimStyleTableRecord::setDimalttz(int v) const
{
    PyThrowBadEs(impObj()->setDimalttz(v));
}

void PyDbDimStyleTableRecord::setDimaltu(int v) const
{
    PyThrowBadEs(impObj()->setDimaltu(v));
}

void PyDbDimStyleTableRecord::setDimaltz(int v) const
{
    PyThrowBadEs(impObj()->setDimaltz(v));
}

void PyDbDimStyleTableRecord::setDimapost(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimapost(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimarcsym(int v) const
{
    PyThrowBadEs(impObj()->setDimarcsym(v));
}

void PyDbDimStyleTableRecord::setDimasz(double v) const
{
    PyThrowBadEs(impObj()->setDimasz(v));
}

void PyDbDimStyleTableRecord::setDimatfit(int v) const
{
    PyThrowBadEs(impObj()->setDimatfit(v));
}

void PyDbDimStyleTableRecord::setDimaunit(int v) const
{
    PyThrowBadEs(impObj()->setDimaunit(v));
}

void PyDbDimStyleTableRecord::setDimazin(int v) const
{
    PyThrowBadEs(impObj()->setDimazin(v));
}

void PyDbDimStyleTableRecord::setDimblkId(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimblk(v.m_id));
}

void PyDbDimStyleTableRecord::setDimblk(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimblk(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimblk1Id(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimblk1(v.m_id));
}

void PyDbDimStyleTableRecord::setDimblk1(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimblk1(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimblk2Id(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimblk2(v.m_id));
}

void PyDbDimStyleTableRecord::setDimblk2(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimblk2(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimldrblkId(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimblk2(v.m_id));
}

void PyDbDimStyleTableRecord::setDimldrblk(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimblk2(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimfxlenOn(bool v) const
{
    PyThrowBadEs(impObj()->setDimfxlenOn(v));
}

void PyDbDimStyleTableRecord::setDimfxlen(double v) const
{
    PyThrowBadEs(impObj()->setDimfxlen(v));
}

bool PyDbDimStyleTableRecord::isModifiedForRecompute() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isModifiedForRecompute();
#endif
}

void PyDbDimStyleTableRecord::setDimlfac(double v) const
{
    PyThrowBadEs(impObj()->setDimlfac(v));
}

void PyDbDimStyleTableRecord::setDimcen(double v) const
{
    PyThrowBadEs(impObj()->setDimcen(v));
}

void PyDbDimStyleTableRecord::setDimclrd(const AcCmColor& v) const
{
    PyThrowBadEs(impObj()->setDimclrd(v));
}

void PyDbDimStyleTableRecord::setDimclre(const AcCmColor& v) const
{
    PyThrowBadEs(impObj()->setDimclre(v));
}

void PyDbDimStyleTableRecord::setDimclrt(const AcCmColor& v) const
{
    PyThrowBadEs(impObj()->setDimclrt(v));
}

void PyDbDimStyleTableRecord::setDimdec(int v) const
{
    PyThrowBadEs(impObj()->setDimdec(v));
}

void PyDbDimStyleTableRecord::setDimdle(double v) const
{
    PyThrowBadEs(impObj()->setDimdle(v));
}

void PyDbDimStyleTableRecord::setDimdli(double v) const
{
    PyThrowBadEs(impObj()->setDimdli(v));
}

void PyDbDimStyleTableRecord::setDimdsep(char v) const
{
    PyThrowBadEs(impObj()->setDimdsep(v));
}

void PyDbDimStyleTableRecord::setDimexe(double v) const
{
    PyThrowBadEs(impObj()->setDimexe(v));
}

void PyDbDimStyleTableRecord::setDimexo(double v) const
{
    PyThrowBadEs(impObj()->setDimexo(v));
}

void PyDbDimStyleTableRecord::setDimfrac(int v) const
{
    PyThrowBadEs(impObj()->setDimfrac(v));
}

void PyDbDimStyleTableRecord::setDimgap(double v) const
{
    PyThrowBadEs(impObj()->setDimgap(v));
}

void PyDbDimStyleTableRecord::setDimjogang(double v) const
{
    PyThrowBadEs(impObj()->setDimjogang(v));
}

void PyDbDimStyleTableRecord::setDimjust(int v) const
{
    PyThrowBadEs(impObj()->setDimjust(v));
}

void PyDbDimStyleTableRecord::setDimlim(bool v) const
{
    PyThrowBadEs(impObj()->setDimlim(v));
}

void PyDbDimStyleTableRecord::setDimltex1(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimltex1(v.m_id));
}

void PyDbDimStyleTableRecord::setDimltex2(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimltex2(v.m_id));
}

void PyDbDimStyleTableRecord::setDimltype(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimltype(v.m_id));
}

void PyDbDimStyleTableRecord::setDimlunit(int v) const
{
    PyThrowBadEs(impObj()->setDimlunit(v));
}

void PyDbDimStyleTableRecord::setDimlwd(AcDb::LineWeight v) const
{
    PyThrowBadEs(impObj()->setDimlwd(v));
}

void PyDbDimStyleTableRecord::setDimlwe(AcDb::LineWeight v) const
{
    PyThrowBadEs(impObj()->setDimlwe(v));
}

void PyDbDimStyleTableRecord::setDimmzf(double v) const
{
    PyThrowBadEs(impObj()->setDimmzf(v));
}

void PyDbDimStyleTableRecord::setDimmzs(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimmzs(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimpost(const std::string& v) const
{
    PyThrowBadEs(impObj()->setDimpost(utf8_to_wstr(v).c_str()));
}

void PyDbDimStyleTableRecord::setDimrnd(double v) const
{
    PyThrowBadEs(impObj()->setDimrnd(v));
}

void PyDbDimStyleTableRecord::setDimsah(bool v) const
{
    PyThrowBadEs(impObj()->setDimsah(v));
}

void PyDbDimStyleTableRecord::setDimscale(double v) const
{
    PyThrowBadEs(impObj()->setDimscale(v));
}

void PyDbDimStyleTableRecord::setDimsd1(bool v) const
{
    PyThrowBadEs(impObj()->setDimsd1(v));
}

void PyDbDimStyleTableRecord::setDimsd2(bool v) const
{
    PyThrowBadEs(impObj()->setDimsd2(v));
}

void PyDbDimStyleTableRecord::setDimse1(bool v) const
{
    PyThrowBadEs(impObj()->setDimse1(v));
}

void PyDbDimStyleTableRecord::setDimse2(bool v) const
{
    PyThrowBadEs(impObj()->setDimse2(v));
}

void PyDbDimStyleTableRecord::setDimsoxd(bool v) const
{
    PyThrowBadEs(impObj()->setDimsoxd(v));
}

void PyDbDimStyleTableRecord::setDimtad(int v) const
{
    PyThrowBadEs(impObj()->setDimtad(v));
}

void PyDbDimStyleTableRecord::setDimtdec(int v) const
{
    PyThrowBadEs(impObj()->setDimtdec(v));
}

void PyDbDimStyleTableRecord::setDimtfac(double v) const
{
    PyThrowBadEs(impObj()->setDimtfac(v));
}

void PyDbDimStyleTableRecord::setDimtfill(int v) const
{
    PyThrowBadEs(impObj()->setDimtfill(v));
}

void PyDbDimStyleTableRecord::setDimtfillclr(const AcCmColor& v) const
{
    PyThrowBadEs(impObj()->setDimtfillclr(v));
}

void PyDbDimStyleTableRecord::setDimtih(bool v) const
{
    PyThrowBadEs(impObj()->setDimtih(v));
}

void PyDbDimStyleTableRecord::setDimtix(bool v) const
{
    PyThrowBadEs(impObj()->setDimtix(v));
}

void PyDbDimStyleTableRecord::setDimtm(double v) const
{
    PyThrowBadEs(impObj()->setDimtm(v));
}

void PyDbDimStyleTableRecord::setDimtmove(int v) const
{
    PyThrowBadEs(impObj()->setDimtmove(v));
}

void PyDbDimStyleTableRecord::setDimtofl(bool v) const
{
    PyThrowBadEs(impObj()->setDimtofl(v));
}

void PyDbDimStyleTableRecord::setDimtoh(bool v) const
{
    PyThrowBadEs(impObj()->setDimtoh(v));
}

void PyDbDimStyleTableRecord::setDimtol(bool v) const
{
    PyThrowBadEs(impObj()->setDimtol(v));
}

void PyDbDimStyleTableRecord::setDimtolj(int v) const
{
    PyThrowBadEs(impObj()->setDimtolj(v));
}

void PyDbDimStyleTableRecord::setDimtp(double v) const
{
    PyThrowBadEs(impObj()->setDimtp(v));
}

void PyDbDimStyleTableRecord::setDimtsz(double v) const
{
    PyThrowBadEs(impObj()->setDimtsz(v));
}

void PyDbDimStyleTableRecord::setDimtvp(double v) const
{
    PyThrowBadEs(impObj()->setDimtvp(v));
}

void PyDbDimStyleTableRecord::setDimtxsty(const PyDbObjectId& v) const
{
    PyThrowBadEs(impObj()->setDimtxsty(v.m_id));
}

void PyDbDimStyleTableRecord::setDimtxt(double v) const
{
    PyThrowBadEs(impObj()->setDimtxt(v));
}

void PyDbDimStyleTableRecord::setDimtxtdirection(bool v) const
{
    PyThrowBadEs(impObj()->setDimtxtdirection(v));
}

void PyDbDimStyleTableRecord::setDimtzin(int v) const
{
    PyThrowBadEs(impObj()->setDimtzin(v));
}

void PyDbDimStyleTableRecord::setDimupt(bool v) const
{
    PyThrowBadEs(impObj()->setDimupt(v));
}

void PyDbDimStyleTableRecord::setDimzin(int v) const
{
    PyThrowBadEs(impObj()->setDimzin(v));
}

std::string PyDbDimStyleTableRecord::className()
{
    return "AcDbDimStyleTableRecord";
}

PyRxClass PyDbDimStyleTableRecord::desc()
{
    return PyRxClass(AcDbDimStyleTableRecord::desc(), false);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbDimStyleTableRecord, AcDbDimStyleTableRecord>(src);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDimStyleTableRecord>(src);
}

AcDbDimStyleTableRecord* PyDbDimStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDimStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper()
{
    constexpr const std::string_view setUcsOverloads = "Overloads:\n"
        "- origin: PyGe.Point3d, xAxis: PyGe.Vector3d, yAxis : PyGe.Vector3d\n"
        "- view: PyDb.OrthographicView\n"
        "- ucsId: PyDb.ObjectId\n";

    constexpr const std::string_view ssetViewDirectionOverloads = "Overloads:\n"
        "- viewDirection: PyGe.Vector3d\n"
        "- view: PyDb.OrthographicView\n";

    PyDocString DS("AbstractViewTableRecord");
    class_<PyDbAbstractViewTableRecord, bases<PyDbSymbolTableRecord>>("AbstractViewTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 1349)))
        .def("centerPoint", &PyDbAbstractViewTableRecord::centerPoint, DS.ARGS(1356))
        .def("setCenterPoint", &PyDbAbstractViewTableRecord::setCenterPoint, DS.ARGS({ "val : PyGe.Point2d" }, 1375))
        .def("height", &PyDbAbstractViewTableRecord::height, DS.ARGS(1364))
        .def("setHeight", &PyDbAbstractViewTableRecord::setHeight, DS.ARGS({ "val : float" }, 1383))
        .def("width", &PyDbAbstractViewTableRecord::width, DS.ARGS(1401))
        .def("setWidth", &PyDbAbstractViewTableRecord::setWidth, DS.ARGS({ "val : float" }, 1393))
        .def("target", &PyDbAbstractViewTableRecord::target, DS.ARGS(1395))
        .def("setTarget", &PyDbAbstractViewTableRecord::setTarget, DS.ARGS({ "val : PyGe.Point3d" }, 1387))
        .def("viewDirection", &PyDbAbstractViewTableRecord::viewDirection, DS.ARGS(1398))
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection1)
        .def("setViewDirection", &PyDbAbstractViewTableRecord::setViewDirection2, DS.OVRL(ssetViewDirectionOverloads, 1390))
        .def("viewTwist", &PyDbAbstractViewTableRecord::viewTwist, DS.ARGS(1399))
        .def("setViewTwist", &PyDbAbstractViewTableRecord::setViewTwist, DS.ARGS({ "val : float" }, 1391))
        .def("lensLength", &PyDbAbstractViewTableRecord::lensLength, DS.ARGS(1368))
        .def("setLensLength", &PyDbAbstractViewTableRecord::setLensLength, DS.ARGS({ "val : float" }, 1384))
        .def("frontClipDistance", &PyDbAbstractViewTableRecord::frontClipDistance, DS.ARGS(1361))
        .def("setFrontClipDistance", &PyDbAbstractViewTableRecord::setFrontClipDistance, DS.ARGS({ "val : float" }, 1381))
        .def("backClipDistance", &PyDbAbstractViewTableRecord::backClipDistance, DS.ARGS(1352))
        .def("setBackClipDistance", &PyDbAbstractViewTableRecord::setBackClipDistance, DS.ARGS({ "val : float" }, 1371))
        .def("perspectiveEnabled", &PyDbAbstractViewTableRecord::perspectiveEnabled, DS.ARGS(1369))
        .def("setPerspectiveEnabled", &PyDbAbstractViewTableRecord::setPerspectiveEnabled, DS.ARGS({ "val : bool" }, 1385))
        .def("frontClipEnabled", &PyDbAbstractViewTableRecord::frontClipEnabled, DS.ARGS(1362))
        .def("setFrontClipEnabled", &PyDbAbstractViewTableRecord::setFrontClipEnabled, DS.ARGS({ "val : bool" }, 1382))
        .def("backClipEnabled", &PyDbAbstractViewTableRecord::backClipEnabled, DS.ARGS(1353))
        .def("setBackClipEnabled", &PyDbAbstractViewTableRecord::setBackClipEnabled, DS.ARGS({ "val : bool" }, 1372))
        .def("frontClipAtEye", &PyDbAbstractViewTableRecord::frontClipAtEye, DS.ARGS(1360))
        .def("setFrontClipAtEye", &PyDbAbstractViewTableRecord::setFrontClipAtEye, DS.ARGS({ "val : bool" }, 1380))
        .def("background", &PyDbAbstractViewTableRecord::background, DS.ARGS(1354))
        .def("setBackground", &PyDbAbstractViewTableRecord::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }, 1373))
        .def("visualStyle", &PyDbAbstractViewTableRecord::visualStyle, DS.ARGS(1400))
        .def("setVisualStyle", &PyDbAbstractViewTableRecord::setVisualStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 1392))
        .def("isDefaultLightingOn", &PyDbAbstractViewTableRecord::isDefaultLightingOn, DS.ARGS(1365))
        .def("setDefaultLightingOn", &PyDbAbstractViewTableRecord::setDefaultLightingOn, DS.ARGS({ "val : bool" }, 1377))
        .def("defaultLightingType", &PyDbAbstractViewTableRecord::defaultLightingType, DS.ARGS(1358))
        .def("setDefaultLightingType", &PyDbAbstractViewTableRecord::setDefaultLightingType, DS.ARGS({ "val: PyGi.DefaultLightingType" }, 1378))
        .def("brightness", &PyDbAbstractViewTableRecord::brightness, DS.ARGS(1355))
        .def("setBrightness", &PyDbAbstractViewTableRecord::setBrightness, DS.ARGS({ "val : float" }, 1374))
        .def("contrast", &PyDbAbstractViewTableRecord::contrast, DS.ARGS(1357))
        .def("setContrast", &PyDbAbstractViewTableRecord::setContrast, DS.ARGS({ "val : float" }, 1376))
        .def("ambientLightColor", &PyDbAbstractViewTableRecord::ambientLightColor, DS.ARGS(1351))
        .def("setAmbientLightColor", &PyDbAbstractViewTableRecord::setAmbientLightColor, DS.ARGS({ "val : PyDb.Color" }, 1370))
        .def("sunId", &PyDbAbstractViewTableRecord::sunId, DS.ARGS(1394))
        .def("setSun", &PyDbAbstractViewTableRecord::setSun1)
        .def("setSun", &PyDbAbstractViewTableRecord::setSun2, DS.ARGS({ "retId : PyDb.ObjectId","pSun : PyDb.Object","eraseOldSun : bool=True" }, 1386))
        .def("getUcs", &PyDbAbstractViewTableRecord::getUcs, DS.ARGS(1363))
        .def("isUcsOrthographic", &PyDbAbstractViewTableRecord::isUcsOrthographic, DS.ARGS(1366))
        .def("ucsName", &PyDbAbstractViewTableRecord::ucsName, DS.ARGS(1397))
        .def("elevation", &PyDbAbstractViewTableRecord::elevation, DS.ARGS(1359))
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs1)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs2)
        .def("setUcs", &PyDbAbstractViewTableRecord::setUcs3, DS.OVRL(setUcsOverloads, 1388))
        .def("setUcsToWorld", &PyDbAbstractViewTableRecord::setUcsToWorld, DS.ARGS(1389))
        .def("setElevation", &PyDbAbstractViewTableRecord::setElevation, DS.ARGS({ "val : float" }, 1379))
        .def("isViewOrthographic", &PyDbAbstractViewTableRecord::isViewOrthographic, DS.ARGS(1367))
        .def("className", &PyDbAbstractViewTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAbstractViewTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAbstractViewTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAbstractViewTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

#ifdef NEVER
PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord()
    : PyDbSymbolTableRecord(new AcDbAbstractViewTableRecord(), true)
{
}
#endif

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(AcDbAbstractViewTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbAbstractViewTableRecord>(id), false)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbAbstractViewTableRecord>(id, mode), false)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbAbstractViewTableRecord>(id, mode, erased), false)
{
}

AcGePoint2d PyDbAbstractViewTableRecord::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDbAbstractViewTableRecord::setCenterPoint(const AcGePoint2d& val) const
{
    return impObj()->setCenterPoint(val);
}

double PyDbAbstractViewTableRecord::height() const
{
    return impObj()->height();
}

void PyDbAbstractViewTableRecord::setHeight(double val) const
{
    return impObj()->setHeight(val);
}

double PyDbAbstractViewTableRecord::width() const
{
    return impObj()->width();
}

void PyDbAbstractViewTableRecord::setWidth(double val) const
{
    return impObj()->setWidth(val);
}

AcGePoint3d PyDbAbstractViewTableRecord::target() const
{
    return impObj()->target();
}

void PyDbAbstractViewTableRecord::setTarget(const AcGePoint3d& target) const
{
    return impObj()->setTarget(target);
}

AcGeVector3d PyDbAbstractViewTableRecord::viewDirection() const
{
    return impObj()->viewDirection();
}

void PyDbAbstractViewTableRecord::setViewDirection1(const AcGeVector3d& viewDirection) const
{
    return impObj()->setViewDirection(viewDirection);
}

void PyDbAbstractViewTableRecord::setViewDirection2(AcDb::OrthographicView view) const
{
    return PyThrowBadEs(impObj()->setViewDirection(view));
}

double PyDbAbstractViewTableRecord::viewTwist() const
{
    return impObj()->viewTwist();
}

void PyDbAbstractViewTableRecord::setViewTwist(double angle) const
{
    return impObj()->setViewTwist(angle);
}

double PyDbAbstractViewTableRecord::lensLength() const
{
    return impObj()->lensLength();
}

void PyDbAbstractViewTableRecord::setLensLength(double length) const
{
    return impObj()->setLensLength(length);
}

double PyDbAbstractViewTableRecord::frontClipDistance() const
{
    return impObj()->frontClipDistance();
}

void PyDbAbstractViewTableRecord::setFrontClipDistance(double distance) const
{
    return impObj()->setFrontClipDistance(distance);
}

double PyDbAbstractViewTableRecord::backClipDistance() const
{
    return impObj()->backClipDistance();
}

void PyDbAbstractViewTableRecord::setBackClipDistance(double distance) const
{
    return impObj()->setBackClipDistance(distance);
}

bool PyDbAbstractViewTableRecord::perspectiveEnabled() const
{
    return impObj()->perspectiveEnabled();
}

void PyDbAbstractViewTableRecord::setPerspectiveEnabled(bool enabled) const
{
    return impObj()->setPerspectiveEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::frontClipEnabled() const
{
    return impObj()->frontClipEnabled();
}

void PyDbAbstractViewTableRecord::setFrontClipEnabled(bool enabled) const
{
    return impObj()->setFrontClipEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::backClipEnabled() const
{
    return impObj()->backClipEnabled();
}

void PyDbAbstractViewTableRecord::setBackClipEnabled(bool enabled) const
{
    return impObj()->setBackClipEnabled(enabled);
}

bool PyDbAbstractViewTableRecord::frontClipAtEye() const
{
    return impObj()->frontClipAtEye();
}

void PyDbAbstractViewTableRecord::setFrontClipAtEye(bool atEye) const
{
    return impObj()->setFrontClipAtEye(atEye);
}

PyDbObjectId PyDbAbstractViewTableRecord::background() const
{
    return PyDbObjectId(impObj()->background());
}

void PyDbAbstractViewTableRecord::setBackground(const PyDbObjectId& backgroundId) const
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbAbstractViewTableRecord::visualStyle() const
{
    return PyDbObjectId(impObj()->visualStyle());
}

void PyDbAbstractViewTableRecord::setVisualStyle(const PyDbObjectId& visualStyleId) const
{
    return PyThrowBadEs(impObj()->setVisualStyle(visualStyleId.m_id));
}

bool PyDbAbstractViewTableRecord::isDefaultLightingOn() const
{
    return impObj()->isDefaultLightingOn();
}

void PyDbAbstractViewTableRecord::setDefaultLightingOn(bool on) const
{
    return PyThrowBadEs(impObj()->setDefaultLightingOn(on));
}

AcGiViewportTraits::DefaultLightingType PyDbAbstractViewTableRecord::defaultLightingType() const
{
    return impObj()->defaultLightingType();
}

void PyDbAbstractViewTableRecord::setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ) const
{
    return PyThrowBadEs(impObj()->setDefaultLightingType(typ));
}

double PyDbAbstractViewTableRecord::brightness() const
{
    return impObj()->brightness();
}

void PyDbAbstractViewTableRecord::setBrightness(double val) const
{
    return PyThrowBadEs(impObj()->setBrightness(val));
}

double PyDbAbstractViewTableRecord::contrast() const
{
    return impObj()->contrast();
}

void PyDbAbstractViewTableRecord::setContrast(double val) const
{
    return PyThrowBadEs(impObj()->setContrast(val));
}

AcCmColor PyDbAbstractViewTableRecord::ambientLightColor() const
{
    return impObj()->ambientLightColor();
}

void PyDbAbstractViewTableRecord::setAmbientLightColor(const AcCmColor& clr) const
{
    return PyThrowBadEs(impObj()->setAmbientLightColor(clr));
}

PyDbObjectId PyDbAbstractViewTableRecord::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbAbstractViewTableRecord::setSun1(PyDbObjectId& retId, PyDbObject& pSun) const
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbAbstractViewTableRecord::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
}

boost::python::tuple PyDbAbstractViewTableRecord::getUcs() const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d xAxis;
    AcGeVector3d yAxis;
    PyThrowBadEs(impObj()->getUcs(origin, xAxis, yAxis));
    return boost::python::make_tuple(origin, xAxis, yAxis);
}

boost::python::tuple PyDbAbstractViewTableRecord::isUcsOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view;
    bool flag = impObj()->isUcsOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

PyDbObjectId PyDbAbstractViewTableRecord::ucsName() const
{
    return PyDbObjectId(impObj()->ucsName());
}

double PyDbAbstractViewTableRecord::elevation() const
{
    return impObj()->elevation();
}

void PyDbAbstractViewTableRecord::setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis) const
{
    return PyThrowBadEs(impObj()->setUcs(origin, xAxis, yAxis));
}

void PyDbAbstractViewTableRecord::setUcs2(AcDb::OrthographicView view) const
{
    return PyThrowBadEs(impObj()->setUcs(view));
}

void PyDbAbstractViewTableRecord::setUcs3(const PyDbObjectId& ucsId) const
{
    return PyThrowBadEs(impObj()->setUcs(ucsId.m_id));
}

void PyDbAbstractViewTableRecord::setUcsToWorld() const
{
    return PyThrowBadEs(impObj()->setUcsToWorld());
}

void PyDbAbstractViewTableRecord::setElevation(double elev) const
{
    return PyThrowBadEs(impObj()->setElevation(elev));
}

boost::python::tuple PyDbAbstractViewTableRecord::isViewOrthographic() const
{
    PyAutoLockGIL lock;
    AcDb::OrthographicView view;
    bool flag = impObj()->isViewOrthographic(view);
    return boost::python::make_tuple(flag, view);
}

std::string PyDbAbstractViewTableRecord::className()
{
    return "AcDbAbstractViewTableRecord";
}

PyRxClass PyDbAbstractViewTableRecord::desc()
{
    return PyRxClass(AcDbAbstractViewTableRecord::desc(), false);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAbstractViewTableRecord, AcDbAbstractViewTableRecord>(src);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAbstractViewTableRecord>(src);
}

AcDbAbstractViewTableRecord* PyDbAbstractViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAbstractViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setPreviousBackgroundOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, stype: PyGi.DrawableType, bForcedSwitch: bool\n";

    PyDocString DS("ViewportTableRecord");
    class_<PyDbViewportTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewportTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords,9958)))
        .def("number", &PyDbViewportTableRecord::number, DS.ARGS(9976))
        .def("lowerLeftCorner", &PyDbViewportTableRecord::lowerLeftCorner, DS.ARGS(9975))
        .def("setLowerLeftCorner", &PyDbViewportTableRecord::setLowerLeftCorner, DS.ARGS({ "val : PyGe.Point2d" }, 9993))
        .def("upperRightCorner", &PyDbViewportTableRecord::upperRightCorner, DS.ARGS(10010))
        .def("setUpperRightCorner", &PyDbViewportTableRecord::setUpperRightCorner, DS.ARGS({ "val : PyGe.Point2d" }, 10002))
        .def("ucsFollowMode", &PyDbViewportTableRecord::ucsFollowMode, DS.ARGS(10009))
        .def("setUcsFollowMode", &PyDbViewportTableRecord::setUcsFollowMode, DS.ARGS({ "val : bool" }, 10000))
        .def("circleSides", &PyDbViewportTableRecord::circleSides, DS.ARGS(9960))
        .def("setCircleSides", &PyDbViewportTableRecord::setCircleSides, DS.ARGS({ "val : int" }, 9980))
        .def("fastZoomsEnabled", &PyDbViewportTableRecord::fastZoomsEnabled, DS.ARGS(9962))
        .def("setFastZoomsEnabled", &PyDbViewportTableRecord::setFastZoomsEnabled, DS.ARGS({ "val : bool" }, 9981))
        .def("iconEnabled", &PyDbViewportTableRecord::iconEnabled, DS.ARGS(9968))
        .def("setIconEnabled", &PyDbViewportTableRecord::setIconEnabled, DS.ARGS({ "val : bool" }, 9991))
        .def("iconAtOrigin", &PyDbViewportTableRecord::iconAtOrigin, DS.ARGS(9967))
        .def("setIconAtOrigin", &PyDbViewportTableRecord::setIconAtOrigin, DS.ARGS({ "val : bool" }, 9990))
        .def("gridEnabled", &PyDbViewportTableRecord::gridEnabled, DS.ARGS(9963))
        .def("setGridEnabled", &PyDbViewportTableRecord::setGridEnabled, DS.ARGS({ "val : bool" }, 9984))
        .def("gridIncrements", &PyDbViewportTableRecord::gridIncrements, DS.ARGS(9964))
        .def("setGridIncrements", &PyDbViewportTableRecord::setGridIncrements, DS.ARGS({ "val : PyGe.Point2d" }, 9986))
        .def("snapEnabled", &PyDbViewportTableRecord::snapEnabled, DS.ARGS(10005))
        .def("setSnapEnabled", &PyDbViewportTableRecord::setSnapEnabled, DS.ARGS({ "val : bool" }, 9997))
        .def("isometricSnapEnabled", &PyDbViewportTableRecord::isometricSnapEnabled, DS.ARGS(9973))
        .def("setIsometricSnapEnabled", &PyDbViewportTableRecord::setIsometricSnapEnabled, DS.ARGS({ "val : bool" }, 9992))
        .def("snapPair", &PyDbViewportTableRecord::snapPair, DS.ARGS(10007))
        .def("setSnapPair", &PyDbViewportTableRecord::setSnapPair, DS.ARGS({ "val : int" }, 9999))
        .def("snapAngle", &PyDbViewportTableRecord::snapAngle, DS.ARGS(10003))
        .def("setSnapAngle", &PyDbViewportTableRecord::setSnapAngle, DS.ARGS({ "val : float" }, 9995))
        .def("snapBase", &PyDbViewportTableRecord::snapBase, DS.ARGS(10004))
        .def("setSnapBase", &PyDbViewportTableRecord::setSnapBase, DS.ARGS({ "val : PyGe.Point2d" }, 9996))
        .def("snapIncrements", &PyDbViewportTableRecord::snapIncrements, DS.ARGS(10006))
        .def("setSnapIncrements", &PyDbViewportTableRecord::setSnapIncrements, DS.ARGS({ "val : PyGe.Point2d" }, 9998))
        .def("gsView", &PyDbViewportTableRecord::gsView, DS.ARGS(9966))
        .def("setGsView", &PyDbViewportTableRecord::setGsView, DS.ARGS({ "val : PyGs.GsView" }, 9989))
        .def("isUcsSavedWithViewport", &PyDbViewportTableRecord::isUcsSavedWithViewport, DS.ARGS(9974))
        .def("setUcsPerViewport", &PyDbViewportTableRecord::setUcsPerViewport, DS.ARGS({ "val : bool" }, 10001))
        .def("isGridBoundToLimits", &PyDbViewportTableRecord::isGridBoundToLimits, DS.ARGS(9970))
        .def("setGridBoundToLimits", &PyDbViewportTableRecord::setGridBoundToLimits, DS.ARGS({ "val : bool" }, 9983))
        .def("isGridAdaptive", &PyDbViewportTableRecord::isGridAdaptive, DS.ARGS(9969))
        .def("setGridAdaptive", &PyDbViewportTableRecord::setGridAdaptive, DS.ARGS({ "val : bool" }, 9982))
        .def("isGridSubdivisionRestricted", &PyDbViewportTableRecord::isGridSubdivisionRestricted, DS.ARGS(9972))
        .def("setGridSubdivisionRestricted", &PyDbViewportTableRecord::setGridSubdivisionRestricted, DS.ARGS({ "val : bool" }, 9988))
        .def("isGridFollow", &PyDbViewportTableRecord::isGridFollow, DS.ARGS(9971))
        .def("setGridFollow", &PyDbViewportTableRecord::setGridFollow, DS.ARGS({ "val : bool" }, 9985))
        .def("gridMajor", &PyDbViewportTableRecord::gridMajor, DS.ARGS(9965))
        .def("setGridMajor", &PyDbViewportTableRecord::setGridMajor, DS.ARGS({ "val : int" }, 9987))
        .def("setBackground", &PyDbViewportTableRecord::setBackground, DS.ARGS({ "val : PyDb.ObjectId" }, 9979))
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground1)
        .def("previousBackground", &PyDbViewportTableRecord::previousBackground2, DS.ARGS({ "val: PyGi.DrawableType=PyGi.DrawableType.kGeometry" }, 9977))
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground1)
        .def("setPreviousBackground", &PyDbViewportTableRecord::setPreviousBackground2, DS.OVRL(setPreviousBackgroundOverloads, 9994))
        .def("previousBackgroundForcedSwitch", &PyDbViewportTableRecord::previousBackgroundForcedSwitch, DS.ARGS(9978))
        .def("className", &PyDbViewportTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewportTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbViewportTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewportTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbViewportTableRecord::PyDbViewportTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewportTableRecord(), true)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(AcDbViewportTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewportTableRecord>(id), false)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewportTableRecord>(id, mode), false)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewportTableRecord>(id, mode, erased), false)
{
}

Adesk::Int16 PyDbViewportTableRecord::number() const
{
    return impObj()->number();
}

AcGePoint2d PyDbViewportTableRecord::lowerLeftCorner() const
{
    return impObj()->lowerLeftCorner();
}

void PyDbViewportTableRecord::setLowerLeftCorner(const AcGePoint2d& pt) const
{
    return impObj()->setLowerLeftCorner(pt);
}

AcGePoint2d PyDbViewportTableRecord::upperRightCorner() const
{
    return impObj()->upperRightCorner();
}

void PyDbViewportTableRecord::setUpperRightCorner(const AcGePoint2d& pt) const
{
    return impObj()->setUpperRightCorner(pt);
}

bool PyDbViewportTableRecord::ucsFollowMode() const
{
    return impObj()->ucsFollowMode();
}

void PyDbViewportTableRecord::setUcsFollowMode(bool enabled) const
{
    return impObj()->setUcsFollowMode(enabled);
}

Adesk::UInt16 PyDbViewportTableRecord::circleSides() const
{
    return impObj()->circleSides();
}

void PyDbViewportTableRecord::setCircleSides(Adesk::UInt16 circleSides) const
{
    return impObj()->setCircleSides(circleSides);
}

bool PyDbViewportTableRecord::fastZoomsEnabled() const
{
    return impObj()->fastZoomsEnabled();
}

void PyDbViewportTableRecord::setFastZoomsEnabled(bool enabled) const
{
    return impObj()->setFastZoomsEnabled(enabled);
}

bool PyDbViewportTableRecord::iconEnabled() const
{
    return impObj()->iconEnabled();
}

void PyDbViewportTableRecord::setIconEnabled(bool enabled) const
{
    return impObj()->setIconEnabled(enabled);
}

bool PyDbViewportTableRecord::iconAtOrigin() const
{
    return impObj()->iconAtOrigin();
}

void PyDbViewportTableRecord::setIconAtOrigin(bool atOrigin) const
{
    return impObj()->setIconAtOrigin(atOrigin);
}

bool PyDbViewportTableRecord::gridEnabled() const
{
    return impObj()->gridEnabled();
}

void PyDbViewportTableRecord::setGridEnabled(bool enabled) const
{
    return impObj()->setGridEnabled(enabled);
}

AcGePoint2d PyDbViewportTableRecord::gridIncrements() const
{
    return impObj()->gridIncrements();
}

void PyDbViewportTableRecord::setGridIncrements(const AcGePoint2d& base) const
{
    return impObj()->setGridIncrements(base);
}

bool PyDbViewportTableRecord::snapEnabled() const
{
    return impObj()->snapEnabled();
}

void PyDbViewportTableRecord::setSnapEnabled(bool enabled) const
{
    return impObj()->setSnapEnabled(enabled);
}

bool PyDbViewportTableRecord::isometricSnapEnabled() const
{
    return impObj()->isometricSnapEnabled();
}

void PyDbViewportTableRecord::setIsometricSnapEnabled(bool enabled) const
{
    return impObj()->setIsometricSnapEnabled(enabled);
}

Adesk::Int16 PyDbViewportTableRecord::snapPair() const
{
    return impObj()->snapPair();
}

void PyDbViewportTableRecord::setSnapPair(Adesk::Int16 pairType) const
{
    return impObj()->setSnapPair(pairType);
}

double PyDbViewportTableRecord::snapAngle() const
{
    return impObj()->snapAngle();
}

void PyDbViewportTableRecord::setSnapAngle(double angle) const
{
    return impObj()->setSnapAngle(angle);
}

AcGePoint2d PyDbViewportTableRecord::snapBase() const
{
    return impObj()->snapBase();
}

void PyDbViewportTableRecord::setSnapBase(const AcGePoint2d& base) const
{
    return impObj()->setSnapBase(base);
}

AcGePoint2d PyDbViewportTableRecord::snapIncrements() const
{
    return impObj()->snapIncrements();
}

void PyDbViewportTableRecord::setSnapIncrements(const AcGePoint2d& base) const
{
    return impObj()->setSnapIncrements(base);
}

void PyDbViewportTableRecord::setGsView(PyGsView& pView) const
{
    impObj()->setGsView(pView.impObj());
}

PyGsView PyDbViewportTableRecord::gsView() const
{
    return PyGsView(impObj()->gsView(), false);
}

bool PyDbViewportTableRecord::isUcsSavedWithViewport() const
{
    return impObj()->isUcsSavedWithViewport();
}

void PyDbViewportTableRecord::setUcsPerViewport(bool ucsvp) const
{
    return impObj()->setUcsPerViewport(ucsvp);
}

bool PyDbViewportTableRecord::isGridBoundToLimits() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridBoundToLimits();
#endif
}

void PyDbViewportTableRecord::setGridBoundToLimits(bool enabled) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridBoundToLimits(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridAdaptive() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridAdaptive();
#endif
}

void PyDbViewportTableRecord::setGridAdaptive(bool enabled) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridAdaptive(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridSubdivisionRestricted() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridSubdivisionRestricted();
#endif
}

void PyDbViewportTableRecord::setGridSubdivisionRestricted(bool enabled) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridSubdivisionRestricted(enabled);
#endif
}

bool PyDbViewportTableRecord::isGridFollow() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isGridFollow();
#endif
}

void PyDbViewportTableRecord::setGridFollow(bool enabled) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridFollow(enabled);
#endif
}

Adesk::Int16 PyDbViewportTableRecord::gridMajor() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->gridMajor();
#endif
}

void PyDbViewportTableRecord::setGridMajor(Adesk::Int16 value) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->setGridMajor(value);
#endif
}

void PyDbViewportTableRecord::setBackground(const PyDbObjectId& backgroundId) const
{
    return PyThrowBadEs(impObj()->setBackground(backgroundId.m_id));
}

PyDbObjectId PyDbViewportTableRecord::previousBackground1() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground());
#endif
}

PyDbObjectId PyDbViewportTableRecord::previousBackground2(AcGiDrawable::DrawableType type) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->previousBackground(type));
#endif
}

void PyDbViewportTableRecord::setPreviousBackground1(PyDbObjectId& backgroundId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id));
#endif
}

void PyDbViewportTableRecord::setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPreviousBackground(backgroundId.m_id, type, bForcedSwitch));
#endif
}

bool PyDbViewportTableRecord::previousBackgroundForcedSwitch(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->previousBackgroundForcedSwitch();
#endif
}

std::string PyDbViewportTableRecord::className()
{
    return "AcDbViewportTableRecord";
}

PyRxClass PyDbViewportTableRecord::desc()
{
    return PyRxClass(AcDbViewportTableRecord::desc(), false);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewportTableRecord, AcDbViewportTableRecord>(src);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbViewportTableRecord>(src);
}

AcDbViewportTableRecord* PyDbViewportTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbViewportTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("ViewTableRecord");
    class_<PyDbViewTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 10223)))
        .def("annotationScale", &PyDbViewTableRecord::annotationScale, DS.ARGS(10225))
        .def("setAnnotationScale", &PyDbViewTableRecord::setAnnotationScale, DS.ARGS({ "val: PyDb.AnnotationScale" }, 10238))
        .def("setParametersFromViewport", &PyDbViewTableRecord::setParametersFromViewport, DS.ARGS({ "id: PyDb.ObjectId" }, 10246))
        .def("isPaperspaceView", &PyDbViewTableRecord::isPaperspaceView, DS.ARGS(10234))
        .def("setIsPaperspaceView", &PyDbViewTableRecord::setIsPaperspaceView, DS.ARGS({ "val : bool" }, 10242))
        .def("isUcsAssociatedToView", &PyDbViewTableRecord::isUcsAssociatedToView, DS.ARGS(10235))
        .def("disassociateUcsFromView", &PyDbViewTableRecord::disassociateUcsFromView, DS.ARGS(10227))
        .def("getCategoryName", &PyDbViewTableRecord::getCategoryName, DS.ARGS(10228))
        .def("setCategoryName", &PyDbViewTableRecord::setCategoryName, DS.ARGS({ "val : str" }, 10240))
        .def("getLayerState", &PyDbViewTableRecord::getLayerState, DS.ARGS(10229))
        .def("setLayerState", &PyDbViewTableRecord::setLayerState, DS.ARGS({ "val : str" }, 10243))
        .def("getLayout", &PyDbViewTableRecord::getLayout, DS.ARGS(10230))
        .def("setLayout", &PyDbViewTableRecord::setLayout, DS.ARGS({ "val : PyDb.ObjectId" }, 10244))
        .def("isViewAssociatedToViewport", &PyDbViewTableRecord::isViewAssociatedToViewport, DS.ARGS(10236))
        .def("setViewAssociatedToViewport", &PyDbViewTableRecord::setViewAssociatedToViewport, DS.ARGS({ "val : bool" }, 10250))
        .def("isCameraPlottable", &PyDbViewTableRecord::isCameraPlottable, DS.ARGS(10233))
        .def("setIsCameraPlottable", &PyDbViewTableRecord::setIsCameraPlottable, DS.ARGS({ "val : bool" }, 10241))
        .def("liveSection", &PyDbViewTableRecord::liveSection, DS.ARGS(10237))
        .def("setLiveSection", &PyDbViewTableRecord::setLiveSection, DS.ARGS({ "val : PyDb.ObjectId" }, 10245))
        .def("camera", &PyDbViewTableRecord::camera, DS.ARGS(10226))
        .def("setCamera", &PyDbViewTableRecord::setCamera, DS.ARGS({ "val : PyDb.ObjectId" }, 10239))
        .def("sunId", &PyDbViewTableRecord::sunId, DS.ARGS(10252))
        .def("setSun", &PyDbViewTableRecord::setSun1)
        .def("setSun", &PyDbViewTableRecord::setSun2, DS.ARGS({ "retId : PyDb.ObjectId","pSun : PyDb.Object","eraseOldSun : bool=True" }, 10248))
        .def("className", &PyDbViewTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbViewTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbViewTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbViewTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbViewTableRecord::PyDbViewTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewTableRecord(), true)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(AcDbViewTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewTableRecord>(id), false)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewTableRecord>(id, mode), false)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbAbstractViewTableRecord(openAcDbObject<AcDbViewTableRecord>(id, mode, erased), false)
{
}

void PyDbViewTableRecord::setParametersFromViewport(PyDbObjectId& objId) const
{
    return PyThrowBadEs(impObj()->setParametersFromViewport(objId.m_id));
}

bool PyDbViewTableRecord::isPaperspaceView() const
{
    return impObj()->isPaperspaceView();
}

void PyDbViewTableRecord::setIsPaperspaceView(bool pspace) const
{
    return impObj()->setIsPaperspaceView(pspace);
}

bool PyDbViewTableRecord::isUcsAssociatedToView() const
{
    return impObj()->isUcsAssociatedToView();
}

void PyDbViewTableRecord::disassociateUcsFromView() const
{
    return PyThrowBadEs(impObj()->disassociateUcsFromView());
}

std::string PyDbViewTableRecord::getCategoryName() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getCategoryName(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getCategoryName(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbViewTableRecord::setCategoryName(const std::string& categoryName) const
{
    return PyThrowBadEs(impObj()->setCategoryName(utf8_to_wstr(categoryName).c_str()));
}

std::string PyDbViewTableRecord::getLayerState() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getLayerState(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getLayerState(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbViewTableRecord::setLayerState(const std::string& layerStateName) const
{
    return PyThrowBadEs(impObj()->setLayerState(utf8_to_wstr(layerStateName).c_str()));
}

PyDbObjectId PyDbViewTableRecord::getLayout() const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getLayout(id.m_id));
    return id;
}

void PyDbViewTableRecord::setLayout(const PyDbObjectId& layoutId) const
{
    return PyThrowBadEs(impObj()->setLayout(layoutId.m_id));
}

bool PyDbViewTableRecord::isViewAssociatedToViewport() const
{
    return impObj()->isViewAssociatedToViewport();
}

void PyDbViewTableRecord::setViewAssociatedToViewport(bool bVPflag) const
{
    return PyThrowBadEs(impObj()->setViewAssociatedToViewport(bVPflag));
}

bool PyDbViewTableRecord::isCameraPlottable() const
{
    return impObj()->isCameraPlottable();
}

void PyDbViewTableRecord::setIsCameraPlottable(bool plottable) const
{
    return PyThrowBadEs(impObj()->setIsCameraPlottable(plottable));
}

PyDbObjectId PyDbViewTableRecord::liveSection() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->liveSection());
#endif
}

void PyDbViewTableRecord::setLiveSection(const PyDbObjectId& liveSectionId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setLiveSection(liveSectionId.m_id));
#endif
}

PyDbObjectId PyDbViewTableRecord::camera() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->camera());
#endif
}

void PyDbViewTableRecord::setCamera(const PyDbObjectId& cameraId) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCamera(cameraId.m_id));
#endif
}

PyDbAnnotationScale PyDbViewTableRecord::annotationScale() const
{
    return PyDbAnnotationScale(impObj()->annotationScale());
}

void PyDbViewTableRecord::setAnnotationScale(const PyDbAnnotationScale& pScaleObj) const
{
    return PyThrowBadEs(impObj()->setAnnotationScale(pScaleObj.impObj()));
}

PyDbObjectId PyDbViewTableRecord::sunId() const
{
    return PyDbObjectId(impObj()->sunId());
}

void PyDbViewTableRecord::setSun1(PyDbObjectId& retId, PyDbObject& pSun) const
{
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj()));
}

void PyDbViewTableRecord::setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSun(retId.m_id, pSun.impObj(), eraseOldSun));
#endif
}

std::string PyDbViewTableRecord::className()
{
    return "AcDbViewTableRecord";
}

PyRxClass PyDbViewTableRecord::desc()
{
    return PyRxClass(AcDbViewTableRecord::desc(), false);
}

PyDbViewTableRecord PyDbViewTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewTableRecord, AcDbViewTableRecord>(src);
}

PyDbViewTableRecord PyDbViewTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbViewTableRecord>(src);
}

AcDbViewTableRecord* PyDbViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbSortentsTable
void makePyDbSortentsTableWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.SortentsTable");
    class_<PyDbSortentsTable, bases<PyDbObject>>("SortentsTable")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctor, 8677)))
        .def("sortAs", &PyDbSortentsTable::sortAs, DS.ARGS({ "id: PyDb.ObjectId" }, 8697))
        .def("getSortHandle", &PyDbSortentsTable::getSortHandle, DS.ARGS({ "id: PyDb.ObjectId" }, 8689))
        .def("remove", &PyDbSortentsTable::remove, DS.ARGS({ "id: PyDb.ObjectId" }, 8694))
        .def("moveToBottom", &PyDbSortentsTable::moveToBottom, DS.ARGS({ "ids:Collection[PyDb.ObjectId]" }, 8692))
        .def("moveToTop", &PyDbSortentsTable::moveToTop, DS.ARGS({ "ids:Collection[PyDb.ObjectId]" }, 8693))
        .def("moveBelow", &PyDbSortentsTable::moveBelow, DS.ARGS({ "ids:Collection[PyDb.ObjectId]","target: PyDb.ObjectId" }, 8691))
        .def("moveAbove", &PyDbSortentsTable::moveAbove, DS.ARGS({ "ids:Collection[PyDb.ObjectId]","target: PyDb.ObjectId" }, 8690))
        .def("swapOrder", &PyDbSortentsTable::swapOrder, DS.ARGS({ "left: PyDb.ObjectId" , "right: PyDb.ObjectId" }, 8699))
        .def("setBlockId", &PyDbSortentsTable::setBlockId, DS.ARGS({ "id: PyDb.ObjectId" }, 8695))
        .def("blockId", &PyDbSortentsTable::blockId, DS.ARGS(8681))
        .def("firstEntityIsDrawnBeforeSecond", &PyDbSortentsTable::firstEntityIsDrawnBeforeSecond, DS.ARGS({ "first: PyDb.ObjectId" , "second: PyDb.ObjectId" }, 8686))
        .def("getFullDrawOrder", &PyDbSortentsTable::getFullDrawOrder, DS.ARGS({ "mask:int" }, 8687))
        .def("getRelativeDrawOrder", &PyDbSortentsTable::getRelativeDrawOrder, DS.ARGS({ "mask:int" }, 8688))
        .def("setRelativeDrawOrder", &PyDbSortentsTable::setRelativeDrawOrder, DS.ARGS({ "ids:Collection[PyDb.ObjectId]" }, 8696))
        .def("desc", &PyDbSortentsTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbSortentsTable::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbSortentsTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSortentsTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSortentsTable::PyDbSortentsTable()
    : PyDbSortentsTable(new AcDbSortentsTable(), true)
{
}

PyDbSortentsTable::PyDbSortentsTable(const PyDbObjectId& id)
    : PyDbSortentsTable(openAcDbObject<AcDbSortentsTable>(id), false)
{
}

PyDbSortentsTable::PyDbSortentsTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSortentsTable(openAcDbObject<AcDbSortentsTable>(id, mode), false)
{
}

PyDbSortentsTable::PyDbSortentsTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSortentsTable(openAcDbObject<AcDbSortentsTable>(id, mode, erased), false)
{
}

PyDbSortentsTable::PyDbSortentsTable(AcDbSortentsTable* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

boost::python::tuple PyDbSortentsTable::sortAs(const PyDbObjectId& id) const
{
    PyAutoLockGIL lock;
    PyDbHandle h;
    auto flag = impObj()->sortAs(id.m_id, h.m_hnd);
    return boost::python::make_tuple(flag, h);
}

PyDbHandle PyDbSortentsTable::getSortHandle(const PyDbObjectId& id) const
{
    PyDbHandle h;
    impObj()->getSortHandle(id.m_id, h.m_hnd);
    return h;
}

void PyDbSortentsTable::remove(const PyDbObjectId& id) const
{
#ifdef _BRXTARGET250
    throw PyNotimplementedByHost{};
#else
    PyThrowBadEs(impObj()->remove(id.m_id));
#endif
}

void PyDbSortentsTable::moveToBottom(const boost::python::object& pylist) const
{
    PyThrowBadEs(impObj()->moveToBottom(PyListToObjectIdArray(pylist)));
}

void PyDbSortentsTable::moveToTop(const boost::python::object& pylist) const
{
    PyThrowBadEs(impObj()->moveToTop(PyListToObjectIdArray(pylist)));
}

void PyDbSortentsTable::moveBelow(const boost::python::object& pylist, const PyDbObjectId& target) const
{
    PyThrowBadEs(impObj()->moveBelow(PyListToObjectIdArray(pylist), target.m_id));
}

void PyDbSortentsTable::moveAbove(const boost::python::object& pylist, const PyDbObjectId& target) const
{
    PyThrowBadEs(impObj()->moveAbove(PyListToObjectIdArray(pylist), target.m_id));
}

void PyDbSortentsTable::swapOrder(const PyDbObjectId& left, const PyDbObjectId& right) const
{
    PyThrowBadEs(impObj()->swapOrder(left.m_id, right.m_id));
}

void PyDbSortentsTable::setBlockId(const PyDbObjectId& id) const
{
    PyThrowBadEs(impObj()->setBlockId(id.m_id));
}

PyDbObjectId PyDbSortentsTable::blockId() const
{
    return PyDbObjectId{ impObj()->blockId() };
}

bool PyDbSortentsTable::firstEntityIsDrawnBeforeSecond(const PyDbObjectId& first, const PyDbObjectId& second) const
{
#if defined(_BRXTARGET)
    auto db = impObj()->database();
    if (db == nullptr)
        PyThrowBadEs(Acad::eNotInDatabase);
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getFullDrawOrder(ids, db->sortEnts()));
    for (auto& id : ids)
    {
        if (id == second.m_id)
            return false;
        else if (id == first.m_id)
            return true;
    }
    PyThrowBadEs(Acad::eInvalidInput);
    return false;
#else
    bool flag = false;
    PyThrowBadEs(impObj()->firstEntityIsDrawnBeforeSecond(first.m_id, second.m_id, flag));
    return flag;
#endif
}

boost::python::list PyDbSortentsTable::getFullDrawOrder(int mask) const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getFullDrawOrder(ids, mask));
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbSortentsTable::getRelativeDrawOrder(int mask) const
{
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getRelativeDrawOrder(ids, mask));
    return ObjectIdArrayToPyList(ids);
}

void PyDbSortentsTable::setRelativeDrawOrder(const boost::python::object& pylist) const
{
    PyThrowBadEs(impObj()->setRelativeDrawOrder(PyListToObjectIdArray(pylist)));
}

std::string PyDbSortentsTable::className()
{
    return "AcDbSortentsTable";
}

PyRxClass PyDbSortentsTable::desc()
{
    return PyRxClass(AcDbSortentsTable::desc(), false);
}

PyDbSortentsTable PyDbSortentsTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSortentsTable, AcDbSortentsTable>(src);
}

PyDbSortentsTable PyDbSortentsTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSortentsTable>(src);
}

AcDbSortentsTable* PyDbSortentsTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSortentsTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makePyDbBlockTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view objectIdsOverloads = "Overloads:\n"
        "desc: PyRx.RxClass=PyDb.Entity\n"
        "descList: list[PyRx.RxClass]\n";

    PyDocString DS("BlockTableRecord");
    class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("BlockTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 2541)))
        .def("appendAcDbEntity", &PyDbBlockTableRecord::appendAcDbEntity, DS.ARGS({ "entity : PyDb.Entity" }, 2553))
        .def("appendAcDbEntities", &PyDbBlockTableRecord::appendAcDbEntities, DS.ARGS({ "entities : Collection[PyDb.Entity]" }, 2553))
        .def("objectIds", &PyDbBlockTableRecord::objectIds)
        .def("objectIds", &PyDbBlockTableRecord::objectIdsOfType)
        .def("objectIds", &PyDbBlockTableRecord::objectIdsOfTypeList, DS.OVRL(objectIdsOverloads))
        .def("comments", &PyDbBlockTableRecord::comments, DS.ARGS(2558))
        .def("setComments", &PyDbBlockTableRecord::setComments, DS.ARGS({ "val : str" }, 2585))
        .def("pathName", &PyDbBlockTableRecord::pathName, DS.ARGS(2581))
        .def("setPathName", &PyDbBlockTableRecord::setPathName, DS.ARGS({ "val : str" }, 2591))
        .def("origin", &PyDbBlockTableRecord::origin, DS.ARGS(2580))
        .def("setOrigin", &PyDbBlockTableRecord::setOrigin, DS.ARGS({ "val : PyGe.Point3d" }, 2590))
        .def("openBlockBegin", &PyDbBlockTableRecord::openBlockBegin, DS.ARGS({ "val: PyDb.BlockBegin", "mode: PyDb.OpenMode" }, 2578))
        .def("openBlockEnd", &PyDbBlockTableRecord::openBlockEnd, DS.ARGS({ "val: PyDb.BlockEnd", "mode: PyDb.OpenMode" }, 2579))
        .def("hasAttributeDefinitions", &PyDbBlockTableRecord::hasAttributeDefinitions, DS.ARGS(2569))
        .def("hasPreviewIcon", &PyDbBlockTableRecord::hasPreviewIcon, DS.ARGS(2570))
        .def("getPreviewIcon", &PyDbBlockTableRecord::getPreviewIcon, DS.ARGS(2567))
        .def("clearPreviewIcon", &PyDbBlockTableRecord::clearPreviewIcon, DS.ARGS())
        .def("isAnonymous", &PyDbBlockTableRecord::isAnonymous, DS.ARGS(2571))
        .def("isDynamicBlock", &PyDbBlockTableRecord::isDynamicBlock, DS.ARGS())
        .def("isFromExternalReference", &PyDbBlockTableRecord::isFromExternalReference, DS.ARGS(2572))
        .def("isFromOverlayReference", &PyDbBlockTableRecord::isFromOverlayReference, DS.ARGS(2573))
        .def("setIsFromOverlayReference", &PyDbBlockTableRecord::setIsFromOverlayReference, DS.ARGS({ "val : bool" }, 2587))
        .def("isLayout", &PyDbBlockTableRecord::isLayout, DS.ARGS(2574))
        .def("getLayoutId", &PyDbBlockTableRecord::getLayoutId, DS.ARGS(2566))
        .def("setLayoutId", &PyDbBlockTableRecord::setLayoutId, DS.ARGS({ "val : PyDb.ObjectId" }, 2589))
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds1)
        .def("getBlockReferenceIds", &PyDbBlockTableRecord::getBlockReferenceIds2, DS.ARGS({ "directOnly : bool = True" ,"bForceValidity : bool = False" }, 2564))
        .def("getErasedBlockReferenceIds", &PyDbBlockTableRecord::getErasedBlockReferenceIds, DS.ARGS(2565))
        .def("xrefDatabase", &PyDbBlockTableRecord::xrefDatabase, DS.ARGS({ "val : bool" }, 2594))
        .def("isUnloaded", &PyDbBlockTableRecord::isUnloaded, DS.ARGS(2575))
        .def("setIsUnloaded", &PyDbBlockTableRecord::setIsUnloaded, DS.ARGS({ "val : bool" }, 2588))
        .def("xrefStatus", &PyDbBlockTableRecord::xrefStatus, DS.ARGS(2595))
        .def("assumeOwnershipOf", &PyDbBlockTableRecord::assumeOwnershipOf, DS.ARGS({ "entities : Collection[PyDb.Entity]" }, 2554))
        .def("blockScaling", &PyDbBlockTableRecord::blockScaling, DS.ARGS(2556))
        .def("setBlockScaling", &PyDbBlockTableRecord::setBlockScaling, DS.ARGS({ "val : PyDb.BlockScaling" }, 2584))
        .def("setExplodable", &PyDbBlockTableRecord::setExplodable, DS.ARGS({ "val : bool" }, 2586))
        .def("explodable", &PyDbBlockTableRecord::explodable, DS.ARGS(2563))
        .def("setBlockInsertUnits", &PyDbBlockTableRecord::setBlockInsertUnits, DS.ARGS({ "val : PyDb.UnitsValue" }, 2583))
        .def("blockInsertUnits", &PyDbBlockTableRecord::blockInsertUnits, DS.ARGS(2555))
        .def("postProcessAnnotativeBTR", &PyDbBlockTableRecord::postProcessAnnotativeBTR, DS.ARGS({ "bqueryOnly  : bool = False" ,"bScale : bool = True" }, 2582))
        .def("addAnnoScalestoBlkRefs", &PyDbBlockTableRecord::addAnnoScalestoBlkRefs, DS.ARGS({ "scale : bool" }, 2552))
        .def("getSortentsTable", &PyDbBlockTableRecord::getSortentsTable1)
        .def("getSortentsTable", &PyDbBlockTableRecord::getSortentsTable2, DS.ARGS({ "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "createIfNecessary:bool = False" }, 2568))
        .def("effectiveName", &PyDbBlockTableRecord::effectiveName, DS.ARGS())
        .def("__iter__", range(&PyDbBlockTableRecord::begin, &PyDbBlockTableRecord::end))
        .def("className", &PyDbBlockTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//helper
static bool getIsDynamicBlockImpl(AcDbBlockTableRecord* pBlockTableRecord)
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 250)
    return AcDbDynBlockTableRecord::isDynamicBlock(pBlockTableRecord);
#elif defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    constexpr const wchar_t* key = L"ACAD_ENHANCEDBLOCK";
    if (AcDbEvalGraph* graphPtr = nullptr; AcDbEvalGraph::getGraph(pBlockTableRecord, key, &graphPtr, AcDb::OpenMode::kForRead) == eOk)
    {
        if (graphPtr != nullptr)
        {
            graphPtr->close();
            return true;
        }
    }
    return false;
#endif
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord
PyDbBlockTableRecord::PyDbBlockTableRecord()
    : PyDbSymbolTableRecord(new AcDbBlockTableRecord(), true)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbBlockTableRecord>(id), false)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbBlockTableRecord>(id, mode), false)
{
}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbBlockTableRecord>(id, mode, erased), false)
{
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent) const
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyDbObjectId id;
    PyThrowBadEs(impObj()->appendAcDbEntity(id.m_id, ent.impObj()));
    return id;
}

boost::python::list PyDbBlockTableRecord::appendAcDbEntities(const boost::python::object& entities) const
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& ents = py_list_to_std_vector<PyDbEntity>(entities);
    for (const auto& ent : ents)
        pylist.append(appendAcDbEntity(ent));
    return pylist;
}

boost::python::list PyDbBlockTableRecord::objectIds() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es != eOk)
        return pyList;

    PyDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (iter->getEntityId(id.m_id) == eOk)
            pyList.append(id);
    }
    return pyList;
}

boost::python::list PyDbBlockTableRecord::objectIdsOfType(const PyRxClass& _class) const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto _desc = _class.impObj();
    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es != eOk)
        return pyList;

    PyDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (const auto es = iter->getEntityId(id.m_id); es == eOk && id.m_id.objectClass()->isDerivedFrom(_desc))
            pyList.append(id);
    }
    return pyList;
}

boost::python::list PyDbBlockTableRecord::objectIdsOfTypeList(const boost::python::list& _classes) const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;

    auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es != eOk)
        return pyList;

    std::unordered_set<AcRxClass*> _set;
    for (auto& item : py_list_to_std_vector<PyRxClass>(_classes))
        _set.insert(item.impObj());

    PyDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (const auto es = iter->getEntityId(id.m_id); es == eOk && _set.contains(id.m_id.objectClass()))
            pyList.append(id);
    }
    return pyList;

}

std::string PyDbBlockTableRecord::comments() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    impObj()->comments(str.buf);
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    impObj()->comments(str);
    return wstr_to_utf8(str);
#endif
}

void PyDbBlockTableRecord::setComments(const std::string& pString) const
{
    return PyThrowBadEs(impObj()->setComments(utf8_to_wstr(pString).c_str()));
}

std::string PyDbBlockTableRecord::pathName() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    impObj()->pathName(str.buf);
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    impObj()->pathName(str);
    return wstr_to_utf8(str);
#endif
}

void PyDbBlockTableRecord::setPathName(const std::string& pString) const
{
    return PyThrowBadEs(impObj()->setPathName(utf8_to_wstr(pString).c_str()));
}

AcGePoint3d PyDbBlockTableRecord::origin() const
{
    return impObj()->origin();
}

void PyDbBlockTableRecord::setOrigin(const AcGePoint3d& pt) const
{
    return PyThrowBadEs(impObj()->setOrigin(pt));
}

//TODO: wrong
void PyDbBlockTableRecord::openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode) const
{
    AcDbBlockBegin* pObj = nullptr;
    PyThrowBadEs(impObj()->openBlockBegin(pObj, openMode));
    pBlockBegin = PyDbBlockBegin(pObj, false);
}

void PyDbBlockTableRecord::openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode) const
{
    AcDbBlockEnd* pObj = nullptr;
    PyThrowBadEs(impObj()->openBlockEnd(pObj, openMode));
    pBlockBegin = PyDbBlockEnd(pObj, false);
}

bool PyDbBlockTableRecord::hasAttributeDefinitions() const
{
    return impObj()->hasAttributeDefinitions();
}

bool PyDbBlockTableRecord::hasPreviewIcon() const
{
    return impObj()->hasPreviewIcon();
}

//TODO remove hack
static void addBITMAPFILEHEADER(AcDbBlockTableRecord::PreviewIcon& ico)
{
    //BITMAPFILEHEADER
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x36);//offset BITMAPFILEHEADER + BITMAPINFO
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x0);//0 file size? ico.length()ok
    ico.insertAt(0, 0x0);
    ico.insertAt(0, 0x4D);
    ico.insertAt(0, 0x42);//BM0
}

boost::python::object PyDbBlockTableRecord::getPreviewIcon() const
{
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt8> previewIcon;
    previewIcon.setLogicalLength(2048);
    PyThrowBadEs(impObj()->getPreviewIcon(previewIcon));
    addBITMAPFILEHEADER(previewIcon);
    wxMemoryInputStream stream(previewIcon.asArrayPtr(), previewIcon.length());
    wxImage img(stream);
    wxBitmap* bmp = new wxBitmap(img);
    if (!bmp->IsOk())
        PyThrowBadEs(Acad::eInvalidPreviewImage);
    return boost::python::object(boost::python::handle<>(wxPyConstructObject(bmp, wxT("wxBitmap"), true)));
}

void PyDbBlockTableRecord::clearPreviewIcon() const
{
    static AcArray<Adesk::UInt8> previewIcon;
    PyThrowBadEs(impObj()->setPreviewIcon(previewIcon));
}

bool PyDbBlockTableRecord::isAnonymous() const
{
    return impObj()->isAnonymous();
}

bool PyDbBlockTableRecord::isDynamicBlock() const
{
    return getIsDynamicBlockImpl(impObj());
}

bool PyDbBlockTableRecord::isFromExternalReference() const
{
    return impObj()->isFromExternalReference();
}

bool PyDbBlockTableRecord::isFromOverlayReference() const
{
    return impObj()->isFromOverlayReference();
}

void PyDbBlockTableRecord::setIsFromOverlayReference(bool bIsOverlay) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIsFromOverlayReference(bIsOverlay));
#endif
}

bool PyDbBlockTableRecord::isLayout() const
{
    return impObj()->isLayout();
}

PyDbObjectId PyDbBlockTableRecord::getLayoutId() const
{
    return PyDbObjectId(impObj()->getLayoutId());
}

void PyDbBlockTableRecord::setLayoutId(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setLayoutId(id.m_id));
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds1() const
{
    AcDbObjectIdArray ids;
    impObj()->getBlockReferenceIds(ids);
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbBlockTableRecord::getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity) const
{
    AcDbObjectIdArray ids;
    impObj()->getBlockReferenceIds(ids, bDirectOnly, bForceValidity);
    return ObjectIdArrayToPyList(ids);
}

boost::python::list PyDbBlockTableRecord::getErasedBlockReferenceIds() const
{
    AcDbObjectIdArray ids;
    impObj()->getErasedBlockReferenceIds(ids);
    return ObjectIdArrayToPyList(ids);
}

PyDbDatabase PyDbBlockTableRecord::xrefDatabase(bool incUnres) const
{
    return PyDbDatabase(impObj()->xrefDatabase(incUnres));
}

bool PyDbBlockTableRecord::isUnloaded() const
{
    return impObj()->isUnloaded();
}

void PyDbBlockTableRecord::setIsUnloaded(bool isUnloaded) const
{
    return PyThrowBadEs(impObj()->setIsUnloaded(isUnloaded));
}

AcDb::XrefStatus PyDbBlockTableRecord::xrefStatus() const
{
    return impObj()->xrefStatus();
}

void PyDbBlockTableRecord::assumeOwnershipOf(const boost::python::object& entitiesToMove) const
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids = PyListToObjectIdArray(entitiesToMove);
    return PyThrowBadEs(impObj()->assumeOwnershipOf(ids));
}

AcDbBlockTableRecord::BlockScaling PyDbBlockTableRecord::blockScaling() const
{
    return impObj()->blockScaling();
}

void PyDbBlockTableRecord::setBlockScaling(AcDbBlockTableRecord::BlockScaling _blockScaling) const
{
    return PyThrowBadEs(impObj()->setBlockScaling(_blockScaling));
}

void PyDbBlockTableRecord::setExplodable(bool bExplodable) const
{
    return PyThrowBadEs(impObj()->setExplodable(bExplodable));
}

bool PyDbBlockTableRecord::explodable() const
{
    return impObj()->explodable();
}

void PyDbBlockTableRecord::setBlockInsertUnits(AcDb::UnitsValue insunits) const
{
    return PyThrowBadEs(impObj()->setBlockInsertUnits(insunits));
}

AcDb::UnitsValue PyDbBlockTableRecord::blockInsertUnits() const
{
    return impObj()->blockInsertUnits();
}

int PyDbBlockTableRecord::postProcessAnnotativeBTR(bool bqueryOnly, bool bScale) const
{
    int stripCnt = 0;
    PyThrowBadEs(impObj()->postProcessAnnotativeBTR(stripCnt, bqueryOnly, bScale));
    return stripCnt;
}

void PyDbBlockTableRecord::addAnnoScalestoBlkRefs(bool bScale /*= false*/) const
{
    return PyThrowBadEs(impObj()->addAnnoScalestoBlkRefs(bScale));
}

PyDbSortentsTable PyDbBlockTableRecord::getSortentsTable1() const
{
    AcDbSortentsTable* ptr = nullptr;
    PyThrowBadEs(impObj()->getSortentsTable(ptr, AcDb::OpenMode::kForRead, false));
    return PyDbSortentsTable(ptr, false);
}

PyDbSortentsTable PyDbBlockTableRecord::getSortentsTable2(AcDb::OpenMode openMode, bool createIfNecessary) const
{
    AcDbSortentsTable* ptr = nullptr;
    PyThrowBadEs(impObj()->getSortentsTable(ptr, openMode, createIfNecessary));
    return PyDbSortentsTable(ptr, false);
}

std::string PyDbBlockTableRecord::effectiveName() const
{
    AcString efname;
    if (impObj()->isAnonymous())
    {
#if defined (_BRXTARGET)//(SR196681)
        if (AcDbObjectIdArray refids; impObj()->getBlockReferenceIds(refids) == eOk && refids.length() != 0)
        {
            if (efname = acdbEffectiveBlockRefName(refids.at(0)); !efname.isEmpty())
                return wstr_to_utf8(efname);
        }
#endif
        AcResBufPtr rb(impObj()->xData(L"AcDbBlockRepBTag"));
        for (resbuf* pTail = rb.get(); pTail != nullptr; pTail = pTail->rbnext)
        {
            if (pTail->restype == 1005)
            {
                AcDbHandle hnd(pTail->resval.rstring);
                if (AcDbObjectId id; impObj()->database()->getAcDbObjectId(id, false, hnd) == eOk && id.isValid())
                {
                    if (AcDbBlockTableRecordPointer btr(id); btr.openStatus() == eOk)
                    {
                        if (btr->getName(efname) == eOk)
                            return wstr_to_utf8(efname);
                    }
                }
            }
        }
    }
    PyThrowBadEs(impObj()->getName(efname));
    return wstr_to_utf8(efname);
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

PyRxClass PyDbBlockTableRecord::desc()
{
    return PyRxClass(AcDbBlockTableRecord::desc(), false);
}

PyDbBlockTableRecord PyDbBlockTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbBlockTableRecord, AcDbBlockTableRecord>(src);
}

PyDbBlockTableRecord PyDbBlockTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBlockTableRecord>(src);
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbBlockTableRecord*>(m_pyImp.get());
}

void PyDbBlockTableRecord::filliterator()
{
    const auto [es, iter] = makeBlockTableRecordIterator(*impObj());
    if (es == eOk)
    {
        PyDbObjectId id;
        m_iterable.clear();
        for (iter->start(); !iter->done(); iter->step())
        {
            if (iter->getEntityId(id.m_id) == eOk)
                m_iterable.push_back(id);
        }
    }
    PyThrowBadEs(es);
}

std::vector<PyDbObjectId>::iterator PyDbBlockTableRecord::begin()
{
    return m_iterable.begin();
}

std::vector<PyDbObjectId>::iterator PyDbBlockTableRecord::end()
{
    filliterator();
    return m_iterable.end();
}

//---------------------------------------------------------------------------------------- -
// PyDbDynBlockTableRecord
void makePyDbDynBlockTableRecordWrapper()
{
    PyDocString DS("DynBlockTableRecord");
    class_<PyAcDbDynBlockTableRecord>("DynBlockTableRecord", no_init)
        .def(init<const PyDbObjectId&>(DS.ARGS({ "val : PyDb.ObjectId" }, 4219)))
        .def("isDynamicBlock", &PyAcDbDynBlockTableRecord::isDynamicBlock, DS.ARGS(4223))
        .def("blockTableRecordId", &PyAcDbDynBlockTableRecord::blockTableRecordId, DS.ARGS(4221))
        .def("getAnonymousBlockIds", &PyAcDbDynBlockTableRecord::getAnonymousBlockIds, DS.ARGS(4222))
        .def("updateAnonymousBlocks", &PyAcDbDynBlockTableRecord::updateAnonymousBlocks, DS.ARGS(4224))
        .def("getIsDynamicBlock", &PyAcDbDynBlockTableRecord::getIsDynamicBlock1)
        .def("getIsDynamicBlock", &PyAcDbDynBlockTableRecord::getIsDynamicBlock2, DS.SARGS({ "otherObject: PyDb.ObjectId|PyDb.BlockTableRecord" })).staticmethod("getIsDynamicBlock")
        .def("className", &PyAcDbDynBlockTableRecord::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcDbDynBlockTableRecord::PyAcDbDynBlockTableRecord(const PyDbObjectId& id)
    : m_imp(new AcDbDynBlockTableRecord(id.m_id))
{
}

bool PyAcDbDynBlockTableRecord::isDynamicBlock() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isDynamicBlock();
#endif
}

PyDbObjectId PyAcDbDynBlockTableRecord::blockTableRecordId() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->blockTableRecordId());
#endif
}

boost::python::list PyAcDbDynBlockTableRecord::getAnonymousBlockIds() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids;
    PyThrowBadEs(impObj()->getAnonymousBlockIds(ids));
    return ObjectIdArrayToPyList(ids);
#endif
}

void PyAcDbDynBlockTableRecord::updateAnonymousBlocks() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->updateAnonymousBlocks());
#endif
}

bool PyAcDbDynBlockTableRecord::getIsDynamicBlock1(const PyDbObjectId& id)
{
    AcDbBlockTableRecordPointer pBlock(id.m_id);
    PyThrowBadEs(pBlock.openStatus());
    return getIsDynamicBlockImpl(pBlock);
}

bool PyAcDbDynBlockTableRecord::getIsDynamicBlock2(const PyDbBlockTableRecord& pBlockTableRecord)
{
    return getIsDynamicBlockImpl(pBlockTableRecord.impObj());
}

std::string PyAcDbDynBlockTableRecord::className()
{
    return "AcDbDynBlockTableRecord";
}

AcDbDynBlockTableRecord* PyAcDbDynBlockTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_imp.get();
#endif
}

//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
void makePyDbLayerTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("LayerTableRecord");
    class_<PyDbLayerTableRecord, bases<PyDbSymbolTableRecord>>("LayerTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 5773)))
        .def("isFrozen", &PyDbLayerTableRecord::isFrozen, DS.ARGS(5781))
        .def("setIsFrozen", &PyDbLayerTableRecord::setIsFrozen, DS.ARGS({ "frozen: bool" }, 5802))
        .def("isOff", &PyDbLayerTableRecord::isOff, DS.ARGS(5785))
        .def("setIsOff", &PyDbLayerTableRecord::setIsOff, DS.ARGS({ "off: bool" }, 5805))
        .def("VPDFLT", &PyDbLayerTableRecord::VPDFLT, DS.ARGS(5816))
        .def("setVPDFLT", &PyDbLayerTableRecord::setVPDFLT, DS.ARGS({ "frozen: bool" }, 5813))
        .def("isLocked", &PyDbLayerTableRecord::isLocked, DS.ARGS(5784))
        .def("setIsLocked", &PyDbLayerTableRecord::setIsLocked, DS.ARGS({ "locked: bool" }, 5804))
        .def("color", &PyDbLayerTableRecord::color1)
        .def("color", &PyDbLayerTableRecord::color2, DS.ARGS({ "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5775))
        .def("setColor", &PyDbLayerTableRecord::setColor1)
        .def("setColor", &PyDbLayerTableRecord::setColor2, DS.ARGS({ "clr: PyDb.AcCmColor", "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5800))
        .def("entityColor", &PyDbLayerTableRecord::entityColor, DS.ARGS(5778))
        .def("transparency", &PyDbLayerTableRecord::transparency1)
        .def("transparency", &PyDbLayerTableRecord::transparency2, DS.ARGS({ "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5815))
        .def("setTransparency", &PyDbLayerTableRecord::setTransparency1)
        .def("setTransparency", &PyDbLayerTableRecord::setTransparency2, DS.ARGS({ "clr: PyDb.Transparency", "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5812))
        .def("linetypeObjectId", &PyDbLayerTableRecord::linetypeObjectId, DS.ARGS(5788))
        .def("setLinetypeObjectId", &PyDbLayerTableRecord::setLinetypeObjectId, DS.ARGS({ "id: PyDb.ObjectId" }, 5808))
        .def("materialId", &PyDbLayerTableRecord::materialId, DS.ARGS(5790))
        .def("setMaterialId", &PyDbLayerTableRecord::setMaterialId, DS.ARGS({ "id: PyDb.ObjectId" }, 5810))
        .def("isPlottable", &PyDbLayerTableRecord::isPlottable, DS.ARGS(5786))
        .def("setIsPlottable", &PyDbLayerTableRecord::setIsPlottable, DS.ARGS({ "val: bool" }, 5806))
        .def("lineWeight", &PyDbLayerTableRecord::lineWeight1)
        .def("lineWeight", &PyDbLayerTableRecord::lineWeight2, DS.ARGS({ "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5789))
        .def("setLineWeight", &PyDbLayerTableRecord::setLineWeight1)
        .def("setLineWeight", &PyDbLayerTableRecord::setLineWeight2, DS.ARGS({ "weight: PyDb.LineWeight", "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5809))
        .def("plotStyleName", &PyDbLayerTableRecord::plotStyleName1)
        .def("plotStyleName", &PyDbLayerTableRecord::plotStyleName2, DS.ARGS({ "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5791))
        .def("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId1)
        .def("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId2, DS.ARGS({ "vpid: PyDb.ObjectId=PyDb.ObjectId.kNull" }, 5791))
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName1)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName2)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName3)
        .def("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName4, DS.ARGS({ "val: str|PyDb.ObjectId", "vpid : PyDb.ObjectId = PyDb.ObjectId.kNull" }, 5811))
        .def("isInUse", &PyDbLayerTableRecord::isInUse, DS.ARGS(5783))
        .def("description", &PyDbLayerTableRecord::description, DS.ARGS(5776))
        .def("setDescription", &PyDbLayerTableRecord::setDescription, DS.ARGS({ "val: str" }, 5801))
        .def("setIsHidden", &PyDbLayerTableRecord::setIsHidden, DS.ARGS({ "val: bool" }, 5803))
        .def("isHidden", &PyDbLayerTableRecord::isHidden, DS.ARGS(5782))
        .def("isHiddenS", &PyDbLayerTableRecord::isHiddenS, DS.SARGS({ "val : PyDb.ObjectId" })).staticmethod("isHiddenS")
        .def("removeColorOverride", &PyDbLayerTableRecord::removeColorOverride, DS.ARGS({ "id: PyDb.ObjectId" }, 5794))
        .def("removeLinetypeOverride", &PyDbLayerTableRecord::removeLinetypeOverride, DS.ARGS({ "id: PyDb.ObjectId" }, 5795))
        .def("removeLineWeightOverride", &PyDbLayerTableRecord::removeLineWeightOverride, DS.ARGS({ "id: PyDb.ObjectId" }, 5796))
        .def("removePlotStyleOverride", &PyDbLayerTableRecord::removePlotStyleOverride, DS.ARGS({ "id: PyDb.ObjectId" }, 5797))
        .def("removeTransparencyOverride", &PyDbLayerTableRecord::removeTransparencyOverride, DS.ARGS({ "id: PyDb.ObjectId" }, 5798))
        .def("removeViewportOverrides", &PyDbLayerTableRecord::removeViewportOverrides, DS.ARGS({ "id: PyDb.ObjectId" }, 5799))
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides, DS.ARGS(5793))
        .def("hasOverrides", &PyDbLayerTableRecord::hasOverrides, DS.ARGS({ "id: PyDb.ObjectId" }, 5780))
        .def("hasAnyOverrides", &PyDbLayerTableRecord::hasAnyOverrides, DS.ARGS(5779))
        .def("isReconciled", &PyDbLayerTableRecord::isReconciled, DS.ARGS(5787))
        .def("isReconciledS", &PyDbLayerTableRecord::isReconciledS, DS.SARGS({ "val : PyDb.ObjectId" })).staticmethod("isReconciledS")
        .def("className", &PyDbLayerTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLayerTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLayerTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLayerTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
PyDbLayerTableRecord::PyDbLayerTableRecord()
    :PyDbSymbolTableRecord(new AcDbLayerTableRecord(), true)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(AcDbLayerTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, false)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLayerTableRecord>(id), false)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLayerTableRecord>(id, mode), false)
{
}


PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLayerTableRecord>(id, mode, erased), false)
{
}

bool PyDbLayerTableRecord::isFrozen() const
{
    return impObj()->isFrozen();
}

void PyDbLayerTableRecord::setIsFrozen(bool frozen) const
{
    return PyThrowBadEs(impObj()->setIsFrozen(frozen));
}

bool PyDbLayerTableRecord::isOff() const
{
    return impObj()->isOff();
}

void PyDbLayerTableRecord::setIsOff(bool off) const
{
    return impObj()->setIsOff(off);
}

bool PyDbLayerTableRecord::VPDFLT() const
{
    return impObj()->VPDFLT();
}

void PyDbLayerTableRecord::setVPDFLT(bool frozen) const
{
    return impObj()->setVPDFLT(frozen);
}

bool PyDbLayerTableRecord::isLocked() const
{
    return impObj()->isLocked();
}

void PyDbLayerTableRecord::setIsLocked(bool locked) const
{
    return impObj()->setIsLocked(locked);
}

AcCmColor PyDbLayerTableRecord::color1() const
{
    return impObj()->color();
}

AcCmColor PyDbLayerTableRecord::color2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->color(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setColor1(const AcCmColor& _color) const
{
    return impObj()->setColor(_color);
}

void PyDbLayerTableRecord::setColor2(const AcCmColor& color, const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->setColor(color, viewportId.m_id));
}

AcCmEntityColor PyDbLayerTableRecord::entityColor(void) const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbLayerTableRecord::transparency1(void) const
{
    return impObj()->transparency();
}

AcCmTransparency PyDbLayerTableRecord::transparency2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->transparency(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setTransparency1(const AcCmTransparency& trans) const
{
    return PyThrowBadEs(impObj()->setTransparency(trans));
}

void PyDbLayerTableRecord::setTransparency2(const AcCmTransparency& trans, const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->setTransparency(trans, viewportId.m_id));
}

void PyDbLayerTableRecord::removeColorOverride(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removeColorOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeLinetypeOverride(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removeLinetypeOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeLineWeightOverride(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removeLineWeightOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removePlotStyleOverride(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removePlotStyleOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeTransparencyOverride(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removeTransparencyOverride(viewportId.m_id));
}

void PyDbLayerTableRecord::removeViewportOverrides(const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->removeViewportOverrides(viewportId.m_id));
}

void PyDbLayerTableRecord::removeAllOverrides() const
{
    return PyThrowBadEs(impObj()->removeAllOverrides());
}

bool PyDbLayerTableRecord::hasOverrides(const PyDbObjectId& viewportId) const
{
    return impObj()->hasOverrides(viewportId.m_id);
}

bool PyDbLayerTableRecord::hasAnyOverrides() const
{
    return impObj()->hasAnyOverrides();
}

PyDbObjectId PyDbLayerTableRecord::linetypeObjectId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

void PyDbLayerTableRecord::setLinetypeObjectId(const PyDbObjectId& id) const
{
#if defined(_BRXTARGET250)
    impObj()->setLinetypeObjectId(id.m_id);
#else
    return PyThrowBadEs(impObj()->setLinetypeObjectId(id.m_id));
#endif
}

PyDbObjectId PyDbLayerTableRecord::materialId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

void PyDbLayerTableRecord::setMaterialId(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setMaterialId(id.m_id));
}

bool PyDbLayerTableRecord::isPlottable() const
{
    return impObj()->isPlottable();
}

void PyDbLayerTableRecord::setIsPlottable(bool plot) const
{
    return PyThrowBadEs(impObj()->setIsPlottable(plot));
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight1() const
{
    return impObj()->lineWeight();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->lineWeight(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setLineWeight1(AcDb::LineWeight weight) const
{
    return PyThrowBadEs(impObj()->setLineWeight(weight));
}

void PyDbLayerTableRecord::setLineWeight2(AcDb::LineWeight weight, const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->setLineWeight(weight, viewportId.m_id));
}

std::string PyDbLayerTableRecord::plotStyleName1() const
{
    return wstr_to_utf8(impObj()->plotStyleName());
}

std::string PyDbLayerTableRecord::plotStyleName2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return wstr_to_utf8(impObj()->plotStyleName(viewportId.m_id, flag));
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId1() const
{
    return PyDbObjectId(impObj()->plotStyleNameId());
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId2(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return PyDbObjectId(impObj()->plotStyleNameId(viewportId.m_id, flag));
}

void PyDbLayerTableRecord::setPlotStyleName1(const std::string& newName) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str()));
}

void PyDbLayerTableRecord::setPlotStyleName2(const PyDbObjectId& newId) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(newId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName3(const std::string& newName, const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str(), viewportId.m_id));
}

void PyDbLayerTableRecord::setPlotStyleName4(const PyDbObjectId& newId, const PyDbObjectId& viewportId) const
{
    return PyThrowBadEs(impObj()->setPlotStyleName(newId.m_id, viewportId.m_id));
}

bool PyDbLayerTableRecord::isInUse() const
{
    return impObj()->isInUse();
}

std::string PyDbLayerTableRecord::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbLayerTableRecord::setDescription(const std::string& description) const
{
    return PyThrowBadEs(impObj()->setDescription(utf8_to_wstr(description).c_str()));
}

bool PyDbLayerTableRecord::isHidden() const
{
    return impObj()->isHidden();
}

bool PyDbLayerTableRecord::isHiddenS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isHidden(id.m_id);
}

void PyDbLayerTableRecord::setIsHidden(bool on) const
{
    return PyThrowBadEs(impObj()->setIsHidden(on));
}

bool PyDbLayerTableRecord::isReconciled() const
{
    return impObj()->isReconciled();
}

bool PyDbLayerTableRecord::isReconciledS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isReconciled(id.m_id);
}

void PyDbLayerTableRecord::setIsReconciled(bool bReconcile /*= true*/) const
{
    return PyThrowBadEs(impObj()->setIsReconciled(bReconcile));
}

std::string PyDbLayerTableRecord::className()
{
    return "AcDbLayerTableRecord";
}

PyRxClass PyDbLayerTableRecord::desc()
{
    return PyRxClass(AcDbLayerTableRecord::desc(), false);
}

PyDbLayerTableRecord PyDbLayerTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLayerTableRecord, AcDbLayerTableRecord>(src);
}

PyDbLayerTableRecord PyDbLayerTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLayerTableRecord>(src);
}

AcDbLayerTableRecord* PyDbLayerTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLayerTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbTextStyleTableRecord
void makePyDbTextStyleTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("TextStyleTableRecord");
    class_<PyDbTextStyleTableRecord, bases<PyDbSymbolTableRecord>>("TextStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9691)))
        .def("isShapeFile", &PyDbTextStyleTableRecord::isShapeFile, DS.ARGS(9698))
        .def("setIsShapeFile", &PyDbTextStyleTableRecord::setIsShapeFile, DS.ARGS({ "val : bool" }, 9706))
        .def("isVertical", &PyDbTextStyleTableRecord::isVertical, DS.ARGS(9699))
        .def("setIsVertical", &PyDbTextStyleTableRecord::setIsVertical, DS.ARGS({ "val : bool" }, 9707))
        .def("textSize", &PyDbTextStyleTableRecord::textSize, DS.ARGS(9713))
        .def("setTextSize", &PyDbTextStyleTableRecord::setTextSize, DS.ARGS({ "val : float" }, 9710))
        .def("xScale", &PyDbTextStyleTableRecord::xScale, DS.ARGS(9714))
        .def("setXScale", &PyDbTextStyleTableRecord::setXScale, DS.ARGS({ "val : float" }, 9711))
        .def("obliquingAngle", &PyDbTextStyleTableRecord::obliquingAngle, DS.ARGS(9700))
        .def("setObliquingAngle", &PyDbTextStyleTableRecord::setObliquingAngle, DS.ARGS({ "val : float" }, 9708))
        .def("flagBits", &PyDbTextStyleTableRecord::flagBits, DS.ARGS(9696))
        .def("setFlagBits", &PyDbTextStyleTableRecord::setFlagBits, DS.ARGS({ "flag: int" }, 9704))
        .def("priorSize", &PyDbTextStyleTableRecord::priorSize, DS.ARGS(9701))
        .def("setPriorSize", &PyDbTextStyleTableRecord::setPriorSize, DS.ARGS({ "val : int" }, 9709))
        .def("fileName", &PyDbTextStyleTableRecord::fileName, DS.ARGS(9695))
        .def("setFileName", &PyDbTextStyleTableRecord::setFileName, DS.ARGS({ "val : str" }, 9703))
        .def("bigFontFileName", &PyDbTextStyleTableRecord::bigFontFileName, DS.ARGS(9693))
        .def("setBigFontFileName", &PyDbTextStyleTableRecord::setBigFontFileName, DS.ARGS({ "val : str" }, 9702))
        .def("setFont", &PyDbTextStyleTableRecord::setFont, DS.ARGS({ "tFace: str","bold: bool","italic: bool","charset: int","pitch: int","family: int","allowMissing: bool" }, 9705))
        .def("font", &PyDbTextStyleTableRecord::font, DS.ARGS(9697))
        .def("className", &PyDbTextStyleTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTextStyleTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbTextStyleTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTextStyleTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbTextStyleTableRecord(), true)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(AcDbTextStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbTextStyleTableRecord>(id), false)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbTextStyleTableRecord>(id, mode), false)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbTextStyleTableRecord>(id, mode, erased), false)
{
}

Adesk::Boolean PyDbTextStyleTableRecord::isShapeFile() const
{
    return impObj()->isShapeFile();
}

void PyDbTextStyleTableRecord::setIsShapeFile(Adesk::Boolean shape) const
{
    return impObj()->setIsShapeFile(shape);
}

Adesk::Boolean PyDbTextStyleTableRecord::isVertical() const
{
    return impObj()->isVertical();
}

void PyDbTextStyleTableRecord::setIsVertical(Adesk::Boolean vertical) const
{
    return impObj()->setIsVertical(vertical);
}

double PyDbTextStyleTableRecord::textSize() const
{
    return impObj()->textSize();
}

void PyDbTextStyleTableRecord::setTextSize(double size) const
{
    return PyThrowBadEs(impObj()->setTextSize(size));
}

double PyDbTextStyleTableRecord::xScale() const
{
    return impObj()->xScale();
}

void PyDbTextStyleTableRecord::setXScale(double xScale) const
{
    return PyThrowBadEs(impObj()->setXScale(xScale));
}

double PyDbTextStyleTableRecord::obliquingAngle() const
{
    return impObj()->obliquingAngle();
}

void PyDbTextStyleTableRecord::setObliquingAngle(double obliquingAngle) const
{
    return PyThrowBadEs(impObj()->setObliquingAngle(obliquingAngle));
}

Adesk::UInt8 PyDbTextStyleTableRecord::flagBits() const
{
    return impObj()->flagBits();
}

void PyDbTextStyleTableRecord::setFlagBits(Adesk::UInt8 flagBits) const
{
    return impObj()->setFlagBits(flagBits);
}

double PyDbTextStyleTableRecord::priorSize() const
{
    return impObj()->priorSize();
}

void PyDbTextStyleTableRecord::setPriorSize(double priorSize) const
{
    return PyThrowBadEs(impObj()->setPriorSize(priorSize));
}

std::string PyDbTextStyleTableRecord::fileName() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr path;
    PyThrowBadEs(impObj()->fileName(path.buf));
    return wstr_to_utf8(path.buf);
#else
    AcString path;
    PyThrowBadEs(impObj()->fileName(path));
    return wstr_to_utf8(path);
#endif
}

void PyDbTextStyleTableRecord::setFileName(const std::string& path) const
{
    return PyThrowBadEs(impObj()->setFileName(utf8_to_wstr(path).c_str()));
}

std::string PyDbTextStyleTableRecord::bigFontFileName() const
{
    AcString path;
    PyThrowBadEs(impObj()->bigFontFileName(path));
    return wstr_to_utf8(path);
}

void PyDbTextStyleTableRecord::setBigFontFileName(const std::string& path) const
{
    return PyThrowBadEs(impObj()->setBigFontFileName(utf8_to_wstr(path).c_str()));
}

void PyDbTextStyleTableRecord::setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont) const
{
    return PyThrowBadEs(impObj()->setFont(
        utf8_to_wstr(pTypeface).c_str(),
        bold,
        italic,
        (Charset)charset,
        (Autodesk::AutoCAD::PAL::FontUtils::FontPitch)pitch,
        (Autodesk::AutoCAD::PAL::FontUtils::FontFamily)family, bAllowMissingFont));
}

boost::python::tuple PyDbTextStyleTableRecord::font() const
{
    PyAutoLockGIL lock;
    Adesk::Boolean bold = false;
    Adesk::Boolean italic = false;
    Charset charset = kAnsiCharset;
    AcString sTypeface;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch = Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family = Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare;
    PyThrowBadEs(impObj()->font(sTypeface, bold, italic, charset, pitch, family));
    std::string tf = wstr_to_utf8(sTypeface);
    return boost::python::make_tuple(tf, bold, italic, (int)charset, (int)pitch, (int)family);
}

std::string PyDbTextStyleTableRecord::className()
{
    return "AcDbTextStyleTableRecord";
}

PyRxClass PyDbTextStyleTableRecord::desc()
{
    return PyRxClass(AcDbTextStyleTableRecord::desc(), false);
}

PyDbTextStyleTableRecord PyDbTextStyleTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbTextStyleTableRecord, AcDbTextStyleTableRecord>(src);
}

PyDbTextStyleTableRecord PyDbTextStyleTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbTextStyleTableRecord>(src);
}

AcDbTextStyleTableRecord* PyDbTextStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbTextStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbUCSTableRecord
void makePyDbUCSTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("UCSTableRecord");
    class_<PyDbUCSTableRecord, bases<PyDbSymbolTableRecord>>("UCSTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9813)))
        .def("origin", &PyDbUCSTableRecord::origin, DS.ARGS(9815))
        .def("setOrigin", &PyDbUCSTableRecord::setOrigin, DS.ARGS({ "val : PyGe.Point3d" }, 9816))
        .def("xAxis", &PyDbUCSTableRecord::xAxis, DS.ARGS(9822))
        .def("setXAxis", &PyDbUCSTableRecord::setXAxis, DS.ARGS({ "val : PyGe.Vector3d" }, 9818))
        .def("yAxis", &PyDbUCSTableRecord::yAxis, DS.ARGS(9823))
        .def("setYAxis", &PyDbUCSTableRecord::setYAxis, DS.ARGS({ "val : PyGe.Vector3d" }, 9819))
        .def("ucsBaseOrigin", &PyDbUCSTableRecord::ucsBaseOrigin, DS.ARGS({ "view : PyDb.OrthographicView" }, 9821))
        .def("setUcsBaseOrigin", &PyDbUCSTableRecord::setUcsBaseOrigin, DS.ARGS({ "val : PyGe.Point3d","view : PyDb.OrthographicView" }, 9817))
        .def("className", &PyDbUCSTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUCSTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbUCSTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbUCSTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbUCSTableRecord::PyDbUCSTableRecord()
    : PyDbSymbolTableRecord(new AcDbUCSTableRecord(), true)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(AcDbUCSTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbUCSTableRecord>(id), false)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbUCSTableRecord>(id, mode), false)
{
}

PyDbUCSTableRecord::PyDbUCSTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbUCSTableRecord>(id, mode, erased), false)
{
}

AcGePoint3d PyDbUCSTableRecord::origin() const
{
    return impObj()->origin();
}

void PyDbUCSTableRecord::setOrigin(const AcGePoint3d& newOrigin) const
{
    return impObj()->setOrigin(newOrigin);
}

AcGeVector3d PyDbUCSTableRecord::xAxis() const
{
    return impObj()->xAxis();
}

void PyDbUCSTableRecord::setXAxis(const AcGeVector3d& xAxis) const
{
    return impObj()->setXAxis(xAxis);
}

AcGeVector3d PyDbUCSTableRecord::yAxis() const
{
    return impObj()->yAxis();
}

void PyDbUCSTableRecord::setYAxis(const AcGeVector3d& yAxis) const
{
    return impObj()->setXAxis(yAxis);
}

AcGePoint3d PyDbUCSTableRecord::ucsBaseOrigin(AcDb::OrthographicView view) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->ucsBaseOrigin(view);
#endif
}

void PyDbUCSTableRecord::setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUcsBaseOrigin(origin, view));
#endif
}

std::string PyDbUCSTableRecord::className()
{
    return "AcDbUCSTableRecord";
}

PyRxClass PyDbUCSTableRecord::desc()
{
    return PyRxClass(AcDbUCSTableRecord::desc(), false);
}

PyDbUCSTableRecord PyDbUCSTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbUCSTableRecord, AcDbUCSTableRecord>(src);
}

PyDbUCSTableRecord PyDbUCSTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbUCSTableRecord>(src);
}

AcDbUCSTableRecord* PyDbUCSTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbUCSTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbRegAppTableRecord
void makePyDbRegAppTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("RegAppTableRecord");
    class_<PyDbRegAppTableRecord, bases<PyDbSymbolTableRecord>>("RegAppTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 8145)))
        .def("className", &PyDbRegAppTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRegAppTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRegAppTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRegAppTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord()
    : PyDbSymbolTableRecord(new AcDbRegAppTableRecord(), true)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(AcDbRegAppTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbRegAppTableRecord>(id), false)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbRegAppTableRecord>(id, mode), false)
{
}

PyDbRegAppTableRecord::PyDbRegAppTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbRegAppTableRecord>(id, mode, erased), false)
{
}

std::string PyDbRegAppTableRecord::className()
{
    return "AcDbRegAppTableRecord";
}

PyRxClass PyDbRegAppTableRecord::desc()
{
    return PyRxClass(AcDbRegAppTableRecord::desc(), false);
}

PyDbRegAppTableRecord PyDbRegAppTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbRegAppTableRecord, AcDbRegAppTableRecord>(src);
}

PyDbRegAppTableRecord PyDbRegAppTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRegAppTableRecord>(src);
}

AcDbRegAppTableRecord* PyDbRegAppTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRegAppTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbLinetypeTableRecord
void makePyDbLinetypeTableRecordWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("LinetypeTableRecord");
    class_<PyDbLinetypeTableRecord, bases<PyDbSymbolTableRecord>>("LinetypeTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 6032)))
        .def("comments", &PyDbLinetypeTableRecord::comments, DS.ARGS())
        .def("setComments", &PyDbLinetypeTableRecord::setComments, DS.ARGS({ "val: str" }))
        .def("patternLength", &PyDbLinetypeTableRecord::patternLength, DS.ARGS())
        .def("setPatternLength", &PyDbLinetypeTableRecord::setPatternLength, DS.ARGS({ "val: float" }))
        .def("numDashes", &PyDbLinetypeTableRecord::numDashes, DS.ARGS())
        .def("setNumDashes", &PyDbLinetypeTableRecord::setNumDashes, DS.ARGS({ "val: int" }))
        .def("dashLengthAt", &PyDbLinetypeTableRecord::dashLengthAt, DS.ARGS({ "idx: int" }))
        .def("setDashLengthAt", &PyDbLinetypeTableRecord::setDashLengthAt, DS.ARGS({ "idx: int","val: float" }))
        .def("shapeStyleAt", &PyDbLinetypeTableRecord::shapeStyleAt, DS.ARGS({ "idx: int" }))
        .def("setShapeStyleAt", &PyDbLinetypeTableRecord::setShapeStyleAt, DS.ARGS({ "idx: int","id: PyDb.ObjectId" }))
        .def("shapeNumberAt", &PyDbLinetypeTableRecord::shapeNumberAt, DS.ARGS({ "idx: int" }))
        .def("setShapeNumberAt", &PyDbLinetypeTableRecord::setShapeNumberAt, DS.ARGS({ "idx: int","val: int" }))
        .def("shapeOffsetAt", &PyDbLinetypeTableRecord::shapeOffsetAt, DS.ARGS({ "idx: int" }))
        .def("setShapeOffsetAt", &PyDbLinetypeTableRecord::setShapeOffsetAt, DS.ARGS({ "idx: int","vec: PyGe.Vector2d" }))
        .def("shapeScaleAt", &PyDbLinetypeTableRecord::shapeScaleAt, DS.ARGS({ "idx: int" }))
        .def("setShapeScaleAt", &PyDbLinetypeTableRecord::setShapeScaleAt, DS.ARGS({ "idx: int","scale: float" }))
        .def("isScaledToFit", &PyDbLinetypeTableRecord::isScaledToFit, DS.ARGS())
        .def("setIsScaledToFit", &PyDbLinetypeTableRecord::setIsScaledToFit, DS.ARGS({ "val: bool" }))
        .def("shapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::shapeIsUcsOrientedAt, DS.ARGS({ "idx: int" }))
        .def("setShapeIsUcsOrientedAt", &PyDbLinetypeTableRecord::setShapeIsUcsOrientedAt, DS.ARGS({ "idx: int","isUcsOriented: bool" }))
        .def("shapeIsUprightAt", &PyDbLinetypeTableRecord::shapeIsUprightAt, DS.ARGS({ "idx: int" }))
        .def("setShapeIsUprightAt", &PyDbLinetypeTableRecord::setShapeIsUprightAt, DS.ARGS({ "idx: int","isUpright: bool" }))
        .def("shapeRotationAt", &PyDbLinetypeTableRecord::shapeRotationAt, DS.ARGS({ "idx: int" }))
        .def("setShapeRotationAt", &PyDbLinetypeTableRecord::setShapeRotationAt, DS.ARGS({ "idx: int","val: float" }))
        .def("textAt", &PyDbLinetypeTableRecord::textAt, DS.ARGS({ "idx: int" }))
        .def("setTextAt", &PyDbLinetypeTableRecord::setTextAt, DS.ARGS({ "idx: int","val: str" }))
        .def("className", &PyDbLinetypeTableRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLinetypeTableRecord::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLinetypeTableRecord::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLinetypeTableRecord::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord()
    : PyDbSymbolTableRecord(new AcDbLinetypeTableRecord(), true)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(AcDbLinetypeTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLinetypeTableRecord>(id), false)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLinetypeTableRecord>(id, mode), false)
{
}

PyDbLinetypeTableRecord::PyDbLinetypeTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTableRecord(openAcDbObject<AcDbLinetypeTableRecord>(id, mode, erased), false)
{
}

std::string PyDbLinetypeTableRecord::comments() const
{
    const wchar_t* val = nullptr;
    PyThrowBadEs(impObj()->comments(val));
    return wstr_to_utf8(val);
}

void PyDbLinetypeTableRecord::setComments(const std::string& pstring) const
{
    return PyThrowBadEs(impObj()->setComments(utf8_to_wstr(pstring).c_str()));
}

double PyDbLinetypeTableRecord::patternLength() const
{
    return impObj()->patternLength();
}

void PyDbLinetypeTableRecord::setPatternLength(double patternLength) const
{
    return PyThrowBadEs(impObj()->setPatternLength(patternLength));
}

int PyDbLinetypeTableRecord::numDashes() const
{
    return impObj()->numDashes();
}

void PyDbLinetypeTableRecord::setNumDashes(int count) const
{
    return PyThrowBadEs(impObj()->setNumDashes(count));
}

double PyDbLinetypeTableRecord::dashLengthAt(int index) const
{
    return impObj()->dashLengthAt(index);
}

void PyDbLinetypeTableRecord::setDashLengthAt(int index, double value) const
{
    return PyThrowBadEs(impObj()->setDashLengthAt(index, value));
}

PyDbObjectId PyDbLinetypeTableRecord::shapeStyleAt(int index) const
{
    return PyDbObjectId(impObj()->shapeStyleAt(index));
}

void PyDbLinetypeTableRecord::setShapeStyleAt(int index, PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setShapeStyleAt(index, id.m_id));
}

int PyDbLinetypeTableRecord::shapeNumberAt(int index) const
{
    return impObj()->shapeNumberAt(index);
}

void PyDbLinetypeTableRecord::setShapeNumberAt(int index, int shapeNumber) const
{
    return PyThrowBadEs(impObj()->setShapeNumberAt(index, shapeNumber));
}

AcGeVector2d PyDbLinetypeTableRecord::shapeOffsetAt(int index) const
{
    return impObj()->shapeOffsetAt(index);
}

void PyDbLinetypeTableRecord::setShapeOffsetAt(int index, const AcGeVector2d& offset) const
{
    return PyThrowBadEs(impObj()->setShapeOffsetAt(index, offset));
}

double PyDbLinetypeTableRecord::shapeScaleAt(int index) const
{
    return impObj()->shapeScaleAt(index);
}

void PyDbLinetypeTableRecord::setShapeScaleAt(int index, double scale) const
{
    return PyThrowBadEs(impObj()->setShapeScaleAt(index, scale));
}

bool PyDbLinetypeTableRecord::isScaledToFit() const
{
    return impObj()->isScaledToFit();
}

void PyDbLinetypeTableRecord::setIsScaledToFit(bool scaledToFit) const
{
    return impObj()->setIsScaledToFit(scaledToFit);
}

bool PyDbLinetypeTableRecord::shapeIsUcsOrientedAt(int index) const
{
    return impObj()->shapeIsUcsOrientedAt(index);
}

void PyDbLinetypeTableRecord::setShapeIsUcsOrientedAt(int index, bool isUcsOriented) const
{
    return PyThrowBadEs(impObj()->setShapeIsUcsOrientedAt(index, isUcsOriented));
}

bool PyDbLinetypeTableRecord::shapeIsUprightAt(int index) const
{
    return impObj()->shapeIsUprightAt(index);
}

void PyDbLinetypeTableRecord::setShapeIsUprightAt(int index, bool isUpright) const
{
    return PyThrowBadEs(impObj()->setShapeIsUprightAt(index, isUpright));
}

double PyDbLinetypeTableRecord::shapeRotationAt(int index) const
{
    return impObj()->shapeRotationAt(index);
}

void PyDbLinetypeTableRecord::setShapeRotationAt(int index, double rotation) const
{
    return PyThrowBadEs(impObj()->setShapeRotationAt(index, rotation));
}

std::string PyDbLinetypeTableRecord::textAt(int index) const
{
    const wchar_t* val = nullptr;
    PyThrowBadEs(impObj()->textAt(index, val));
    return wstr_to_utf8(val);
}

void PyDbLinetypeTableRecord::setTextAt(int index, const std::string& pstring) const
{
    return PyThrowBadEs(impObj()->setTextAt(index, utf8_to_wstr(pstring).c_str()));
}

std::string PyDbLinetypeTableRecord::className()
{
    return "AcDbLinetypeTableRecord";
}

PyRxClass PyDbLinetypeTableRecord::desc()
{
    return PyRxClass(AcDbLinetypeTableRecord::desc(), false);
}

PyDbLinetypeTableRecord PyDbLinetypeTableRecord::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLinetypeTableRecord, AcDbLinetypeTableRecord>(src);
}

PyDbLinetypeTableRecord PyDbLinetypeTableRecord::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLinetypeTableRecord>(src);
}

AcDbLinetypeTableRecord* PyDbLinetypeTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLinetypeTableRecord*>(m_pyImp.get());
}
