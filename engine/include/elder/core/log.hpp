#pragma once

#include "elder/eepch.hpp"
#include "spdlog/spdlog.h"

namespace Elder {

    enum class EE_API LogLevel : int {
        TRACE = SPDLOG_LEVEL_TRACE,
        DEBUG = SPDLOG_LEVEL_DEBUG,
        INFO  = SPDLOG_LEVEL_INFO,
        WARN  = SPDLOG_LEVEL_WARN,
        ERROR = SPDLOG_LEVEL_ERROR,
        FATAL = SPDLOG_LEVEL_CRITICAL,
        OFF   = SPDLOG_LEVEL_OFF
    };

    void EE_API                   InitLog(const LogLevel& tLogLevel);

    Shared<spdlog::logger> EE_API GetCoreLogger() noexcept;
    Shared<spdlog::logger> EE_API GetClientLogger() noexcept;

} // namespace Elder

#ifdef NDEBUG
#define EE_CORE_TRACE(...)
#define EE_CORE_DEBUG(...)
#define EE_CLIENT_TRACE(...)
#define EE_CLIENT_DEBUG(...)

#else
#define EE_CORE_TRACE(...)   Elder::GetCoreLogger()->trace(__VA_ARGS__)
#define EE_CORE_DEBUG(...)   Elder::GetCoreLogger()->debug(__VA_ARGS__)
#define EE_CLIENT_TRACE(...) Elder::GetClientLogger()->trace(__VA_ARGS__)
#define EE_CLIENT_DEBUG(...) Elder::GetClientLogger()->debug(__VA_ARGS__)

#endif

#ifdef EE_NO_LOG
#define EE_CORE_INFO(...)
#define EE_CORE_WARN(...)
#define EE_CORE_ERROR(...)
#define EE_CORE_FATAL(...)
#define EE_CLIENT_INFO(...)
#define EE_CLIENT_WARN(...)
#define EE_CLIENT_ERROR(...)
#define EE_CLIENT_FATAL(...)

#else
#define EE_CORE_INFO(...)    Elder::GetCoreLogger()->info(__VA_ARGS__)
#define EE_CORE_WARN(...)    Elder::GetCoreLogger()->warn(__VA_ARGS__)
#define EE_CORE_ERROR(...)   Elder::GetCoreLogger()->error(__VA_ARGS__)
#define EE_CORE_FATAL(...)   Elder::GetCoreLogger()->critical(__VA_ARGS__)
#define EE_CLIENT_INFO(...)  Elder::GetClientLogger()->info(__VA_ARGS__)
#define EE_CLIENT_WARN(...)  Elder::GetClientLogger()->warn(__VA_ARGS__)
#define EE_CLIENT_ERROR(...) Elder::GetClientLogger()->error(__VA_ARGS__)
#define EE_CLIENT_FATAL(...) Elder::GetClientLogger()->critical(__VA_ARGS__)

#endif
