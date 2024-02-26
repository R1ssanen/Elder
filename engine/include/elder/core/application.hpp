#pragma once

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"
#include "elder/core/uuid.hpp"
#include "elder/core/timer.hpp"
#include "elder/core/layer_stack.hpp"
#include "elder/core/layer.hpp"

namespace Elder {

    class EE_API Application {
      public:

        void MainLoop();

        // virtual void OnEvent(Event& tEvent);

        void PushLayer(Layer* tLayer);
        void PopLayer(Layer* tLayer);

        Application();
        virtual ~Application();

      protected:

        Unique<LayerStack> mLayerStack;
        Timer              mTimer;
        UUID               mID;
        bool               mIsRunning;
    };

} // namespace Elder

extern Elder::Unique<Elder::Application> CreateApp(int argc, char** argv);
