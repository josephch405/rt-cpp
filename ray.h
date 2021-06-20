#ifndef RAY_H
#define RAY_H

#include "linalg/vec4.h"

class ray
{
public:
    ray() {}
    ray(const point &origin, const vector &direction)
        : orig(origin), dir(direction)
    {
    }

    point origin() const { return orig; }
    vector direction() const { return dir; }

    point at(double t) const
    {
        return point(orig + t * dir);
    }

    point orig;
    vector dir;
};

#endif