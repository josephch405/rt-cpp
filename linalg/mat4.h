#ifndef mat4_H
#define mat4_H

#include <cmath>
#include <iostream>
#include "vec4.h"

class mat4
{
public:
    vec4 v[4];
    mat4() : v{
                 vec4({0, 0, 0, 0}),
                 vec4({0, 0, 0, 0}),
                 vec4({0, 0, 0, 0}),
                 vec4({0, 0, 0, 0})} {}
    mat4(double a[16]) : v{
                             vec4({a[0], a[1], a[2], a[3]}),
                             vec4({a[4], a[5], a[6], a[7]}),
                             vec4({a[8], a[9], a[10], a[11]}),
                             vec4({a[12], a[13], a[14], a[15]})}
    {
    }

    mat4(double a[4][4]) : v{
                               vec4({a[0][0], a[0][1], a[0][2], a[0][3]}),
                               vec4({a[1][0], a[1][1], a[1][2], a[1][3]}),
                               vec4({a[2][0], a[2][2], a[2][2], a[2][3]}),
                               vec4({a[3][0], a[3][2], a[3][2], a[3][3]}),
                           }
    {
    }

    mat4(vec4 const a[4]) : v{a[0], a[1], a[2], a[3]} {}
    mat4(vec4 a, vec4 b, vec4 c, vec4 d) : v{a, b, c, d} {}

    mat4 operator-() const
    {
        return mat4(new vec4[4]{-v[0], -v[1], -v[2], -v[3]});
    }

    const vec4 operator[](int i) const { return v[i]; }
    vec4 &operator[](int i) { return v[i]; }

    mat4 &operator+=(const mat4 &m)
    {
        v[0] += m[0];
        v[1] += m[1];
        v[2] += m[2];
        v[3] += m[3];
        return *this;
    }

    mat4 &operator*=(const double t)
    {
        v[0] *= t;
        v[1] *= t;
        v[2] *= t;
        v[3] *= t;
        return *this;
    }

    mat4 &operator/=(const double t)
    {
        v[0] /= t;
        v[1] /= t;
        v[2] /= t;
        v[3] /= t;
        return *this;
    }

    mat4 transpose() const;
};

inline std::ostream &operator<<(std::ostream &out, const mat4 &m)
{
    return out << "[[" << m[0] << "],["
               << m[1] << "],["
               << m[2] << "],["
               << m[3] << "]]";
}

inline mat4 operator+(const mat4 &a, const mat4 &b)
{
    return mat4(new vec4[4]{a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]});
}

inline mat4 operator-(const mat4 &a, const mat4 &b)
{
    return mat4(new vec4[4]{a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]});
}

// Matrix multiply
mat4 operator*(const mat4 &a, const mat4 &b);

vec4 operator*(const mat4 &a, const vec4 &v);

inline bool operator==(const mat4 &a, const mat4 &b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

inline bool operator!=(const mat4 &a, const mat4 &b)
{
    return !(a == b);
}

inline mat4 operator*(const mat4 &a, const double t)
{
    return mat4(a[0] * t, a[1] * t, a[2] * t, a[3] * t);
}

inline mat4 operator*(const double t, const mat4 &a)
{
    return a * t;
}

inline mat4 operator/(const mat4 &a, const double t)
{
    return a * (1 / t);
}

mat4 I4 = mat4({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

#endif