#include "nestpch.h"
#include "Application.h"

namespace NestApp {

	Application* Application::s_Instance = nullptr;

	Application::Application(int& argc, char** argv)
		: QApplication(argc, argv)
	{
		s_Instance = this;

		//初始化日志系统
		NestApp::Log::Init();
		NEST_CORE_WARN("Initialiazed Log!");
		NEST_CLIENT_INFO("Hello, Nest Framework!");
	}

	void Application::Run()
	{
		//启动主窗口
		m_Window.get()->show();
	}

	void Application::SetMainWindow(QMainWindow* mainWindow)
	{
		s_Instance->m_Window.reset(mainWindow);
	}

}
