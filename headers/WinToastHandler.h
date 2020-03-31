#ifndef _WINTOASTHANDLER_H

#define _WINTOASTHANDLER_H

#include "wintoastlib.h"

using namespace WinToastLib;

class WinToastHandler: public IWinToastHandler{

	public:
		WinToastHandler(){};
		void toastActivated() const override{};
		void toastActivated(int index) const override{};
		void toastDismissed(WinToastDismissalReason state) const override{};
		void toastFailed() const override{};

};

#endif