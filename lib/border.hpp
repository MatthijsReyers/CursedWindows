#pragma once

namespace cw
{
    struct Border
    {
        const static char cornerTL[], cornerBL[], cornerTR[], cornerBR[];
        const static char horizontal[], vertical[];
    };
    
    struct DBorder : public Border
    {
        const char* cornerTL = "╔";
        const char* cornerBL = "╚";
        const char* cornerTR = "╗";
        const char* cornerBR = "╝";

        const char* horizontal = "═";
        const char* vertical = "║";

    } DoubleBorder;

    struct SBorder : public Border
    {
        const char* cornerTL = "┌";
        const char* cornerBL = "└";
        const char* cornerTR = "┐";
        const char* cornerBR = "┘";

        const char* horizontal = "─";
        const char* vertical = "│";

    } SingleBorder;
}