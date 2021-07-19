#ifndef mat_H
#define mat_H

#include <cmath>
#include <iostream>
#include "vec.h"
// #include "mat4.h"

// using std::sqrt;

template <int N, int M>
class mat
{
public:
    vec<M> v[N]{0};

    mat<N, M>(double a[N][M]);

    // mat2(vec<M> const a[N]) : v{a[0], a[1]} {}
    // mat2(vec2 a, vec2 b) : v{a, b} {}

    mat<N, M> operator-() const;

    const vec<M> operator[](int i) const { return v[i]; }
    vec<M> &operator[](int i) { return v[i]; }

    mat<N, M> &operator+=(const mat<N, M> &m)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] += m[i];
        }
        return *this;
    }

    mat<N, M> &operator*=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] *= t;
        }
        return *this;
    }

    mat<N, M> &operator/=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] /= t;
        }
        return *this;
    }

    mat<M, N> transpose() const;
};

template <int N, int M>
inline std::ostream &operator<<(std::ostream &out, const mat<N, M> &m)
{
    out << "[[" << m[0];
    for (int i = 1; i < N; i++)
    {
        out << "],[" << m[i];
    }
    out << "]]";
}

template <int N, int M>
inline mat<N, M> operator+(const mat<N, M> &a, const mat<N, M> &b)
{
    mat<N, M> out = new mat<N, M>();
    for (int i = 0; i < N; i++)
    {
        out[i] = a[i] + b[i];
    }
    return out;
}

template <int N, int M>
inline mat<N, M> operator-(const mat<N, M> &a, const mat<N, M> &b)
{
    mat<N, M> out = new mat<N, M>();
    for (int i = 0; i < N; i++)
    {
        out[i] = a[i] - b[i];
    }
    return out;
}

// Matrix multiply
inline mat2 operator*(const mat2 &a, const mat2 &b);

inline bool operator==(const mat2 &a, const mat2 &b)
{
    return a[0] == b[0] && a[1] == b[1];
}

inline bool operator!=(const mat2 &a, const mat2 &b)
{
    return !(a == b);
}

inline mat2 operator*(const mat2 &a, const double t)
{
    return mat2(a[0] * t, a[1] * t);
}

inline mat2 operator*(const double t, const mat2 &a)
{
    return a * t;
}

inline mat2 operator/(const mat2 &a, const double t)
{
    return a * (1 / t);
}

#endif