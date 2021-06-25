cc_library(
    name = "linalg",
    srcs = [
        "mat3.cc",
        "mat4.cc",
        "vec3.cc",
        "vec4.cc",
    ],
    hdrs = [
        "mat3.h",
        "mat4.h",
        "vec3.h",
        "vec4.h",
    ],
    visibility = ["//:__pkg__"],
)

cc_test(
    name = "linalg_test",
    size = "small",
    srcs = ["mat_test.cc"],
    deps = [
        "linalg",
        "@com_google_googletest//:gtest_main",
    ],
)
