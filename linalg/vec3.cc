#include "vec3.h"

vec3 vec3::normalize() const
{
  return *this / this->length();
}

double vec3::dot(const vec3 v) const
{
  return e[0] * v[0] + e[1] * v[1] + e[2] * v[2];
}