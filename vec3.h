#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{
public:
    vec3() : e{0, 0, 0} {}
    vec3(double x, double y, double z) : e{x, y, z} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    vec3 &operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3 &operator/=(const double t)
    {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    double length()
    {
        return sqrt(length_squared());
    }

    double length_squared()
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

public:
    double e[3];
};

using point3 = vec3;
using color = vec3;

inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << '[' << v[0] << ',' << v[1] << ',' << v[2] << ']';
}

inline vec3 operator+(const vec3 &v, const vec3 &w)
{
    return vec3(v[0] + w[0], v[1] + w[1], v[2] + w[2]);
}

inline vec3 operator-(const vec3 &v, const vec3 &w)
{
    return vec3(v[0] - w[0], v[1] - w[1], v[2] - w[2]);
}

inline vec3 operator*(const vec3 &v, const vec3 &w)
{
    return vec3(v[0] * w[0], v[1] * w[1], v[2] * w[2]);
}

inline vec3 operator*(const vec3 &v, const double t)
{
    return vec3(v[0] * t, v[1] * t, v[2] * t);
}

inline vec3 operator*(const double t, const vec3 &v)
{
    return v * t;
}

inline vec3 operator/(const vec3 &v, const double t)
{
    return v * (1 / t);
}

inline double dot(const vec3 &v, const vec3 &w)
{
    return v[0] * w[0] + v[1] * w[1] + v[2] * w[2];
}

inline vec3 cross(const vec3 &v, const vec3 &w)
{
    return vec3(v[1] * w[2] - v[2] * w[1],
                v[2] * w[0] - v[0] * w[2],
                v[0] * w[1] - v[1] * w[0]);
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

#endif