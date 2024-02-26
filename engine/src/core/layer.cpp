#include "elder/core/layer.hpp"

#include "elder/eepch.hpp"
#include "elder/core/log.hpp"

namespace Elder {

    const bool& Layer::IsOverlay() const noexcept { return mIsOverlay; }

    Layer::Layer(bool tIsOverlay) : mIsActive(true), mIsOverlay(tIsOverlay) {
#if EE_DEBUG_CTOR
        EE_CORE_DEBUG("Layer [{0}] constructed.", static_cast<size_t>(mID));
#endif
    }

    Layer::~Layer() {
#if EE_DEBUG_DTOR
        EE_CORE_DEBUG("Layer [{0}] destructed.", static_cast<size_t>(mID));
#endif
    }

    void Layer::OnPush() {
#if EE_DEBUG_LAYER_PUSH
        EE_CORE_DEBUG("Layer [{0}] pushed to stack.", static_cast<size_t>(mID));
#endif
    }

    void Layer::OnPop() {
#if EE_DEBUG_LAYER_PUSH
        EE_CORE_DEBUG("Layer [{0}] popped from stack.", static_cast<size_t>(mID));
#endif
    }

} // namespace Elder
