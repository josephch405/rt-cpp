#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec4
{
public:
    double e[4];
    vec4() : e{0, 0, 0, 0} {}
    vec4(double x, double y, double z, double w) : e{x, y, z, w} {}
    vec4(double v[4]) : e{v[0], v[1], v[2], v[3]} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    double w() const { return e[3]; }

    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec4 &operator+=(const vec4 &v)
    {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        e[3] += v[3];
        return *this;
    }

    vec4 &operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    vec4 &operator/=(const double t)
    {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        e[3] /= t;
        return *this;
    }

    double length()
    {
        return sqrt(length_squared());
    }

    double length_squared()
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }

    double dot(const vec4 v) const;
};

class point : public vec4
{
public:
    point() : point(0, 0, 0){};
    point(vec4 v) : vec4(v[0], v[1], v[2], 1){};
    point(double x, double y, double z) : vec4(x, y, z, 1){};
};

class vector : public vec4
{
public:
    vector() : vector(0, 0, 0){};
    vector(vec4 v) : vec4(v[0], v[1], v[2], 0){};
    vector(double x, double y, double z) : vec4(x, y, z, 0){};

    vector normalize();
};

inline std::ostream &operator<<(std::ostream &out, const vec4 &v)
{
    return out << '[' << v[0] << ',' << v[1] << ',' << v[2] << ',' << v[3] << ']';
}

inline vec4 operator+(const vec4 &v, const vec4 &w)
{
    return vec4(v[0] + w[0], v[1] + w[1], v[2] + w[2], v[3] + w[3]);
}

inline vec4 operator-(const vec4 &v, const vec4 &w)
{
    return vec4(v[0] - w[0], v[1] - w[1], v[2] - w[2], v[3] - w[3]);
}

inline vec4 operator*(const vec4 &v, const vec4 &w)
{
    return vec4(v[0] * w[0], v[1] * w[1], v[2] * w[2], v[3] * w[3]);
}

inline bool operator==(const vec4 &v, const vec4 &w)
{
    vec4 u = v - w;
    return u.length() < 0.000001;
}

inline bool operator!=(const vec4 &v, const vec4 &w)
{
    return !(v == w);
}

inline vec4 operator*(const vec4 &v, const double t)
{
    return vec4(v[0] * t, v[1] * t, v[2] * t, v[3] * t);
}

inline vec4 operator*(const double t, const vec4 &v)
{
    return v * t;
}

inline vec4 operator/(const vec4 &v, const double t)
{
    return v * (1 / t);
}

inline double dot(const vec4 &v, const vec4 &w)
{
    return v[0] * w[0] + v[1] * w[1] + v[2] * w[2] + v[3] * w[3];
}

inline vec4 cross(const vec4 &v, const vec4 &w)
{
    return vec4(v[1] * w[2] - v[2] * w[1],
                v[2] * w[0] - v[0] * w[2],
                v[0] * w[1] - v[1] * w[0], 0);
}

inline vec4 unit_vector(vec4 v)
{
    return v / v.length();
}

#endif