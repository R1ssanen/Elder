#include "elder/core/log.hpp"

#include "elder/eepch.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace {

    Elder::Shared<spdlog::logger> sCoreLogger   = spdlog::stdout_color_mt("CORE");
    Elder::Shared<spdlog::logger> sClientLogger = spdlog::stdout_color_mt("CLIENT");

} // namespace

namespace Elder {

    Shared<spdlog::logger> GetCoreLogger() noexcept { return sCoreLogger; }

    Shared<spdlog::logger> GetClientLogger() noexcept { return sClientLogger; }

    void                   InitLog(const LogLevel& tLogLevel) {
        spdlog::set_pattern("%^[%n/%L]%$ %v (%T)");

        sCoreLogger->set_level(static_cast<spdlog::level::level_enum>(tLogLevel));
        sClientLogger->set_level(static_cast<spdlog::level::level_enum>(tLogLevel));
    }

} // namespace Elder
