#include "elder/core/uuid.hpp"

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"

namespace {

    std::random_device                                sRandomDevice;
    std::mt19937_64                                   sRandomEngine(sRandomDevice());
    std::uniform_int_distribution<unsigned long long> sDistribution(0ULL, 18446744073709551615ULL);

} // namespace

namespace Elder {

    UUID::UUID() : mID(sDistribution(sRandomEngine)) {
#if ELDER_DEBUG_ID_CREATION
        EE_CORE_DEBUG("New UUID: {0}", mID);
#endif
    }

} // namespace Elder

namespace std {

    template <> class hash<Elder::UUID> {
        size_t operator()(const Elder::UUID& tID) const {
            return std::hash<uint64_t>()(static_cast<uint64_t>(tID));
        }
    };

} // namespace std
