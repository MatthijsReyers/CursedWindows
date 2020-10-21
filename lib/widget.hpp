#pragma once

#include <utility>
#include <functional>
#include <stdint.h>

namespace cw
{
    class Widget
    {
    public:
        // Overwritable events.
        // ====================================================================
        std::function<void()> onDraw;
        std::function<void()> onResize;

        // Mouse related events.
        // ====================================================================
        std::function<void()> onMouseUp;
        std::function<void()> onMouseMove;
        std::function<void()> onMouseDown;

        // Note overwriting any of the below functions will cause onKey() not
        // to be called for that key.
        // ====================================================================
        std::function<void()> onKey;
        std::function<void()> onKeyHome;
        std::function<void()> onKeyArrow;
        std::function<void()> onKeyEscape;
        std::function<void()> onKeyDelete;
        std::function<void()> onKeyTab;

        // Should be called automatically by the parent layout.
        // ====================================================================
        virtual void draw();
        virtual void resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

        // Note that setPosition is meant to be called by the parent layout and
        // should only manually be called if the widget is in a free layout.
        // ====================================================================
        void setPosition(uint16_t x, uint16_t y);
        std::pair<uint16_t, uint16_t> getPosition() const;
        uint16_t getPositionX() const;
        uint16_t getPositionY() const;

        // Note that setSize is meant to be called by the parent layout and
        // should only manually be called if the widget is in a free layout.
        // ====================================================================
        void setSize(uint16_t width, uint16_t height);
        std::pair<uint16_t, uint16_t> getSize() const;
        uint16_t getWidth() const;
        uint16_t getHeight() const;
    
    protected:
        uint16_t posX, posY;
        uint16_t width, height;
    };
}
