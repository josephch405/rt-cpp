#ifndef COLOR_H
#define COLOR_H

#include "utils.h"

#include <iostream>

using color = vec3;

vector make_color(double a, double b, double c)
{
    return make_vec3(a, b, c);
}

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel)
{
    auto r = pixel_color[0];
    auto g = pixel_color[1];
    auto b = pixel_color[2];

    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif
