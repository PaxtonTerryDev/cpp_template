cmake_minimum_required(VERSION 3.28)
project(cpp_template)

set(CMAKE_CXX_STANDARD 20)

# Include headers for your own project
include_directories(include)

add_executable(cpp_template main.cpp
        src/my_project/test_class.cpp
        include/my_project/test_class.h
)

include(FetchContent)

# Quant Config (personal)
FetchContent_Declare(
        quant_config
        GIT_REPOSITORY https://github.com/PaxtonTerryDev/quant-config
        GIT_TAG v1.0.2
)
FetchContent_MakeAvailable(quant_config)

# ✅ This applies include path + definitions to cpp_template
target_link_libraries(cpp_template PRIVATE quant_config)

# Catch2 (for testing)
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)

add_executable(unit_tests tests/test_main.cpp)
target_include_directories(unit_tests PRIVATE ${catch2_SOURCE_DIR}/src)
target_link_libraries(unit_tests Catch2::Catch2WithMain)
