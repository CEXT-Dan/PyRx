#include "stdafx.h"
#include "PyRxAced.h"
#include "ol_errno.h"

const char* PyRxAced::GetStringDoc()
{
return "getstring([cronly] [, prompt])  ->  float or keyword\n\
\n\
Prompts the user for an string interactively and returns that string.\n\
The prompt argument is a string and is printed to the console.\n\
On R14 or earlier, the returned string is truncated to 132 characters.\n\
If the integer cronly argument exists and is nonzero, the string can\n\
contain spaces and the user must terminate it by entering <Return>.\n\
If cronly is emitted or zero, entering either a space or <Return>;\n\
terminates the string.\n\
\n\
If a call to initget() before the getreal() specified keywords,\n\
then one of those keywords can be returned. Flags to initget() are\n\
respected where appropriate.\n\
";
}

PyObject* PyRxAced::GetString(PyObject* self, PyObject* args)
{
    int status = 0;
    int cronly = 0;
    const char* inStr = nullptr;
    if (!PyArg_ParseTuple(args, "is", &cronly, &inStr))
        return NULL;
    AcString _result;
    status = acedGetString(cronly, utf8_to_wstr(inStr).c_str(), _result);
    return Py_BuildValue("s", wstr_to_utf8(_result).c_str());
}

const char* PyRxAced::GetVarDoc()
{
 return "getvar(varname)  ->  Value\n\
\n\
Get the value of an Autocad system variable (varname is a string).\n\
If the variable varname doesn't exist, or if the value can't be\n\
converted to a Python datatype, a ValueError exception is raised.\n\
";
}

PyObject* PyRxAced::GetVar(PyObject* self, PyObject* args)
{
	PyObject* outObj;
    struct resbuf rb;
	const char* varname = nullptr;
    char errstr[128]; /* keep error messages shorter than that */

    if (!PyArg_ParseTuple(args, "s:GetVar()", &varname))
        return NULL;

    if (RTNORM != acedGetVar(utf8_to_wstr(varname).c_str(), &rb)) {
        PyErr_SetString(PyExc_ValueError, "error in getvar()");
        return NULL;
    }

    switch (rb.restype) {
        case RTREAL:
            return Py_BuildValue("d", rb.resval.rreal);
        case RTSHORT:
            return Py_BuildValue("h", rb.resval.rint);
        case RTLONG:
            return Py_BuildValue("l", rb.resval.rlong);
        case RTPOINT: /* are those still in use? */
            return Py_BuildValue("dd", rb.resval.rpoint[X],  rb.resval.rpoint[Y]);
        case RT3DPOINT:
            return Py_BuildValue("ddd", rb.resval.rpoint[X],  rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
        case RTSTR:
            outObj = Py_BuildValue("s", rb.resval.rstring);
            free(rb.resval.rstring);
            return outObj;
        default:
            sprintf(errstr, "Unexpected result type %d from gevar()", rb.restype);
            PyErr_SetString(PyExc_ValueError, errstr);
            return NULL;
    }
}

const char* PyRxAced::SetVarDoc()
{
return "setvar(varname, value)\n\
\n\
Set the value of an Autocad system variable.\n\
\n\
If the variable varname doesn't exist, if the value can't\n\
be converted to an Autolisp datatype, if the value doesn't\n\
match the type or range of the variable or if the variable\n\
is read-only, a ValueError exception is raised.\n\
";
}

PyObject* PyRxAced::SetVar(PyObject* self, PyObject* args)
{
	char* varname;
	struct resbuf rb;

	//replace goto
	auto rberr = [&]()
	{
		acedGetVar(L"ERRNO", &rb);
		/* the bozos at autodesk couldn't supply an ads_strerror() */
		switch (rb.resval.rint)
		{
			case OL_ERDONLY:
				PyErr_SetString(PyExc_ValueError, "Attempt to set a read-only variable");
				break;
			case OL_ENONZERO:
				PyErr_SetString(PyExc_ValueError, "Zero value not allowed");
				break;
			case OL_ERANGE:
				PyErr_SetString(PyExc_ValueError, "Value out of range");
				break;
			default:
				PyErr_SetString(PyExc_ValueError, "Unexpected error in setvar()");
				break;
		}
	};

	/* XXX could we use pyacad_obj2resbuf() here? */
	/* XXX are there sysvars that hold enames or ssets?*/

	/* This needs to come before "sd",
	 *  because ints are also accepted there */
	if (!PyArg_ParseTuple(args, "sh", &varname, &(rb.resval.rint)))
	{
		PyErr_Clear();
	}
	else 
	{
		rb.restype = RTSHORT;
		if (RTNORM != acedSetVar(utf8_to_wstr(varname).c_str(), &rb)) 
			rberr;
		Py_INCREF(Py_None);
		return Py_None;
	}

	if (!PyArg_ParseTuple(args, "sd", &varname, &(rb.resval.rreal)))
	{
		PyErr_Clear();
	}
	else 
	{
		rb.restype = RTREAL;
		if (RTNORM != acedSetVar(utf8_to_wstr(varname).c_str(), &rb))
			rberr;
		Py_INCREF(Py_None);
		return Py_None;
	}

	/* can't use sequence2point here, since we don't just
	   ignore Z if not present, but build a true 2D RTPOINT */
	if (!PyArg_ParseTuple(args, "s(dd)", &varname, &(rb.resval.rpoint[X]), &(rb.resval.rpoint[Y])))
	{
		PyErr_Clear();
	}
	else 
	{
		rb.restype = RTPOINT;
		rb.resval.rpoint[3] = 0.0;
		if (RTNORM != acedSetVar(utf8_to_wstr(varname).c_str(), &rb))
			rberr;
		Py_INCREF(Py_None);
		return Py_None;
	}

	if (!PyArg_ParseTuple(args, "s(ddd)", &varname, &(rb.resval.rpoint[X]), &(rb.resval.rpoint[Y]), &(rb.resval.rpoint[Z])))
	{
		PyErr_Clear();
	}
	else 
	{
		rb.restype = RT3DPOINT;
		if (RTNORM != acedSetVar(utf8_to_wstr(varname).c_str(), &rb))
			rberr;
		Py_INCREF(Py_None);
		return Py_None;
	}

	if (!PyArg_ParseTuple(args, "sd", &varname, &(rb.resval.rstring)))
	{
		PyErr_Clear();
	}
	else 
	{
		rb.restype = RTSTR;
		/* rb lives on the heap, and won't get relrb-ed anywhere.
		   We can lend out the python string to autocad for a while. */
		if (RTNORM != acedSetVar(utf8_to_wstr(varname).c_str(), &rb))
			rberr;
		Py_INCREF(Py_None);
		return Py_None;
	}
	/* nothing matched */
	PyErr_SetString(PyExc_ValueError, "Invalid arguments for setvar()");
	return NULL;
}
