load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")

cc_binary(
    name = "mainprog",
    srcs = ["main.cpp"], # the main application
    deps = [
        "//Func:functions" # library to use by main application
    ]
)