// Include headers
#include "wintoastlib.h"
#include "WinToastHandler.h"
#include "Configuration.h"
#include "Errors.h"

// Define type of application
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {

	WinToastTemplate toast;
	WinToast::WinToastError error;
	WinToastHandler* handler;
	std::vector<std::wstring> actions;
	std::wstring aumi;
	int launched;
	bool not_compatible, succedded;

	// Check if compatible
	not_compatible = (!WinToast::isCompatible());
	if (not_compatible)
		std::wcout << ErrorCaptions::NotCompatible << std::endl;

	// Init the library
	WinToast::instance()->setAppName(Configuration::ApplicationDetails::ProductName);
	aumi = WinToast::configureAUMI(Configuration::ApplicationDetails::CompanyName, Configuration::ApplicationDetails::ProductName, Configuration::ApplicationDetails::SubProductName, Configuration::ApplicationDetails::VersionNumber);
	WinToast::instance()->setAppUserModelId(aumi);
	succedded = WinToast::instance()->initialize(&error);
	if (!succedded)
		std::wcout << ErrorCaptions::NotInitialized<< error << std::endl;

	// Init the toast
	toast = WinToastTemplate(WinToastTemplate::ImageAndText04);
	toast.setTextField(Configuration::Toast::Texts::FirstLine, WinToastTemplate::FirstLine);
	toast.setTextField(Configuration::Toast::Texts::SecondLine, WinToastTemplate::SecondLine);
	toast.setAudioOption(WinToastTemplate::Silent);
	toast.setImagePath(Configuration::Toast::Image::Path);
	toast.setDuration(WinToastTemplate::Duration::Short);

	// Add actions
	actions.push_back(Configuration::Toast::ButtonCaptions::Accept);
	for (auto const& action : actions)
		toast.addAction(action);

	// Create handler
	handler = new WinToastHandler();

	// Sleep before showing the notification for the first time
	Sleep(Configuration::Toast::Times::MilisecondsSleepOnStartup);

	// Show toast
	launched = WinToast::instance()->showToast(toast, handler, &error);
	if (!launched)
		std::wcout << ErrorCaptions::NotLaunched << error << std::endl;

	// Sleep before closing the notification
	Sleep(Configuration::Toast::Times::MilisecondsSleepUntilExit);

	// Close and delete notification
	bool result = WinToast::instance()->hideToast(launched);
	WinToast::instance()->clear();

	// Exit program
	return 0;

}