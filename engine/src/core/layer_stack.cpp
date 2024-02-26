#include "elder/core/layer_stack.hpp"

#include "elder/eepch.hpp"
#include "elder/core/layer.hpp"
#include "elder/core/log.hpp"

namespace Elder {

    void LayerStack::Push(Layer* tLayer) {
        if (tLayer->IsOverlay()) {
            m.Layers.push_back(tLayer);
        }

        else {
            m.LastLayer = m.Layers.emplace(m.LastLayer, tLayer);
        }
    }

    void LayerStack::Pop(Layer* tLayer) {
        auto it = std::find(m.Layers.begin(), m.Layers.end(), tLayer);

        if (it != m.Layers.end()) {
            m.Layers.erase(it);

            if (!tLayer->IsOverlay()) { m.LastLayer--; }
        }
    }

    LayerStack::stack_t::iterator LayerStack::begin() noexcept { return m.Layers.begin(); }

    LayerStack::stack_t::iterator LayerStack::end() noexcept { return m.Layers.end(); }

    LayerStack&                   LayerStack::operator=(LayerStack&& tOther) {
        m = std::move(tOther.m);
        return *this;
    }

    LayerStack::LayerStack(LayerStack&& tOther) : m(std::move(tOther.m)) { }

    LayerStack::LayerStack() {
#if EE_DEBUG_CTOR
        EE_CORE_DEBUG("LayerStack constructed.");
#endif
    }

    LayerStack::~LayerStack() {
        for (Layer* Layer : m.Layers) { delete Layer; }

#if EE_DEBUG_DTOR
        EE_CORE_DEBUG("LayerStack destructed.");
#endif
    }

    Unique<LayerStack> LayerStack::New() { return std::make_unique<LayerStack>(); }

} // namespace Elder
