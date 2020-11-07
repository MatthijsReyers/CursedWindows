
#include "layouts/border.hpp"
#include "widgets/empty.hpp"

#include "ncurses.h"

#include <sstream>
#include <string>
#include <iostream>

const char* autoToStr(int input)
{
    std::stringstream ss;
    ss << input;
    return (ss.str().c_str());
}

namespace cw
{
    BorderLayout::BorderLayout()
        : widget(std::make_shared<EmptyWidget>()) {}
    BorderLayout::BorderLayout(std::shared_ptr<Widget> w)
        : widget(w) {}

    void BorderLayout::setWidget(std::shared_ptr<Widget> widget)
    {
        this->widget = widget;
        this->draw();
    }

    std::shared_ptr<Widget> BorderLayout::getWidget() const noexcept
    {
        return this->widget;
    }

    void BorderLayout::setBorder(Border border)
    {
        // this->border = border;
    }

    Border BorderLayout::getBorder() const noexcept
    {
        return this->border;
    }
    
    void BorderLayout::resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
    {
        this->posX = x;
        this->posY = y;
        this->width = w;
        this->height = h;

        // Check if the resize callback needs calling.
        if (this->onDraw) this->onDraw();

        // Redraw widget.
        this->draw();

        // Check if the draw callback needs calling.
        if (this->onResize) this->onResize();

        // Resize child widget.
        this->widget->resize(posX + 1, posY + 1, width-2, height-2);
    }

    void BorderLayout::draw()
    {
        // Placing the corners.
        mvaddstr(this->posX, this->posY, this->border.cornerTL.c_str());
        mvaddstr(this->posX - this->width - 1, this->posY, this->border.cornerTR.c_str());
        mvaddstr(this->posX - this->width - 1, this->posY, this->border.cornerBL.c_str());
        mvaddstr(this->posX, this->posY - this->height - 1, this->border.cornerBL.c_str());
        mvaddstr(this->posX - this->width - 1, this->posY - this->height - 1, this->border.cornerBR.c_str());

        // Placing the straight horizontal borders.
        for (uint16_t x = 0; x < this->width; x++) {
            mvaddstr(this->posX + x, this->posY, this->border.horizontal.c_str());
            mvaddstr(this->posX + x, this->posY + this->height - 1, this->border.horizontal.c_str());
        }

        // Placing the straight vertical borders.
        for (uint16_t y = 0; y < this->height; y++) {
            mvaddstr(this->posX, this->posY + y, this->border.horizontal.c_str());
            mvaddstr(this->posX + this->height - 1, this->posY + y, this->border.horizontal.c_str());
        }
        
        // Draw widget
        if (this->widget) this->widget->draw();

        refresh();
    }
}