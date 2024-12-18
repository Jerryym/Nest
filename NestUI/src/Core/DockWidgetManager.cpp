#include "nestuipch.h"
#include "DockWidgetManager.h"

namespace NestUI {

	DockWidgetManager* DockWidgetManager::s_Instance = nullptr;

	DockWidgetManager::DockWidgetManager(QMainWindow* mainWindow)
	{
		m_mainWindow = mainWindow;
	}

	DockWidgetManager::~DockWidgetManager()
	{
		m_mainWindow = nullptr;
	}

	DockWidgetManager* DockWidgetManager::GetDockManager(QMainWindow* mainWindow)
	{
		// FIXED: 在此处插入 return 语句
		if (s_Instance == nullptr)
		{
			s_Instance = new DockWidgetManager(mainWindow);
		}
		return s_Instance;
	}

	void DockWidgetManager::AddDockWidget(const QString& STitle, QDockWidget* dockWidget, Qt::DockWidgetArea area)
	{
		m_DockWidgetMap.insert(STitle, dockWidget);
		m_mainWindow->addDockWidget(area, dockWidget);
	}

	QDockWidget* DockWidgetManager::GetDockWidget(const QString& STitle)
	{
		if (m_DockWidgetMap.contains(STitle) == true)
		{
			return m_DockWidgetMap[STitle];
		}
		return nullptr;
	}

	void DockWidgetManager::RemoveDockWidget(const QString& STitle)
	{
		if (m_DockWidgetMap.contains(STitle) == true)
		{
			m_mainWindow->removeDockWidget(m_DockWidgetMap[STitle]);
			m_DockWidgetMap.remove(STitle);
		}
	}
}
