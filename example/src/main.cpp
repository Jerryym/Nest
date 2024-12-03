#include "NestApp.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	NestApp::Application app(argc, argv);

	Example::MainWindow* pMainWindow = new Example::MainWindow;
	app.SetMainWindow(pMainWindow);
	app.Run();

	return app.exec();
}
