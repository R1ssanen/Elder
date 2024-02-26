#pragma once

#include "elder/eepch.hpp"
#include "elder/core/uuid.hpp"

namespace Elder {

    using nanoseconds  = std::chrono::nanoseconds;
    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds      = std::chrono::seconds;
    using hours        = std::chrono::hours;

    class EE_API Timer final {
      public:

        template <typename E, typename T = size_t> T GetTimeElapsed() const {
            return std::chrono::duration_cast<E>(m.TimeElapsed).count();
        }

        const size_t& GetFramesElapsed() const noexcept;

        void          Tick() noexcept;

        Timer();
        explicit Timer(const Timer&);
        explicit Timer(Timer&&);

      private:

        using timepoint_t = std::chrono::high_resolution_clock::time_point;

        struct _M {
            timepoint_t TimerStart, FrameStart;
            nanoseconds TimeElapsed;
            size_t      FramesElapsed;
        } m;
    };

} // namespace Elder
