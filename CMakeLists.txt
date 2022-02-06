
cmake_minimum_required(VERSION 3.20)
project(JhelperProject)

add_executable(output output/main.cpp output/main.cpp libs/collections/SegmentTree.h libs/collections/FendwickTree.h libs/collections/Counter.h
        libs/bits.h libs/io/Output.h libs/io/Input.h libs/graph/edges/BiEdge.h libs/graph/edges/BaseEdge.h libs/numbers/numbers.h libs/range/range.h  libs/collections/UnionFind.h)
add_executable(testrunner testrunner/main.cpp testrunner/main.cpp libs/range/range.h libs/collections/UnionFind.h)


target_precompile_headers(output PRIVATE bits/stdc++.h)
target_precompile_headers(testrunner PRIVATE bits/stdc++.h)

file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "libs/*.h")

add_executable(task ${TASKS} ${HEADERS})
target_precompile_headers(task PRIVATE bits/stdc++.h)

ADD_DEFINITIONS(-static -std=c++17 -Wall -Wextra -Wno-sign-compare -Wno-reorder -Wno-logical-op-parentheses)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)