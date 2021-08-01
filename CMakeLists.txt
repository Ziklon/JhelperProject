cmake_minimum_required(VERSION 2.8.4)
project(JhelperProject)

add_executable(output output/main.cpp output/main.cpp libs/collections/SegmentTree.h libs/collections/FendwickTree.h libs/collections/Counter.h
        libs/bits.h libs/io/Output.h libs/io/Input.h libs/graph/edges/BiEdge.h libs/graph/edges/BaseEdge.h libs/numbers/numbers.h)
add_executable(testrunner testrunner/main.cpp testrunner/main.cpp)


file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "libs/*.h")

add_executable(task ${TASKS} ${HEADERS})

ADD_DEFINITIONS(-static -std=c++17 -Wall -Wextra -Wno-sign-compare -Wno-reorder -Wno-logical-op-parentheses)

set_target_properties(task PROPERTIES LINKER_LANGUAGE CXX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ftrapping-math -g3 -gfull -ggdb -fno-inline-functions -fno-unroll-loops -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -DLOCAL -fsanitize=undefined -fsanitize-undefined-trap-on-error -fno-sanitize-recover=all -fstack-protector -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O0 -ftrapping-math -g3 -gfull -ggdb -fno-inline-functions -fno-unroll-loops -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -DLOCAL -fsanitize-undefined-trap-on-error -fno-sanitize-recover=all -fstack-protector -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DLOCAL_RELEASE")
