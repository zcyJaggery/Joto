#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h> 

namespace Joto {
	class JOTO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define JT_CORE_TRACE(...)     ::Joto::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JT_CORE_INFO(...)      ::Joto::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JT_CORE_WARN(...)      ::Joto::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JT_CORE_ERROR(...)     ::Joto::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JT_CORE_FATAL(...)     ::Joto::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define JT_TRACE(...)          ::Joto::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JT_INFO(...)           ::Joto::Log::GetClientLogger()->info(__VA_ARGS__)
#define JT_WARN(...)           ::Joto::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JT_ERROR(...)          ::Joto::Log::GetClientLogger()->error(__VA_ARGS__)
#define JT_FATAL(...)          ::Joto::Log::GetClientLogger()->fatal(__VA_ARGS__)
