#include <gtest/gtest.h>
// #include "vec3.h"
#include "vec.h"
#include "mat.h"
// #include "mat3.h"
// #include "mat4.h"

TEST(VecTests, Basics)
{
    double a[2]{1, 3};
    vec<2> v = vec<2>(a);
    a[0] = 10;
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 3);
}

TEST(Mat3Tests, Assign)
{
    double v[3][3] = {{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}};
    mat3 a = mat3(v);
    ASSERT_EQ(a[0][0], -3);
    ASSERT_EQ(a[1][2], -7);
    ASSERT_EQ(a[2][2], 1);
}

TEST(Mat3Tests, Equality)
{
    double _a[3][3] = {{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}};
    mat3 a = mat3(_a);
    double _b[3][3] = {{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}};
    mat3 b = mat3(_b);
    double _c[3][3] = {{-3, 5, 0}, {1, -3, -7}, {0, 1, 1}};
    mat3 c = mat3(_c);
    ASSERT_EQ(a, b);
    ASSERT_NE(a, c);
}

TEST(Mat4Tests, Assign)
{
    double _a[4][4] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 8, 7, 6},
                       {5, 4, 3, 2}};
    mat4 a = mat4(_a);
    ASSERT_EQ(a[0][0], 1);
    ASSERT_EQ(a[3][2], 3);
}

TEST(Mat4Tests, Equality)
{
    double _a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    double _b[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    double _c[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 8}, {5, 4, 3, 2}};
    mat4 a = mat4(_a);
    mat4 b = mat4(_b);
    mat4 c = mat4(_c);
    ASSERT_EQ(a, b);
    ASSERT_NE(a, c);
}

// TEST(Mat4Tests, MatrixMult)
// {
//     mat4 a = mat4({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}});
//     mat4 b = mat4({{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}});
//     mat4 c = mat4({{20, 22, 50, 48}, {44, 54, 114, 108}, {40, 58, 110, 102}, {16, 26, 46, 42}});
//     ASSERT_EQ(a * b, c);
// }

// TEST(Mat4Tests, MatrixVectorMult)
// {
//     mat4 a = mat4({{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}});
//     vec4 u = vec4({1, 2, 3, 1});
//     vec4 v = vec4({18, 24, 33, 1});
//     ASSERT_EQ(a * u, v);
// }
