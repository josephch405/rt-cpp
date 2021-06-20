#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "linalg/vec3.h"

class sphere : public hittable
{
public:
    point center;
    double radius;

    sphere(){};
    sphere(point c, double r) : center(c), radius(r){};

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

    vector normal_at(point p);
};

#endif