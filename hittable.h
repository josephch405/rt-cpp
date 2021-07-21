#ifndef HITTABLE_H
#define HITTABLE_H

#include "linalg/vec.h"
#include "ray.h"

struct hit_record
{
    point p;
    vector normal;
    double t;
    bool front_face;

    inline bool set_face_normal(const ray &r, const vector &outward_normal)
    {
        front_face = r.direction().dot(outward_normal) < 0;
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