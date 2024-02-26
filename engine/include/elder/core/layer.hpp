#pragma once

#include "elder/eepch.hpp"
#include "elder/core/uuid.hpp"

namespace Elder {

    class EE_API Layer {
      public:

        const bool& IsOverlay() const noexcept;

        explicit Layer(bool tIsOverlay);
        virtual ~Layer();

        virtual void OnUpdate() = 0;
        virtual void OnPush();
        virtual void OnPop();

        // virtual void OnEvent(Event& tEvent) = 0;

      protected:

        UUID mID;
        bool mIsActive;
        bool mIsOverlay;
    };

} // namespace Elder
