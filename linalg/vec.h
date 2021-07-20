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

    vec<N> &operator+=(const vec<N> &v)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] += v[i];
        }
        return this;
    };

    vec<N> &operator*=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= t;
        }
        return this;
    };

    vec<N> &operator/=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] /= t;
        }
        return this;
    };

    double length() const
    {
        return sqrt(length_squared());
    }

    double length_squared() const
    {
        double s = 0;
        for (int i = 0; i < N; i++)
        {
            s += e[i] * e[i];
        }
        return s;
    }

    vec<N> normalize() const
    {
        return *this / this->length();
    };

    double dot(const vec<N> v) const
    {
        return e[0] * v[0] + e[1] * v[1];
    };
};

template <int N>
std::ostream &operator<<(std::ostream &out, const vec<N> &v)
{
    out << '[';
    for (int i = 0; i < N - 1; i++)
    {
        out << v[0] << ',';
    }
    return out << v[N - 1] << ']';
};

template <int N>
vec<N> operator+(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] + w[i];
    }
    return result;
};

template <int N>
vec<N> operator-(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] - w[i];
    }
    return result;
};

template <int N>
vec<N> operator*(const vec<N> &v, const vec<N> &w)
{
    vec<N> result = vec<N>();
    for (int i = 0; i < N; i++)
    {
        result[i] = v[i] * w[i];
    }
    return result;
};

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