#include "MainWindow.h"

namespace Example {

	MainWindow::MainWindow(QWidget* parent, const NestUI::sWindowProp& sProp)
		: NestUI::NestMainWindow(parent), m_sProp(sProp)
	{
		//设置窗口标题
		setWindowTitle(sProp.m_STitle);
		//初始化窗口大小
		resize(QSize(sProp.m_nWidth, sProp.m_nHeight));
		showMaximized();

		Initialize();
	}

	void MainWindow::Initialize()
	{
		SARibbonBar* pRibbon = ribbonBar();
		pRibbon->setContentsMargins(5, 0, 5, 0);

		//创建测试标签页
		CreateTestCategory(pRibbon);
	}

	SARibbonCategory* MainWindow::CreateCategory(const NestApp::RibbonPage& page)
	{
		//创建标签页
		SARibbonCategory* pCategory = new SARibbonCategory;
		pCategory->setCategoryName(page.getPageName());
		pCategory->setObjectName(page.getName());

		//创建Pannel
		SARibbonPannel* pPannel = pCategory->addPannel(page.getPageName());

		//添加Action
		QHash<QString, NestApp::Action*> actions = page.getActions();
		for (const auto &key : actions.keys())
		{
			QAction *pAction = new QAction(this);
			pAction->setText(actions[key]->getLabel());
			pAction->setObjectName(actions[key]->getName());
			if (actions[key]->getIconUrl().isEmpty() != true)
			{
				pAction->setIcon(QIcon(actions[key]->getIconUrl()));
			}
			if (actions[key]->getShortCut().isEmpty() != true)
			{
				pAction->setShortcut(QKeySequence(actions[key]->getShortCut()));
			}
			switch (actions[key]->getSize())
			{
			case NestApp::ActionSize::Small:
				pPannel->addSmallAction(pAction);
				break;
			case NestApp::ActionSize::Normal:
				pPannel->addMediumAction(pAction);
				break;
			case NestApp::ActionSize::Large:
				pPannel->addLargeAction(pAction);
				break;
			}
		}
		return pCategory;
	}

	void MainWindow::CreateTestCategory(SARibbonBar* pRibbon)
	{
		NestApp::RibbonPage page("TestPage", "测试");
		page.addAction(new NestApp::Action(NestApp::ActionSize::Large, "TestAction", "测试", "TestPage", "测试"));
		SARibbonCategory* pCategory = CreateCategory(page);
		pRibbon->addCategoryPage(pCategory);
	}

}
