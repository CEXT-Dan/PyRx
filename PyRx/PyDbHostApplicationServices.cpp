#include "stdafx.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbDatabase.h"
#include "PyDbLayout.h"

using namespace boost::python;

void makeAcDbHostApplicationServicesWrapper()
{
    class_<PyDbHostApplicationServices, boost::noncopyable>("HostApplicationServices")
        .def(init<>())
        .def("workingDatabase", &PyDbHostApplicationServices::workingDatabase)
        .def("setWorkingDatabase", &PyDbHostApplicationServices::setWorkingDatabase)
        .def("findFile", &PyDbHostApplicationServices::findFile1)
        .def("findFile", &PyDbHostApplicationServices::findFile2)
        .def("findFile", &PyDbHostApplicationServices::findFile3)
        .def("product", &PyDbHostApplicationServices::product)
        .def("LayoutManager", &PyDbHostApplicationServices::dbLayoutManager)
        ;

    enum_<AcDbHostApplicationServices::FindFileHint>("FindFileHint")
        .value("kDefault", AcDbHostApplicationServices::FindFileHint::kDefault)
        .value("kFontFile", AcDbHostApplicationServices::FindFileHint::kFontFile)
        .value("kCompiledShapeFile", AcDbHostApplicationServices::FindFileHint::kCompiledShapeFile)
        .value("kTrueTypeFontFile", AcDbHostApplicationServices::FindFileHint::kTrueTypeFontFile)
        .value("kEmbeddedImageFile", AcDbHostApplicationServices::FindFileHint::kEmbeddedImageFile)
        .value("kXRefDrawing", AcDbHostApplicationServices::FindFileHint::kXRefDrawing)
        .value("kPatternFile", AcDbHostApplicationServices::FindFileHint::kPatternFile)
        .value("kARXApplication", AcDbHostApplicationServices::FindFileHint::kARXApplication)
        .value("kFontMapFile", AcDbHostApplicationServices::FindFileHint::kFontMapFile)
        .value("kUnderlayFile", AcDbHostApplicationServices::FindFileHint::kUnderlayFile)
        .value("kDataLinkFile", AcDbHostApplicationServices::FindFileHint::kDataLinkFile)
        .value("kPhotometricWebFile", AcDbHostApplicationServices::FindFileHint::kPhotometricWebFile)
        .value("kMaterialMapFile", AcDbHostApplicationServices::FindFileHint::kMaterialMapFile)
        .value("kCloudOrProjectFile", AcDbHostApplicationServices::FindFileHint::kCloudOrProjectFile)
        .export_values()
        ;

    enum_<AcDbHostApplicationServices::RemapFileContext>("RemapFileContext")
        .value("kDrawingOpen", AcDbHostApplicationServices::RemapFileContext::kDrawingOpen)
        .value("kXrefResolution", AcDbHostApplicationServices::RemapFileContext::kXrefResolution)
        .value("kRasterResolution", AcDbHostApplicationServices::RemapFileContext::kRasterResolution)
        .value("kAfterXrefResolution", AcDbHostApplicationServices::RemapFileContext::kAfterXrefResolution)
        .export_values()
        ;
}

PyDbDatabase PyDbHostApplicationServices::workingDatabase() const
{
    return PyDbDatabase(pDbHostApp->workingDatabase());
}

void PyDbHostApplicationServices::setWorkingDatabase(PyDbDatabase& pDatabase)
{
    pDbHostApp->setWorkingDatabase(pDatabase.impObj());
}

std::string PyDbHostApplicationServices::findFile1(const std::string& fileName)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile2(const std::string& fileName, const PyDbDatabase& db)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile3(const std::string& fileName, const PyDbDatabase& db, AcDbHostApplicationServices::FindFileHint hint)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj(), hint); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::product() const
{
    return  wstr_to_utf8(pDbHostApp->product());
}

PyDbLayoutManager PyDbHostApplicationServices::dbLayoutManager()
{
    return PyDbLayoutManager(pDbHostApp->layoutManager(), false);
}
