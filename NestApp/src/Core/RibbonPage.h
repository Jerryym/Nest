#pragma once
#include "Core.h"
#include "Action.h"

namespace NestApp {

    /// @brief Ribbon标签页
    class NESTAPP_API RibbonPage
    {
    public:
        RibbonPage(const QString& SObjName, const QString& SPageName);
        ~RibbonPage() = default;

    public:
        QString getName() const { return m_SName; }
        QString getPageName() const { return m_SPageName; }

    private:
        /// @brief 标签页名称(对应界面控件的name属性)
        QString m_SName;
        /// @brief 标签页名称
        QString m_SPageName;
    };

}