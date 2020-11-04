#pragma once

#include "../errors.hpp"
#include "../widget.hpp"
#include "../layout.hpp"

#include <stdint.h>

#include <utility>
#include <functional>
#include <vector>
#include <memory>

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

        virtual void addWidget(std::shared_ptr<Widget> widget) override;
        void addWidget(std::shared_ptr<Widget> widget, uint16_t x, uint16_t y);
        Widget& getWidget(uint16_t x, uint16_t y) const noexcept;
        void deleteWidget(uint16_t x, uint16_t y) noexcept;

        virtual void resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h) override;

    protected:
        uint16_t rows, columns;
        uint16_t horizontalGap, verticalGap;

        std::vector<std::vector<std::shared_ptr<Widget>>> widgets;
        std::weak_ptr<Widget> activeWidget;

        // Method called whenever the dimensions of the grid change.
        virtual void resizeGrid() noexcept;

    private:

    };
}