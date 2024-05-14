#ifndef GEOSHELL_H
#define GEOSHELL_H

#include <iostream>
#include <array>

class GeoShell
{
public:
    // FEATURES
    static std::array<double, 2> get_coordinates(std::string location);
};
#endif