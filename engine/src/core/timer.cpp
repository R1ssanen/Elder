#include "elder/core/timer.hpp"

#include "elder/core/log.hpp"

namespace Elder {

    const size_t& Timer::GetFramesElapsed() const noexcept { return m.FramesElapsed; }

    void          Timer::Tick() noexcept {
        m.FramesElapsed++;
        timepoint_t Now = std::chrono::high_resolution_clock::now();

        m.TimeElapsed += Now - m.FrameStart;
        m.FrameStart = Now;
    }

    Timer::Timer() {
        timepoint_t StartTime = std::chrono::high_resolution_clock::now();

        m                     = _M{ .TimerStart    = StartTime,
                                    .FrameStart    = StartTime,
                                    .TimeElapsed   = nanoseconds(0),
                                    .FramesElapsed = 0UL };
    }

    Timer::Timer(const Timer& tOther) : m(tOther.m) { }

    Timer::Timer(Timer&& tOther) : m(std::move(tOther.m)) { }

} // namespace Elder
