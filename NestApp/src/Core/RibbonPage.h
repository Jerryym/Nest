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
		QHash<QString, Action*> getActions() const { return m_Actions; }

		/// @brief 添加按钮
		/// @param pAction 
		void addAction(Action* pAction);
		/// @brief 获取按钮
		/// @param SName 
		/// @return 
		Action* getAction(const QString& SName) const;

    private:
        /// @brief 标签页名称(对应界面控件的name属性)
        QString m_SName;
        /// @brief 标签页名称
        QString m_SPageName;
		/// @brief 标签页中的所有按钮
		QHash<QString, Action*> m_Actions;
    };

}
