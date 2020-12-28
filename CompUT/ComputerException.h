//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Pour les exception liee a CompUT </summary>
///
/// <classes> ComputerException </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <stdexcept>
using namespace std;
class ComputerException : public exception {
private:
	string info;
public:
	ComputerException(const string& i)  noexcept:info(i) {}
	virtual ~ComputerException() noexcept {};
	const char* what() const noexcept{ return info.c_str(); }
};
