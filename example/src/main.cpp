#include "NestApp.h"
#include "NestUI.h"
#include <iostream>

int main(int argc, char* argv[])
{
	NestApp::Application app(argc, argv);

	NestUI::MainWindow* pMainWindow = new NestUI::MainWindow;
	app.SetMainWindow(pMainWindow);
	app.Run();

	return app.exec();
}
