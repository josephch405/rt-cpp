#ifndef RT_DEMO_H
#define RT_DEMO_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

const double inf = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_rads(double degrees)
{
    return degrees * pi / 180.0;
}

inline double random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
    return random_double() * (max - min) + min;
}

inline double clamp(double x, double min, double max)
{
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

#include "ray.h"
#include "linalg/vec.h"

#endif