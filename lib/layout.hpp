#pragma once

#include "widget.hpp"

#include <utility>
#include <functional>
#include <memory>
#include <stdint.h>

namespace cw
{
    /**
     * 
     */
    class Layout : public Widget
    {
    public:
        virtual void resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h) = 0;
    
    protected:

    private:

    };
}