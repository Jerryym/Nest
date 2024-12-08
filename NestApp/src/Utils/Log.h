#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/qt_sinks.h"

namespace NestApp {

	/// @brief 日志
	class NESTAPP_API Log
	{
	public:
		/// @brief 初始化日志系统(Log to Console)
		static void Init();
		/// @brief 初始化日志系统(Log to Qt)
		/// @param pTextEdit 
		/// @param iMaxLines 日志最大行数
		static void Init(QTextEdit* pTextEdit, int iMaxLines = 500);

	public:
		/// @brief 获取框架日志
		/// @return 
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		/// @brief 获取客户端日志
		/// @return 
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		// 框架日志对象(智能指针)
		static std::shared_ptr<spdlog::logger> s_ClientLogger;		// 客户端日志对象(智能指针)
	};

}

// Core log macros
#define NEST_CORE_TRACE(...)		::NestApp::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NEST_CORE_INFO(...)			::NestApp::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NEST_CORE_WARN(...)			::NestApp::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NEST_CORE_ERROR(...)		::NestApp::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NEST_CORE_CRITICAL(...)		::NestApp::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NEST_CLIENT_TRACE(...)		::NestApp::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NEST_CLIENT_INFO(...)		::NestApp::Log::GetClientLogger()->info(__VA_ARGS__)
#define NEST_CLIENT_WARN(...)		::NestApp::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NEST_CLIENT_ERROR(...)		::NestApp::Log::GetClientLogger()->error(__VA_ARGS__)
#define NEST_CLIENT_CRITICAL(...)	::NestApp::Log::GetClientLogger()->critical(__VA_ARGS__)
