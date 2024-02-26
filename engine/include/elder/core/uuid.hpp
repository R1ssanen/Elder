#pragma once

#include "elder/eepch.hpp"

namespace Elder {

    class UUID final {
      public:

        UUID();
        UUID(UUID&&)                 = default;

        UUID(const UUID&)            = delete;
        UUID& operator=(UUID&&)      = delete;
        UUID& operator=(const UUID&) = delete;

        operator unsigned long() const noexcept { return mID; }

      private:

        uint64_t mID;
    };

} // namespace Elder
