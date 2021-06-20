load("@rules_cc//cc:defs.bzl", "cc_test")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "camera",
        "color",
        "hittable",
        "hittable_list",
        "ray",
        "sphere",
        "utils",
        "//linalg",
    ],
)

cc_library(
    name = "color",
    hdrs = ["color.h"],
)

cc_library(
    name = "camera",
    hdrs = ["camera.h"],
)

cc_library(
    name = "ray",
    hdrs = ["ray.h"],
    deps = [
        "//linalg",
    ],
)

cc_library(
    name = "utils",
    hdrs = ["utils.h"],
)

cc_library(
    name = "hittable_list",
    hdrs = ["hittable_list.h"],
)

cc_library(
    name = "hittable",
    hdrs = ["hittable.h"],
    deps = ["ray"],
)

cc_library(
    name = "sphere",
    srcs = ["sphere.cc"],
    hdrs = ["sphere.h"],
    deps = [
        "hittable",
        "//linalg",
    ],
)

cc_test(
    name = "sphere_test",
    size = "small",
    srcs = ["sphere_test.cc"],
    deps = [
        "sphere",
        "@com_google_googletest//:gtest_main",
    ],
)
