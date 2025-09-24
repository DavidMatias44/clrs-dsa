#include "../../include/redBlackTrees/color.h"

std::ostream& operator<<(std::ostream& os, Color c)
{
    switch (c) {
    case Color::RED:
        std::cout << "red";
        break;
    case Color::BLACK:
        std::cout << "black";
        break;
    default:
        break;
    }

    return os;
}
