
#include "layouts/grid.hpp"

namespace cw
{
    GridLayout::GridLayout() 
        :rows(1), columns(1), horizontalGap(0), verticalGap(0) {}
    GridLayout::GridLayout(uint16_t r, uint16_t c)
        :rows(r), columns(c), horizontalGap(0), verticalGap(0) {}
    GridLayout::GridLayout(uint16_t r, uint16_t c, uint16_t hg, uint16_t vg)
        :rows(r), columns(c), horizontalGap(hg), verticalGap(vg) {}

    uint16_t GridLayout::getRows() const
        {return this->rows;}
    uint16_t GridLayout::getColumns() const
        {return this->columns;}
    void GridLayout::setRows(uint16_t r)
        {this->rows = r;}
    void GridLayout::setColumns(uint16_t c)
        {this->columns = c;}

    uint16_t GridLayout::getHorizontalGap() const
        {return this->horizontalGap;}
    uint16_t GridLayout::getVerticalGap() const
        {return this->verticalGap;}
    void GridLayout::setHorizontalGap(uint16_t hGap)
        {this->horizontalGap = hGap;}
    void GridLayout::setVerticalGap(uint16_t vGap)
        {this->verticalGap = vGap;}

    void GridLayout::addWidget(Widget& widget)
    {
        for (uint16_t x = 0; x < this->rows; x++)
        {
            if (widgets[x].size() < this->columns)
            {
                widgets[x].push_back(widget);
                return;
            }
        }
        
        throw InvalidWidgetPlacement("No space left in grid layout for widget.");
    }

    void GridLayout::addWidget(Widget& widget, uint16_t x, uint16_t y)
    {
        if (x >= this->width || y >= this->height)
            throw InvalidWidgetPlacement("Cannot place widget outside of grid.");
        
    }
}