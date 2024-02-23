#include "elder/core/application.hpp"

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"

namespace Elder {

    const bool& Application::IsRunning() const { return mIsRunning; }

    Application::Application() {
#if ELDER_DEBUG_CTOR
        EE_CORE_INFO("App ID [{0}] constructed.", mAppID);
#endif
    }

    Application::~Application() {
#if ELDER_DEBUG_DTOR
        EE_CORE_INFO("App ID [{0}] destructed.", mAppID);
#endif
    }

} // namespace Elder
