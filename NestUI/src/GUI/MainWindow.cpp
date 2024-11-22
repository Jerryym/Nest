#include "nestuipch.h"
#include "MainWindow.h"

namespace NestUI {

	MainWindow::MainWindow(QWidget* parent, const sWindowProp& sProp)
		: SARibbonMainWindow(parent), m_sProp(sProp)
	{
		//初始化窗口大小
		resize(QSize(sProp.m_nWidth, sProp.m_nHeight));
		//设置窗口标题
		setWindowTitle(sProp.m_STitle);
	}

}
