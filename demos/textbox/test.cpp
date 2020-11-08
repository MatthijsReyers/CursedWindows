
#include <cursedwindows/borders.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    auto test = cw::DoubleBorder();
    std::cout << test.cornerTR.c_str() << std::endl;
    return 0;
}
