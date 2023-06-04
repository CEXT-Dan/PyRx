#pragma once

void makePyEdSelectionSetWrapper();

typedef std::array<int64_t, 2> PySSName;

struct PyEdSSDeleter
{
    inline void operator()(PySSName* ss) const
    {
        if (ss != nullptr)
        {
            if (ss->at(0) != 0 && ss->at(1) != 0)
                acedSSFree(ss->data());
            delete ss;
        }
    }
};

class PyEdSelectionSet
{
public:
    explicit PyEdSelectionSet(const ads_name& ss);
    ~PyEdSelectionSet() = default;
    bool			    isInitialized() const;
    size_t              size();
    void                clear();
    boost::python::list toList();

public:
    PySSName* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PySSName> m_pSet;
};

