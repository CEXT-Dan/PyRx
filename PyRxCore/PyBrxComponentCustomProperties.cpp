#include "stdafx.h"
#include "PyBrxComponentCustomProperties.h"

#ifdef BRXAPP

using namespace boost::python;
//---------------------------------------------------------------------
//PyBrxMechanicalPropertySet
void makePyBrxMechanicalPropertySet()
{
    constexpr const std::string_view createCategoryOverloads = "Overloads:\n"
        "- db: PyDb.Database, propertyName: str\n"
        "- db: PyDb.Database, propertyName: str, isPerInstance: bool\n"
        "- db: PyDb.Database, propertyName: str, isPerInstance: bool, label: str\n";

    PyDocString DS("PyBrx.MechanicalPropertySet");
    class_<PyBrxMechanicalPropertySet>("MechanicalPropertySet")
        .def(init<>(DS.ARGS()))
        .def("isNull", &PyBrxMechanicalPropertySet::isNull, DS.ARGS())
        .def("categoryName", &PyBrxMechanicalPropertySet::categoryName, DS.ARGS())
        .def("isPerInstance", &PyBrxMechanicalPropertySet::isPerInstance, DS.ARGS())
        .def("categoryLabel", &PyBrxMechanicalPropertySet::categoryLabel, DS.ARGS())
        .def("getAllCustomProperties", &PyBrxMechanicalPropertySet::getAllCustomProperties, DS.ARGS())
        .def("getPropertyByName", &PyBrxMechanicalPropertySet::getPropertyByName, DS.ARGS({ "propertyName : str" }))
        .def("addProperty", &PyBrxMechanicalPropertySet::addProperty1)
        .def("addProperty", &PyBrxMechanicalPropertySet::addProperty2, DS.ARGS({ "propertyName : str", "propertyType : PyBrx.MechanicalPropertyType","label: str=..." }))
        .def("getAllCategories", &PyBrxMechanicalPropertySet::getAllCategories, DS.SARGS({ "db : PyDb.Database" })).staticmethod("getAllCategories")
        .def("getCategoryByName", &PyBrxMechanicalPropertySet::getCategoryByName, DS.SARGS({ "db : PyDb.Database","propertyName : str" })).staticmethod("getAllCategories")
        .def("createCategory", &PyBrxMechanicalPropertySet::createCategory1)
        .def("createCategory", &PyBrxMechanicalPropertySet::createCategory2)
        .def("createCategory", &PyBrxMechanicalPropertySet::createCategory3, DS.SOVRL(createCategoryOverloads))
        .def("className", &PyBrxMechanicalPropertySet::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxMechanicalPropertySet::PyBrxMechanicalPropertySet(const BrxMechanicalPropertySet& other)
    : m_impl(other)
{
}

bool PyBrxMechanicalPropertySet::isNull() const
{
    return m_impl.isNull();
}

std::string PyBrxMechanicalPropertySet::categoryName() const
{
    return wstr_to_utf8(m_impl.categoryName());
}

bool PyBrxMechanicalPropertySet::isPerInstance() const
{
    return m_impl.isPerInstance();
}

std::string PyBrxMechanicalPropertySet::categoryLabel() const
{
    return wstr_to_utf8(m_impl.categoryLabel());
}

boost::python::list PyBrxMechanicalPropertySet::getAllCustomProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : m_impl.getAllCustomProperties())
        pylist.append(PyBrxMechanicalPropertyDefinition{ item });
    return pylist;
}

PyBrxMechanicalPropertyDefinition PyBrxMechanicalPropertySet::getPropertyByName(const std::string& propertyName) const
{
    return PyBrxMechanicalPropertyDefinition(m_impl.getPropertyByName(utf8_to_wstr(propertyName).c_str()));
}

PyBrxMechanicalPropertyDefinition PyBrxMechanicalPropertySet::addProperty1(const std::string& propertyName, BrxMechanicalPropertyType type)
{
    return PyBrxMechanicalPropertyDefinition(m_impl.addProperty(utf8_to_wstr(propertyName).c_str(), type));
}

PyBrxMechanicalPropertyDefinition PyBrxMechanicalPropertySet::addProperty2(const std::string& propertyName, BrxMechanicalPropertyType type, const std::string& label)
{
    return PyBrxMechanicalPropertyDefinition(m_impl.addProperty(utf8_to_wstr(propertyName).c_str(), type, utf8_to_wstr(label).c_str()));
}

boost::python::list PyBrxMechanicalPropertySet::getAllCategories(const PyDbDatabase& pDb)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const BrxMechanicalPropertySet& item : BrxMechanicalPropertySet::getAllCategories(pDb.impObj()))
        pylist.append(PyBrxMechanicalPropertySet{ item });
    return pylist;
}

PyBrxMechanicalPropertySet PyBrxMechanicalPropertySet::getCategoryByName(const PyDbDatabase& pDb, const std::string& categoryName)
{
    return PyBrxMechanicalPropertySet(BrxMechanicalPropertySet::getCategoryByName(pDb.impObj(), utf8_to_wstr(categoryName).c_str()));
}

PyBrxMechanicalPropertySet PyBrxMechanicalPropertySet::createCategory1(const PyDbDatabase& pDb, const std::string& categoryName)
{
    return PyBrxMechanicalPropertySet(BrxMechanicalPropertySet::createCategory(pDb.impObj(), utf8_to_wstr(categoryName).c_str()));
}

PyBrxMechanicalPropertySet PyBrxMechanicalPropertySet::createCategory2(const PyDbDatabase& pDb, const std::string& categoryName, bool isPerInstance)
{
    return PyBrxMechanicalPropertySet(BrxMechanicalPropertySet::createCategory(pDb.impObj(), utf8_to_wstr(categoryName).c_str(), isPerInstance));
}

PyBrxMechanicalPropertySet PyBrxMechanicalPropertySet::createCategory3(const PyDbDatabase& pDb, const std::string& categoryName, bool isPerInstance, const std::string& label)
{
    return PyBrxMechanicalPropertySet(BrxMechanicalPropertySet::createCategory(pDb.impObj(), utf8_to_wstr(categoryName).c_str(), isPerInstance, utf8_to_wstr(label).c_str()));
}

std::string PyBrxMechanicalPropertySet::className()
{
    return "BrxMechanicalPropertySet";
}

//---------------------------------------------------------------------
//PyBrxMechanicalPropertyDefinition
void makePyBrxMechanicalPropertyDefinition()
{
    PyDocString DS("PyBrx.MechanicalPropertyDefinition");
    class_<PyBrxMechanicalPropertyDefinition>("MechanicalPropertyDefinition")
        .def(init<>(DS.ARGS()))
        .def("isNull", &PyBrxMechanicalPropertyDefinition::isNull, DS.ARGS())
        .def("doesExist", &PyBrxMechanicalPropertyDefinition::doesExist, DS.ARGS())
        .def("name", &PyBrxMechanicalPropertyDefinition::name, DS.ARGS())
        .def("label", &PyBrxMechanicalPropertyDefinition::label, DS.ARGS())
        .def("type", &PyBrxMechanicalPropertyDefinition::type, DS.ARGS())
        .def("enumValues", &PyBrxMechanicalPropertyDefinition::enumValues, DS.ARGS())
        .def("setLabel", &PyBrxMechanicalPropertyDefinition::setLabel, DS.ARGS({ "newLabel:str" }))
        .def("setType", &PyBrxMechanicalPropertyDefinition::setType, DS.ARGS({ "newTypeName:PyBrx.MechanicalPropertyType" }))
        .def("setEnumValues", &PyBrxMechanicalPropertyDefinition::setEnumValues, DS.ARGS({ "aNewEnumValues:list[tuple[str,str]]" }))
        .def("className", &PyBrxMechanicalPropertyDefinition::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxMechanicalPropertyDefinition::PyBrxMechanicalPropertyDefinition(const BrxMechanicalPropertyDefinition& other)
    : m_impl(other)
{
}

bool PyBrxMechanicalPropertyDefinition::isNull() const
{
    return m_impl.isNull();
}

bool PyBrxMechanicalPropertyDefinition::doesExist() const
{
    return m_impl.doesExist();
}

std::string PyBrxMechanicalPropertyDefinition::name() const
{
    return wstr_to_utf8(m_impl.name());
}

std::string PyBrxMechanicalPropertyDefinition::label() const
{
    return wstr_to_utf8(m_impl.label());
}

BrxMechanicalPropertyType PyBrxMechanicalPropertyDefinition::type() const
{
    return m_impl.type();
}

boost::python::list PyBrxMechanicalPropertyDefinition::enumValues() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const BrxMechanicalPropertyEnum& item : m_impl.enumValues())
        pylist.append(boost::python::make_tuple(wstr_to_utf8(item.value), wstr_to_utf8(item.description)));
    return pylist;
}

void PyBrxMechanicalPropertyDefinition::setLabel(const std::string& newLabel)
{
    m_impl.setLabel(utf8_to_wstr(newLabel).c_str());
}

void PyBrxMechanicalPropertyDefinition::setType(BrxMechanicalPropertyType newTypeName)
{
    m_impl.setType(newTypeName);
}

void PyBrxMechanicalPropertyDefinition::setEnumValues(const boost::python::list& aNewEnumValues)
{
    PyAutoLockGIL lock;
    auto vec = py_list_to_std_vector<boost::python::object>(aNewEnumValues);
    BrxMechanicalPropertyEnums enums;
    for (auto& items : vec)
    {
        auto vitems = py_list_to_std_vector<std::string>(items);
        enums.append(BrxMechanicalPropertyEnum{ utf8_to_wstr(vitems.at(0)).c_str(), utf8_to_wstr(vitems.at(0)).c_str() });
    }
    m_impl.setEnumValues(enums);
}

std::string PyBrxMechanicalPropertyDefinition::className()
{
    return "BrxMechanicalPropertyDefinition";
}

#endif
