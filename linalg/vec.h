#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>

using std::sqrt;

template <int N>
class vec
{
public:
    double e[N]{0};
    vec<N>() : e{0} {}
    vec<N>(const double arr[N])
    {
        for (int i = 0; i < N; i++)
        {
            e[i] = arr[i];
        }
    }

    vec<N> operator-() const
    {
        vec<N> output = *this;
        for (int i = 0; i < N; i++)
        {
            output[i] = -output[i];
        }
        return output;
    }
    const double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec<N> &operator+=(const vec<N> &v)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] += v[i];
        }
        return *this;
    };

    vec<N> &operator*=(const double t)
    {
        for (int i = 0; i < N; i++)
        {
            e[i] *= t;
        }
        return *this;
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
        double out = 0;
        for (int i = 0; i < N; i++)
        {
            out += e[i] * v[i];
        }
        return out;
    };
};

template <int N>
std::ostream &operator<<(std::ostream &out, const vec<N> &v)
{
    out << '[' << v[0];
    for (int i = 1; i < N; i++)
    {
        out << ',' << v[i];
    }
    return out << ']';
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
inline vec<N> operator*(const vec<N> &v, const double t)
{
    vec<N> out;
    for (int i = 0; i < N; i++)
    {
        out[i] = v[i] * t;
    }
    return out;
}

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

using vec2 = vec<2>;
using vec3 = vec<3>;
using vec4 = vec<4>;

using point = vec3;
using vector = vec3;

inline vec3 make_vec3(double a, double b, double c)
{
    double v[3]{a, b, c};
    return vec3(v);
}

inline point make_point(double a, double b, double c)
{
    return make_vec3(a, b, c);
}

inline vector make_vector(double a, double b, double c)
{
    return make_vec3(a, b, c);
}

inline vec3 vec4_to_vec3(vec4 v)
{
    vec3 output;
    output[0] = v[0];
    output[1] = v[1];
    output[2] = v[2];
    return output;
}

template <int N>
inline vec<N> unit_vector(vec<N> v)
{
    return v / v.length();
}

#endif