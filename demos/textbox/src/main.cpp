
#include "app.hpp"

#include "iostream"
#include <cursedwindows/borders.hpp>

int main(int argc, char const *argv[])
{
    // auto test = cw::DoubleBorder();
    // std::cout << test.cornerBL << test.cornerTR << std::endl;

    auto app = TextBoxApp();
    return app.start();
}
