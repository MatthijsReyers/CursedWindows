#include "widget.hpp"


namespace cw
{
    void Widget::draw()
    {
        // This is a pure widget and should not be called
    }

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

    void Widget::setPosition(uint16_t x, uint16_t y)
    {
        this->posX = x;
        this->posY = y;

        // TODO: Check if x and y are smaller than the size of the terminal.
    }

    uint16_t Widget::getPositionX() const {return this->posX;}
    uint16_t Widget::getPositionY() const {return this->posY;}

    void Widget::setSize(uint16_t w, uint16_t h)
    {
        this->width = w;
        this->height = h;

        // TODO: Check if w and h are smaller than the size of the terminal.
    }

    std::pair<uint16_t, uint16_t> Widget::getSize() const
    {
        return std::pair<uint16_t, uint16_t>(this->posY, this->posY);
    }

    uint16_t Widget::getWidth() const {return this->width;}
    uint16_t Widget::getHeight() const {return this->height;}


}