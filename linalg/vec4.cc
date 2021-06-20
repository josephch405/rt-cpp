#include "vec4.h"

vector vector::normalize()
{
  return *this / this->length();
}
