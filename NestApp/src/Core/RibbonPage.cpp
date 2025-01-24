#include "nestpch.h"
#include "RibbonPage.h"

namespace NestApp {

    RibbonPage::RibbonPage(const QString &SObjName, const QString &SPageName)
        : m_SName(SObjName), m_SPageName(SPageName)
    {
    }

	void RibbonPage::addAction(Action* pAction)
	{
		m_Actions.insert(pAction->getName(), pAction);
	}

	Action* RibbonPage::getAction(const QString& SName) const
	{
		return m_Actions.value(SName);
	}

}
