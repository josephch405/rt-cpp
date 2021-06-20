#include <gtest/gtest.h>
#include "sphere.h"

// Demonstrate some basic assertions.
TEST(SphereTests, XAxisNormal)
{
    sphere s = sphere();
    vec3 v = s.normal_at(point3(1, 0, 0));
    ASSERT_EQ(v, point3(1, 0, 0));
}

TEST(SphereTests, YAxisNormal)
{
    sphere s = sphere();
    vec3 v = s.normal_at(point3(0, 1, 0));
    ASSERT_EQ(v, point3(0, 1, 0));
}

TEST(SphereTests, ZAxisNormal)
{
    sphere s = sphere();
    vec3 v = s.normal_at(point3(0, 0, 1));
    ASSERT_EQ(v, point3(0, 0, 1));
}

TEST(SphereTests, TranslatedSphere)
{
    sphere s = sphere();
    s.center = point3(0, 1, 0);
    vec3 v = s.normal_at(point3(0, 1.70711, -0.70711));
    ASSERT_EQ(v, point3(0, 0.70711, -0.70711));
}