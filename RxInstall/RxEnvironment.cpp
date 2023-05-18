#include "pch.h"
#include "RxEnvironment.h"

std::string RxEnvironment::findPythonPath()
{
	std::string res;
	std::string env = std::getenv("PATH");
	std::vector<std::string> paths;
	splitA(env, ';', paths);
	for (auto& item : paths)
	{
		if (item.ends_with("python310\\") || item.ends_with("python310/") || item.ends_with("python310"))
			res = item;
	}
	return res;
}

std::string RxEnvironment::findWxPythonPath()
{
	std::string res;
	std::string env = std::getenv("PATH");
	std::vector<std::string> paths;
	splitA(env, ';', paths);
	for (auto& item : paths)
	{
		if (item.find("site-packages") != std::string::npos)
		{
			if (item.ends_with("wx\\") || item.ends_with("wx/") || item.ends_with("wx"))
				res = item;
		}
	}
	return res;
}

std::string RxEnvironment::findStubPath()
{
	std::string res;
	return res;
}

bool RxEnvironment::install()
{
	MessageBoxA(NULL, "install", "OK", MB_OK);
	std::string pyPath = findPythonPath();
	if (pyPath.size() == 0)
	{
		MessageBoxA(NULL, "FAIL @ findPythonPath", "FAIL", MB_OK);
		return false;
	}

	std::string wxPath= findWxPythonPath();
	if (wxPath.size() != 0)
	{
		MessageBoxA(NULL, "findWxPythonPath found", "OK", MB_OK);
		return true;
	}

	rtrim(pyPath, '/');
	rtrim(pyPath, '\\');

	std::stringstream ss;
	ss << std::getenv("PATH");;
	ss << ";" << pyPath + "\\Lib\\site-packages\\wx";
	ss << '\0';
	std::string env = ss.str();

	auto e = _putenv_s("PATH", env.c_str());

	if (e)
	{
		MessageBoxA(NULL, "FAIL", "FAIL", MB_OK);
		return false;
	}

	std::string wxPathCheck = findWxPythonPath();
	if (wxPathCheck.size() != 0)
	{
		MessageBoxA(NULL, wxPathCheck.c_str(), "YAY", MB_OK);
		return true;
	}
	else
	{
		MessageBoxA(NULL, "FAIL @ check", "FAIL", MB_OK);
	}

	return false;
}

RxEnvironment& RxEnvironment::instance()
{
	static RxEnvironment mthis;
	return mthis;
}
