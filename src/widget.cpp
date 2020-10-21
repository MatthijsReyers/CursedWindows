#include "widget.hpp"


namespace cw
{
    void Widget::resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
    {
        this->setPosition(x,y);
        this->setSize(w,h);

        // Check and call the draw callback if specified.
        if (this->onResize) this->onResize();

        this->draw();

        // Check and call the draw callback if specified.
        if (this->onDraw) this->onDraw();
    }
}