#include "mat.h"

template <int N, int M>
mat<N, M>::mat(double a[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            v[i][j] = a[i][j];
        }
    }
}

template <int N, int M>
mat<N, M> mat<N, M>::operator-() const
{
    mat<N><M> m;
    for (int i = 0; i < N; i++)
    {
        m[i] = -v[i];
    }
    return m;
}

template <int N, int M>
mat<M, N> mat<N, M>::transpose() const
{
    mat<M, N> out;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            out[j][i] = e[i][j];
        }
    }
    return out;
}

inline mat3 operator*(const mat3 &a, const mat3 &b)
{
    mat3 bt = b.transpose();
    return mat3(vec3(a[0].dot(bt[0]), a[0].dot(bt[1]), a[0].dot(bt[2])),
                vec3(a[1].dot(bt[0]), a[1].dot(bt[1]), a[1].dot(bt[2])),
                vec3(a[2].dot(bt[0]), a[2].dot(bt[1]), a[2].dot(bt[2])));
}