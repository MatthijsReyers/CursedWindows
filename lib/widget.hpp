#pragma once

#include <utility>
#include <stdint.h>

namespace cw
{
    class widget
    {
    public:
        // All drawing related code should be put in here
        // ====================================================================
        virtual void onDraw();

        // Mouse related events.
        // ====================================================================
        virtual void onMouseUp();
        virtual void onMouseMove();
        virtual void onMouseDown();

        // Note overwriting any of the below functions will cause onKey() not
        // to be called for that key.
        // ====================================================================
        virtual void onKey();
        virtual void onKeyHome();
        virtual void onKeyArrow();
        virtual void onKeyEscape();
        virtual void onKeyDelete();
        virtual void onKeyTab();

        // Should be called automatically by the parent layout.
        // ====================================================================
        virtual void onResize(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

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

    private:
        bool running = false;

    };
}