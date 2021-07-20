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
    vec<M> v[N];

    mat<N, M>()
    {
        init();
    };
    mat<N, M>(const double a[N][M])
    {
        init();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                v[i][j] = a[i][j];
            }
        }
    };
    mat<N, M>(vec<M> const a[N])
    {
        for (int i = 0; i < N; i++)
        {
            v[i] = a[i];
        }
    }
    // mat2(vec2 a, vec2 b) : v{a, b} {}

    mat<N, M> operator-() const
    {
        mat<N, M> m;
        for (int i = 0; i < N; i++)
        {
            m[i] = -v[i];
        }
        return m;
    };

    const vec<M> operator[](int i) const { return v[i]; }
    vec<M> &operator[](int i) { return v[i]; }

    mat<N, M> &operator+=(const mat<N, M> &m)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] += m[i];
        }
        return *this;
    };

    mat<N, M> &operator*=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] *= t;
        }
        return *this;
    };

    mat<N, M> &operator/=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            v[i] /= t;
        }
        return *this;
    };

    mat<M, N> transpose() const
    {
        mat<M, N> out;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                out[j][i] = v[i][j];
            }
        }
        return out;
    };

private:
    void init()
    {
        for (int i = 0; i < N; i++)
        {
            v[i] = vec<M>();
        }
    }
};

template <int N>
using sq_mat = mat<N, N>;

using mat3 = sq_mat<3>;
using mat4 = sq_mat<4>;

template <int N, int M>
inline std::ostream &operator<<(std::ostream &out, const mat<N, M> &m)
{
    out << "[[" << m[0];
    for (int i = 1; i < N; i++)
    {
        out << "],[" << m[i];
    }
    return out << "]]";
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
template <int N, int M, int J>
mat<N, J> operator*(const mat<N, M> &a, const mat<M, J> &b)
{
    mat<J, M> bt = b.transpose();
    mat<N, J> output = mat<N, J>();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < J; j++)
        {
            output[i][j] = a[i].dot(bt[j]);
        }
    }
    return output;
}

template <int N, int M>
inline bool operator==(const mat<N, M> &a, const mat<N, M> &b)
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

template <int N, int M>
inline bool operator!=(const mat<N, M> &a, const mat<N, M> &b)
{
    return !(a == b);
}

template <int N, int M>
inline mat<N, M> operator*(const mat<N, M> &a, const double t)
{
    return mat2(a[0] * t, a[1] * t);
}

template <int N, int M>
inline mat<N, M> operator*(const double t, const mat<N, M> &a)
{
    return a * t;
}

template <int N, int M>
inline mat<N, M> operator/(const mat<N, M> &a, const double t)
{
    return a * (1 / t);
}

#endif