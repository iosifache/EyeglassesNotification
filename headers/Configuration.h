#ifndef _CONFIGURATION_H

#define _CONFIGURATION_H

#include <string>
#include "Macros.h"

namespace Configuration{

	namespace ApplicationDetails{

		std::wstring CompanyName = L"";
		std::wstring ProductName = L"EyeglassesNotification";
		std::wstring SubProductName = L"";
		std::wstring VersionNumber = L"";

	}
	
	namespace Toast{

		namespace Image{

			// #error "The path to the image must be setted (std::wstring Path = L"") and this line removed"

		}

		namespace Texts {

			std::wstring FirstLine = L"The same annoying question..";
			std::wstring SecondLine = L"Did you put on your protection eyeglasses?";

		}

		namespace ButtonCaptions{
		
			std::wstring Accept = L"Sir, yes, sir!";

		}

		namespace Times{

			int MilisecondsSleepOnStartup = SECONDS_TO_MILISECONDS(0);
			int MilisecondsSleepUntilExit = SECONDS_TO_MILISECONDS(30);

		}
		
	}
	
}

#endif