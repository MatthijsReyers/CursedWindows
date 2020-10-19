#pragma once

#include "../errors.hpp"
#include "../widget.hpp"
#include "../layout.hpp"

#include <utility>
#include <functional>
#include <vector>
#include <stdint.h>

namespace cw
{
    class GridLayout : public Layout
    {
    public:
        GridLayout();
        GridLayout(uint16_t rows, uint16_t columns);
        GridLayout(uint16_t rows, uint16_t columns, uint16_t hGap, uint16_t vGap);

        uint16_t getRows() const;
        uint16_t getColumns() const;
        void setRows(uint16_t rows);
        void setColumns(uint16_t columns);

        uint16_t getHorizontalGap() const;
        uint16_t getVerticalGap() const;
        void setHorizontalGap(uint16_t hGap);
        void setVerticalGap(uint16_t vGap);

        void addWidget(Widget& widget);
        void addWidget(Widget& widget, uint16_t x, uint16_t y);
        Widget& getWidget(uint16_t x, uint16_t y);
        void deleteWidget(uint16_t x, uint16_t y);
    
    protected:
        uint16_t rows, columns;
        uint16_t horizontalGap, verticalGap;
        std::vector<std::vector<Widget&>> widgets;
        Widget& activeWidget;

    private:

    };
}