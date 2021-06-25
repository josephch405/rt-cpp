#include "mat4.h"

mat4 mat4::transpose() const
{
    return mat4(
        vec4(v[0][0], v[1][0], v[2][0], v[3][0]),
        vec4(v[0][1], v[1][1], v[2][1], v[3][1]),
        vec4(v[0][2], v[1][2], v[2][2], v[3][2]),
        vec4(v[0][3], v[1][3], v[2][3], v[3][3]));
}

mat4 operator*(const mat4 &a, const mat4 &b)
{
    mat4 bt = b.transpose();
    return mat4(vec4(a[0].dot(bt[0]), a[0].dot(bt[1]), a[0].dot(bt[2]), a[0].dot(bt[3])),
                vec4(a[1].dot(bt[0]), a[1].dot(bt[1]), a[1].dot(bt[2]), a[1].dot(bt[3])),
                vec4(a[2].dot(bt[0]), a[2].dot(bt[1]), a[2].dot(bt[2]), a[2].dot(bt[3])),
                vec4(a[3].dot(bt[0]), a[3].dot(bt[1]), a[3].dot(bt[2]), a[3].dot(bt[3])));
}

vec4 operator*(const mat4 &a, const vec4 &v)
{
    return vec4(a[0].dot(v), a[1].dot(v), a[2].dot(v), a[3].dot(v));
}
