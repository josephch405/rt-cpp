#include "vec4.h"

vector vector::normalize()
{
  return *this / this->length();
}

double vec4::dot(const vec4 v) const
{
  return e[0] * v[0] + e[1] * v[1] + e[2] * v[2] + e[3] * v[3];
}
