#pragma once

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"
#include "elder/core/uuid.hpp"

namespace Elder {

    class EE_API Application {
      public:

        const bool&  IsRunning() const;

        virtual void OnUpdate() = 0;

        Application();
        virtual ~Application();

      protected:

        bool mIsRunning = true;

      private:

        UUID mAppID;
    };

} // namespace Elder

extern Elder::Unique<Elder::Application> CreateApp(int argc, char** argv);
