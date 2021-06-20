#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "linalg/vec4.h"

struct hit_record
{
    point p;
    vec4 normal;
    double t;
    bool front_face;

    inline bool set_face_normal(const ray &r, const vec4 &outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
        return true;
    }
};

class hittable
{
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};

#endif