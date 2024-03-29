#pragma once
class RxEnvironment
{
public:
	RxEnvironment(std::filesystem::path modulePath, MSIHANDLE hInstall);
	std::wstring findPythonPathPath();
	std::wstring findPythonPath();
	std::wstring findWxPythonPath();
	std::wstring findStubPath();
	std::wstring installDir();
	DWORD calcBufferSize(const std::wstring& str);
	void appendPath(std::wstring& src, const std::wstring& pathToAppend);
	void flushEnvironment();

	bool install();
	bool uninstall();
	static RxEnvironment& instance(std::filesystem::path modulePath, MSIHANDLE hInstall);

	std::filesystem::path modulePath;
	MSIHANDLE hInstall;
};

