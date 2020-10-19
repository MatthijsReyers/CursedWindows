#pragma once

#include <exception>

namespace cw
{
    class InvalidWidgetPlacement : public std::exception
    {
    private:
        const char* message;

    public:
        InvalidWidgetPlacement(const char* m)
            : message(m) {}

        const char * what () const throw ()
            {return message;}
    };
}
