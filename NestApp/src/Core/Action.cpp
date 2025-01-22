#include "nestpch.h"
#include "Action.h"

namespace NestApp {

    Action::Action(const QString &SObjName, const QString &SLabel, const QString &SPageName, const QString &SDescription, const QString &SIconUrl)
        : m_SName(SObjName), m_SLabel(SLabel), m_SPageName(SPageName), m_SDescription(SDescription), m_SIconUrl(SIconUrl)
    {
    }

}
