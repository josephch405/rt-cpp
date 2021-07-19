#include "vec.h"

template <int N>
vec<N> &vec<N>::operator+=(const vec<N> &v)
{
    for (int i = 0; i < N; i++)
    {
        e[i] += v[i];
    }
    return this;
}

template <int N>
vec<N> &vec<N>::operator*=(const double t)
{
    for (int i = 0; i < N; i++)
    {
        e[i] *= t;
    }
    return this;
}

template <int N>
vec<N> &vec<N>::operator/=(const double t)
{
    for (int i = 0; i < N; i++)
    {
        e[i] /= t;
    }
    return this;
}

template <int N>
inline std::ostream &operator<<(std::ostream &out, const vec<N> &v)
{
    out << '[';
    for (int i = 0; i < N - 1; i++)
    {
        out << v[0] << ',';
    }
    return out << v[N - 1] << ']';
}

template <int N>
inline vec<N> operator+(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = new vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] + w[i];
    }
    return result;
}

template <int N>
inline vec<N> operator-(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = new vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] - w[i];
    }
    return result;
}

template <int N>
inline vec<N> operator*(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = new vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] * w[i];
    }
    return result;
}

template <int N>
double vec<N>::length_squared() const
{
    double s = 0;
    for (int i = 0; i < N; i++)
    {
        s += e[i] * e[i];
    }
    return s;
}

template <int N>
vec<N> vec<N>::normalize() const
{
    return *this / this->length();
}

template <int N>
double vec<N>::dot(const vec<N> v) const
{
    return e[0] * v[0] + e[1] * v[1];
}