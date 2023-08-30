cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(statistics statistics.cpp IStatistics.hpp 
                          Average.hpp Max.hpp Min.hpp 
                          Percentile.hpp Percentile.cpp 
                          StandardDeviation.hpp StandardDeviation.cpp)

set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(statistics PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(statistics PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
