#include "mat3.h"

mat3 mat3::transpose() const
{
  return mat3(
      vec3(v[0][0], v[1][0], v[2][0]),
      vec3(v[0][1], v[1][1], v[2][1]),
      vec3(v[0][2], v[1][2], v[2][2]));
}

inline mat3 operator*(const mat3 &a, const mat3 &b)
{
  mat3 bt = b.transpose();
  return mat3(vec3(a[0].dot(bt[0]), a[0].dot(bt[1]), a[0].dot(bt[2])),
              vec3(a[1].dot(bt[0]), a[1].dot(bt[1]), a[1].dot(bt[2])),
              vec3(a[2].dot(bt[0]), a[2].dot(bt[1]), a[2].dot(bt[2])));
}