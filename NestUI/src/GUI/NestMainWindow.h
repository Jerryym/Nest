#pragma once
#include <NestApp.h>

#include "Base.h"
#include "SARibbonMainWindow.h"
#include "SARibbonCategory.h"

namespace NestUI {

	/// @brief 窗口属性
	typedef struct NESTUI_API sWindowProp
	{
		uint32_t m_nWidth;		//窗口宽
		uint32_t m_nHeight;		//窗口高
		QString m_STitle;		//窗口标题

		sWindowProp(uint32_t width = 1600, uint32_t height = 900, const QString& title = "Nest")
			: m_nWidth(width), m_nHeight(height), m_STitle(title)
		{}
	}sWindowProp;

	/// @brief 窗口基类
	class NESTUI_API NestMainWindow : public SARibbonMainWindow
	{
		Q_OBJECT
	public:
		NestMainWindow(QWidget* parent = nullptr);
		virtual ~NestMainWindow() {}

	public:
		/// @brief 获取窗口宽度
		virtual uint32_t GetWidth() const = 0;
		/// @brief 获取窗口高度
		virtual uint32_t GetHeight() const = 0;
		/// @brief 获取窗口标题
		virtual const QString& GetTitle() const = 0;

	protected:
		/// @brief 创建ribbon页
		/// @param page ribbon页
		/// @return ribbon标签页控件指针 
		SARibbonCategory* CreateCategory(const NestApp::RibbonPage& page);
	};

}


