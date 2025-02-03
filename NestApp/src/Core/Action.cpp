#include "nestpch.h"
#include "Action.h"

namespace NestApp {

	Action::Action(ActionSize Size, const QString& SObjName, const QString& SLabel, const QString& SPageName, const QString& SDescription, const QString& SIconUrl, const QString& SShortCut)
		: m_enSize(Size), m_SName(SObjName), m_SLabel(SLabel), m_SPageName(SPageName), m_SDescription(SDescription), m_SIconUrl(SIconUrl), m_SShortCut(SShortCut)
	{
	}

	void Action::Invoke(const QVariantMap& params)
	{
		
	}

}
