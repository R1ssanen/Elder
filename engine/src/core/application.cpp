#include "elder/core/application.hpp"

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"

namespace Elder {

    Application::Application() : mLayerStack(LayerStack::New()), mIsRunning(true) {
#if EE_DEBUG_CTOR
        EE_CORE_DEBUG("App [{0}] constructed.", static_cast<size_t>(mID));
#endif
    }

    Application::~Application() {
#if EE_DEBUG_DTOR
        EE_CORE_DEBUG("App [{0}] destructed.", static_cast<size_t>(mID));
#endif
    }

    void Application::PushLayer(Layer* tLayer) {
        mLayerStack->Push(tLayer);
        tLayer->OnPush();
    }

    void Application::PopLayer(Layer* tLayer) {
        mLayerStack->Pop(tLayer);
        tLayer->OnPop();
    }

    void Application::MainLoop() {

        while (mTimer.GetFramesElapsed() < 100 && mIsRunning) {

            for (Layer* Layer : *mLayerStack) { Layer->OnUpdate(); }

            mTimer.Tick();
        }
    }

} // namespace Elder
