#pragma once

#include "elder/eepch.hpp"
#include "elder/core/layer.hpp"

namespace Elder {

    class LayerStack final {
        using stack_t = std::vector<Layer*>;

      public:

        void              Push(Layer* tLayer);
        void              Pop(Layer* tLayer);
        stack_t::iterator begin() noexcept;
        stack_t::iterator end() noexcept;

        LayerStack&       operator=(LayerStack&&);
        explicit LayerStack(LayerStack&&);

        LayerStack& operator=(const LayerStack&) = delete;
        LayerStack(const LayerStack&)            = delete;

        static Unique<LayerStack> New();

        LayerStack();
        ~LayerStack();

      private:

        struct _M {
            stack_t           Layers;
            stack_t::iterator LastLayer;
        } m;
    };

} // namespace Elder
