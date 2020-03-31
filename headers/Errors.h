#ifndef _ERRORS_H

#define _ERRORS_H

#include <string>

namespace ErrorCaptions{

	const std::wstring NotCompatible = L"Your system in not supported!";
	const std::wstring NotInitialized = L"Could not initialize the lib. Error number: ";
	const std::wstring NotLaunched = L"Could not launch your toast notification. Error number: ";

};

#endif