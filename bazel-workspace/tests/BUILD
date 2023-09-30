load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")

cc_test(
    name = "test",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//Func:functions", # library to test
        "@googletest//:gtest_main"
    ],
)

