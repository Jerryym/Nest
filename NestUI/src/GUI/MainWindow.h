#pragma once
#include "Base.h"
#include "SARibbon.h"

namespace NestUI {

	/// @brief 窗口属性
	typedef struct NESTUI_API sWindowProp
	{
		unsigned int m_nWidth;		//窗口宽
		unsigned int m_nHeight;		//窗口高
		QString m_STitle;			//窗口标题

		sWindowProp(unsigned int width = 1600, unsigned int height = 900,
			const QString& title = "Nest")
			: m_nWidth(width), m_nHeight(height), m_STitle(title)
		{}
	}sWindowProp;

	/// @brief 主窗口
	class NESTUI_API MainWindow : public SARibbonMainWindow
	{
		Q_OBJECT
	public:
		MainWindow(QWidget* parent = nullptr, const sWindowProp& sProp = sWindowProp());
		virtual ~MainWindow() {}

	public:
		/// @brief 获取主窗口宽度
		/// @return 
		unsigned int GetWidth() const { return m_sProp.m_nWidth; }
		/// @brief 获取主窗口高度
		/// @return 
		unsigned int GetHeigth() const { return m_sProp.m_nHeight; }
		/// @brief 获取主窗口标题名
		/// @return 
		QString GetTitle() const { return m_sProp.m_STitle; }

	private:
		/// @brief 主窗口属性
		sWindowProp m_sProp;
	};

}


