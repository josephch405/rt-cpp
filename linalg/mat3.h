#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>
#include "vec3.h"
// #include "mat4.h"

// using std::sqrt;

class mat3
{
public:
    vec3 v[3];
    mat3() : v{vec3({0, 0, 0}), vec3({0, 0, 0}), vec3({0, 0, 0})} {}
    mat3(double a[9]) : v{
                            vec3({a[0], a[1], a[2]}),
                            vec3({a[3], a[4], a[5]}),
                            vec3({a[6], a[7], a[8]}),
                        }
    {
    }

    mat3(double a[3][3]) : v{
                               vec3({a[0][0], a[0][1], a[0][2]}),
                               vec3({a[1][0], a[1][1], a[1][2]}),
                               vec3({a[2][0], a[2][2], a[2][2]}),
                           }
    {
    }

    mat3(vec3 const a[3]) : v{a[0], a[1], a[2]} {}
    mat3(vec3 a, vec3 b, vec3 c) : v{a, b, c} {}

    mat3 operator-() const
    {
        return mat3(new vec3[3]{-v[0], -v[1], -v[2]});
    }

    const vec3 operator[](int i) const { return v[i]; }
    vec3 &operator[](int i) { return v[i]; }

    // This could have been safer and I regret cpp
    mat3 &operator+=(const mat3 &m)
    {
        v[0] += m[0];
        v[1] += m[1];
        v[2] += m[2];
        return *this;
    }

    mat3 &operator*=(const double t)
    {
        v[0] *= t;
        v[1] *= t;
        v[2] *= t;
        return *this;
    }

    mat3 &operator/=(const double t)
    {
        v[0] /= t;
        v[1] /= t;
        v[2] /= t;
        return *this;
    }

    mat3 transpose() const;
};

inline std::ostream &operator<<(std::ostream &out, const mat3 &m)
{
    return out << "[[" << m[0] << "],[" << m[1] << "],[" << m[2] << "]]";
}

inline mat3 operator+(const mat3 &a, const mat3 &b)
{
    return mat3(new vec3[3]{a[0] + b[0], a[1] + b[1], a[2] + b[2]});
}

inline mat3 operator-(const mat3 &a, const mat3 &b)
{
    return mat3(new vec3[3]{a[0] - b[0], a[1] - b[1], a[2] - b[2]});
}

// Matrix multiply
inline mat3 operator*(const mat3 &a, const mat3 &b);

inline bool operator==(const mat3 &a, const mat3 &b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

inline bool operator!=(const mat3 &a, const mat3 &b)
{
    return !(a == b);
}

inline mat3 operator*(const mat3 &a, const double t)
{
    return mat3(a[0] * t, a[1] * t, a[2] * t);
}

inline mat3 operator*(const double t, const mat3 &a)
{
    return a * t;
}

inline mat3 operator/(const mat3 &a, const double t)
{
    return a * (1 / t);
}

#endif