cc_library(
    name = "linalg",
    hdrs = [
        "mat.h",
        "vec.h",
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
