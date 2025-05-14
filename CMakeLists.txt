cmake_minimum_required(VERSION 3.31)
project(cpp_template)

set(CMAKE_CXX_STANDARD 20)

# Include headers
include_directories(include)

add_executable(cpp_template main.cpp)

include(FetchContent)

# Download Catch2
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)

# Test executable
add_executable(unit_tests tests/test_main.cpp)

# This tells CLion's indexer where to find <catch2/catch.hpp>
target_include_directories(unit_tests PRIVATE ${catch2_SOURCE_DIR}/src)

target_link_libraries(unit_tests Catch2::Catch2WithMain)