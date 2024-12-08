#include <NestApp.h>
#include "SARibbonBar.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	SARibbonBar::initHighDpi();

	NestApp::Application app(argc, argv);
	//初始化日志系统
	NestApp::Log::Init();
	NEST_CORE_WARN("Initialiazed Log!");
	NEST_CLIENT_INFO("Hello, Nest Framework!");
	
	//创建主窗口
	Example::MainWindow* pMainWindow = new Example::MainWindow;
	app.SetMainWindow(pMainWindow);
	app.Run();

	return app.exec();
}
