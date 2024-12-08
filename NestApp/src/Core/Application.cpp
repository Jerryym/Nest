#include "nestpch.h"
#include "Application.h"

namespace NestApp {

	Application* Application::s_Instance = nullptr;

	Application::Application(int& argc, char** argv)
		: QApplication(argc, argv)
	{
		s_Instance = this;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		//启动主窗口
		m_Window->show();
	}

	void Application::SetMainWindow(QMainWindow* mainWindow)
	{
		s_Instance->m_Window.reset(mainWindow);
	}

}
