# gtest-bazel-template  
A sample template for a Bazel workspace using Google Test.

This example just contains the basic workspace structure with samples of `Bazel` related configuration files.  
You should be easily able adapt this example for your own working solution.

## WORKSPACE structure 
The sample workspace directory structure may look like 

```
.
├── Func
│   ├── BUILD
│   ├── func.cpp
│   └── func.h
├── WORKSPACE
├── external
│   └── gmock.BUILD
├── main
│   ├── BUILD
│   └── main.cpp
└── tests
    ├── BUILD
    └── tests.cpp
```

## Building steps

First lets build the main program.

```
-> % bazel build //main:testprog
INFO: Analyzed target //main:testprog (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //main:testprog up-to-date:
  bazel-bin/main/testprog
INFO: Elapsed time: 0.110s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
```

Now lets build the test program. You need to set standard to c++14 at minimum to work with google test.

```
-> % bazel build --cxxopt='-std=c++14'  //tests:test                                        
INFO: Build option --cxxopt has changed, discarding analysis cache.
INFO: Analyzed target //tests:test (3 packages loaded, 448 targets configured).
INFO: Found 1 target...
INFO: From Linking tests/test:
ld: warning: ignoring duplicate libraries: '-lc++'
Target //tests:test up-to-date:
  bazel-bin/tests/test
INFO: Elapsed time: 1.733s, Critical Path: 1.58s
INFO: 9 processes: 1 internal, 8 darwin-sandbox. 
```

A better way to working with a workspace is to let Bazel find all available tests and rund them automatically before building.

```
-> % bazel query //... | xargs bazel test --cxxopt='-std=c++14'
Loading: 0 packages loaded
Loading: 0 packages loaded
INFO: Analyzed 3 targets (0 packages loaded, 113 targets configured).
INFO: Found 2 targets and 1 test target...
INFO: Elapsed time: 0.120s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
//tests:test                                                    PASSED 
```

## Example of test run

It is possible to build and afterwards run a test program manually. But it is also possible to find all possible test cases, maybe from several test programs, an run them automatically. 

### Run specific tests on their own.

As written above it is possible to find an run all tests cases automatically.

For an output in more detail one needs to run the specific test programm on its own.

```
-> % bazel-bin/tests/test                           
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from FunctionTests
[ RUN      ] FunctionTests.AddTwoPositives
[       OK ] FunctionTests.AddTwoPositives (0 ms)
[ RUN      ] FunctionTests.MultiplyTwoPositivs
[       OK ] FunctionTests.MultiplyTwoPositivs (0 ms)
[----------] 2 tests from FunctionTests (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
```

## Further information

- [Building programs with Bazel](https://bazel.build/run/build)
- [Testing](https://bazel.build/rules/testing)
- [Workspace rules](https://bazel.build/reference/be/workspace)
- [Workspaces, packages, and targets](https://bazel.build/concepts/build-ref#workspaces)
- [Commands and Options](https://bazel.build/docs/user-manual#bazelrc)