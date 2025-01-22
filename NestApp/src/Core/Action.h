#pragma once
#include "Core.h"

namespace NestApp {

	/// @brief SARibbon中的按钮类
	class NESTAPP_API Action : public QObject
	{
		Q_OBJECT
	public:
		Action(const QString& SObjName, const QString& SLabel, const QString& SPageName, const QString& SDescription, const QString& SIconUrl);
		~Action() = default;

	public:
		/// @brief 获取按钮名称
		/// @return 
		QString getName() const { return m_SName; }
		/// @brief 获取按钮标签
		/// @return 
		QString getLabel() const { return m_SLabel; }
		/// @brief 获取按钮所属页面名
		/// @return 
		QString getPageName() const { return m_SPageName; }

	public slots:
		void Invoke(const QVariantMap& params = QVariantMap());

	private:
		/// @brief 按钮名称(对应界面控件的name属性)
		QString m_SName;
		/// @brief 按钮标签
		QString m_SLabel;
		/// @brief 所属页面名
		QString m_SPageName;
		/// @brief 按钮描述
		QString m_SDescription;
		/// @brief 按钮图标
		QString m_SIconUrl;
	};

}
