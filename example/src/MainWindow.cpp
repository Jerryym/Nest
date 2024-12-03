#include "MainWindow.h"

namespace Example {

	MainWindow::MainWindow(QWidget* parent, const NestUI::sWindowProp& sProp)
		: NestUI::NestMainWindow(parent), m_sProp(sProp)
	{
		//设置窗口标题
		setWindowTitle(sProp.m_STitle);
		//初始化窗口大小
		resize(QSize(sProp.m_nWidth, sProp.m_nHeight));
	}

}
