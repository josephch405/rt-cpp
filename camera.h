#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

class camera
{
public:
    camera()
    {
        const auto aspect_ratio = 16. / 9.;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * aspect_ratio;
        auto focal_length = 1.0;

        origin = point(0, 0, 0);
        horizontal = vector(viewport_width, 0, 0);
        vertical = vector(0, viewport_height, 0);
        lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector(0, 0, focal_length);
    };

    ray get_ray(double u, double v)
    {
        return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
    };

private:
    point origin;
    point lower_left_corner;
    vector horizontal;
    vector vertical;
};

#endif