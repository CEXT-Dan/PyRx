#pragma once
class RxEnvironment
{
public:

	std::string findPythonPath();
	std::string findWxPythonPath();
	std::string findStubPath();

	bool install();
	static RxEnvironment& instance();
};

