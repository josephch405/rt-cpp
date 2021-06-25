#include <gtest/gtest.h>
#include "vec3.h"
#include "mat3.h"

// Demonstrate some basic assertions.
TEST(Mat3Tests, Assign)
{
    mat3 a = mat3({{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}});
    ASSERT_EQ(a[0][0], -3);
    ASSERT_EQ(a[1][2], -7);
    ASSERT_EQ(a[2][2], 1);
}

TEST(Mat3Tests, Equality)
{
    mat3 a = mat3({{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}});
    mat3 b = mat3({{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}});
    mat3 c = mat3({{-3, 5, 0}, {1, -3, -7}, {0, 1, 1}});
    ASSERT_EQ(a, b);
    ASSERT_NE(a, c);
}
