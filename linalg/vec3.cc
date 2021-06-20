#include "vec3.h"

vec3 vec3::normalize()
{
  return *this / this->length();
}