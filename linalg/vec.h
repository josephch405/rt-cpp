#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

template <int N>
class vec
{
public:
    double e[N]{0};
    vec<N>() : e{0} {}
    vec<N>(double arr[N])
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = arr[i];
        }
    }

    vec<N> operator-() const { return vec2(e.map()); }
    const double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec<N> &operator+=(const vec<N> &v);

    vec<N> &operator*=(const double t);

    vec<N> &operator/=(const double t);

    double length() const
    {
        return sqrt(length_squared());
    }

    double length_squared() const;

    vec<N> normalize() const;

    double dot(const vec<N> v) const;
};

template <int N>
std::ostream &operator<<(std::ostream &out, const vec<N> &v);

template <int N>
vec<N> operator+(const vec<N> &v, const vec<N> &w);

template <int N>
vec<N> operator-(const vec<N> &v, const vec<N> &w);

template <int N>
vec<N> operator*(const vec<N> &v, const vec<N> &w);

template <int N>
bool operator==(const vec<N> &v, const vec<N> &w)
{
    vec<N> u = v - w;
    return u.length() < 0.00001; // Might be good to have this vary vs N
}

template <int N>
bool operator!=(const vec<N> &v, const vec<N> &w)
{
    return !(v == w);
}

template <int N>
vec<N> operator*(const vec<N> &v, const double t);

template <int N>
inline vec<N> operator*(const double t, const vec<N> &v)
{
    return v * t;
}

template <int N>
inline vec<N> operator/(const vec<N> &v, const double t)
{
    return v * (1 / t);
}

template <int N>
inline double dot(const vec<N> &v, const vec<N> &w)
{
    return v.dot(w);
}

// inline vec2 cross(const vec2 &v, const vec2 &w)
// {
//     return vec2(v[1] * w[2] - v[2] * w[1],
//                 v[2] * w[0] - v[0] * w[2],
//                 v[0] * w[1] - v[1] * w[0]);
// }

template <int N>
inline vec<N> unit_vector(vec<N> v)
{
    return v / v.length();
}

#endif