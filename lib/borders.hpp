#pragma once

#include <string>

namespace cw
{
    class Border
    {
    public:
        Border() = default;
        Border(const Border&) = default;
        Border& operator=(const Border&) = default;

        const std::string cornerTL;
        const std::string cornerBL;
        const std::string cornerTR;
        const std::string cornerBR;

        const std::string horizontal;
        const std::string vertical;
    };
    
    class DoubleBorder : public Border
    {
    public:
        DoubleBorder() = default;
        DoubleBorder(const DoubleBorder&) = default;
        DoubleBorder& operator=(const DoubleBorder&) = default;

        const std::string cornerTL = "╔";
        const std::string cornerBL = "╚";
        const std::string cornerTR = "╗";
        const std::string cornerBR = "╝";

        const std::string horizontal = "═";
        const std::string vertical = "║";

    };

    class SingleBorder
    {
    public:
        SingleBorder() = default;
        SingleBorder(const SingleBorder&) = default;
        SingleBorder& operator=(const SingleBorder&) = default;

        const std::string cornerTL = "┌";
        const std::string cornerBL = "└";
        const std::string cornerTR = "┐";
        const std::string cornerBR = "┘";

        const std::string horizontal = "─";
        const std::string vertical = "│";

    };
}