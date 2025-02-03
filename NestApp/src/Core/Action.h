#pragma once
#include "Core.h"

namespace NestApp {

	/// @brief 按钮大小
	enum class ActionSize
	{
		Small,  //小按钮
        Normal, //正常按钮
        Large,  //大按钮
	};

	/// @brief SARibbon中的按钮类
	class NESTAPP_API Action : public QObject
	{
		Q_OBJECT
	public:
		Action(ActionSize Size, const QString& SObjName, const QString& SLabel, const QString& SPageName, const QString& SDescription, const QString& SIconUrl = "", const QString& SShortCut = "");
		~Action() = default;

	public:
		/// @brief 获取按钮大小
		/// @return 
		ActionSize getSize() const { return m_enSize; }
		/// @brief 获取按钮名称
		/// @return 
		QString getName() const { return m_SName; }
		/// @brief 获取按钮标签
		/// @return 
		QString getLabel() const { return m_SLabel; }
		/// @brief 获取按钮所属页面名
		/// @return 
		QString getPageName() const { return m_SPageName; }
		/// @brief 获取按钮图标
		/// @return 
		QString getIconUrl() const { return m_SIconUrl; }
		/// @brief 获取按钮快捷键
		/// @return 
		QString getShortCut() const { return m_SShortCut; }

	public slots:
		void Invoke(const QVariantMap& params = QVariantMap());

	private:
		/// @brief 按钮大小
		ActionSize m_enSize;
		/// @brief 按钮名称(对应界面控件的name属性)
		QString m_SName;
		/// @brief 按钮标签
		QString m_SLabel;
		/// @brief 所属Ribbon页面名
		QString m_SPageName;
		/// @brief 按钮描述
		QString m_SDescription;
		/// @brief 按钮图标
		QString m_SIconUrl;
		/// @brief 按钮快捷键
		QString m_SShortCut;
	};

}
