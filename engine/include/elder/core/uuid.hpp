#pragma once

#include "elder/eepch.hpp"

namespace Elder {

    class UUID final {
      public:

        UUID();
        UUID(UUID&&)      = default;
        UUID(const UUID&) = delete;

        operator uint64_t() const noexcept { return mID; }

      private:

        uint64_t mID;
    };

} // namespace Elder
