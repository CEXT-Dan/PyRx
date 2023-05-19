#pragma once
class RxEnvironment
{
public:
	RxEnvironment(std::filesystem::path modulePath, MSIHANDLE hInstall);
	std::wstring findPythonPath();
	std::wstring findWxPythonPath();
	std::wstring findStubPath();

	bool install();
	bool uninstall();
	static RxEnvironment& instance(std::filesystem::path modulePath, MSIHANDLE hInstall);

	std::filesystem::path modulePath;
	MSIHANDLE hInstall;
};

