#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum class Color
{
    RED, BLACK
};

std::ostream& operator<<(std::ostream&, Color);

#endif // COLOR_H
