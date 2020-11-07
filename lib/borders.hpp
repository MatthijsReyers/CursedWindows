#pragma once

#include <string>
#include <ncurses.h>

namespace cw
{
    class Border
    {
    public:
        std::string cornerTL;
        std::string cornerBL;
        std::string cornerTR;
        std::string cornerBR;

        std::string horizontal;
        std::string vertical;

        Border() = default;
    };
    
    class DoubleBorder : public Border
    {
    public:
        DoubleBorder(const DoubleBorder&) = default;
        DoubleBorder& operator=(const DoubleBorder&) = default;
        DoubleBorder() {
            cornerTL = "╔";
            cornerBL = "╚";
            cornerTR = "╗";
            cornerBR = "╝";
            
            horizontal = "═";
            vertical = "║";
        }
    };

    class SingleBorder : public Border
    {
    public:
        SingleBorder(const SingleBorder&) = default;
        SingleBorder& operator=(const SingleBorder&) = default;
        SingleBorder() {
            cornerTL = "┌";
            cornerBL = "└";
            cornerTR = "┐";
            cornerBR = "┘";
            
            horizontal = "─";
            vertical = "│";
        }
    };
}

#include "iostream"