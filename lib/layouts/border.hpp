#pragma once

#include "../errors.hpp"
#include "../widget.hpp"
#include "../layout.hpp"
#include "../border.hpp"

#include <stdint.h>

#include <utility>
#include <functional>
#include <memory>

namespace cw
{
    class BorderLayout : public Layout
    {
    public:
        BorderLayout();
        BorderLayout(std::shared_ptr<Widget> widget);

        void setWidget(std::shared_ptr<Widget> widget);
        std::shared_ptr<Widget> getWidget() const noexcept;

        void setBorder(Border border);
        Border getBorder() const noexcept;

        virtual void resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h) override;
        virtual void draw() override;

    protected:
        std::shared_ptr<Widget> widget;
        Border border = DoubleBorder;

    private:

    };
}