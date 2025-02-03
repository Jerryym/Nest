#pragma once
#include "NestUI.h"

namespace Example {

	class MainWindow : public NestUI::NestMainWindow
	{
	public:
		MainWindow(QWidget* parent = nullptr, const NestUI::sWindowProp& sProp = NestUI::sWindowProp());
		virtual ~MainWindow() {}

	public:
		/// @brief 获取窗口宽度
		virtual uint32_t GetWidth() const { return m_sProp.m_nWidth; }
		/// @brief 获取窗口高度
		virtual uint32_t GetHeight() const { return m_sProp.m_nHeight; }
		/// @brief 获取窗口标题
		virtual const QString& GetTitle() const override { return m_sProp.m_STitle; }

	private:
		void Initialize();
		SARibbonCategory* CreateCategory(const NestApp::RibbonPage& page);

		void CreateTestCategory(SARibbonBar* pRibbon);

	private:
		NestUI::sWindowProp m_sProp;
	};

}
