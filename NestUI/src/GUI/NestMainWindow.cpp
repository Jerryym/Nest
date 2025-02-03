#include "nestuipch.h"
#include "NestMainWindow.h"

namespace NestUI {

    NestMainWindow::NestMainWindow(QWidget* parent)
		: SARibbonMainWindow(parent)
    {
    }

    SARibbonCategory *NestMainWindow::CreateCategory(const NestApp::RibbonPage &page)
    {
        SARibbonCategory* pCategory = new SARibbonCategory;
        pCategory->setCategoryName(page.getPageName());
        pCategory->setObjectName(page.getName());
        return pCategory;
    }
}
