cmake_minimum_required(VERSION 3.26.4)

# Enable group projects in folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(algo-visualizer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========================================================
# GTEST

include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_property(TARGET gmock PROPERTY FOLDER "gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "gtest")
set_property(TARGET gtest PROPERTY FOLDER "gtest")
set_property(TARGET gtest_main PROPERTY FOLDER "gtest")

# ========================================================

add_library("${PROJECT_NAME}" STATIC
    # Source files
    src/search_algos.cpp

    # Header files
    include/search_algos.h
)

#target_compile_definitions("${PROJECT_NAME}" PRIVATE PROJECT_NAMESPACE=${PROJECT_NAMEspace})

add_executable("${PROJECT_NAME}-main"
    # Source files
    src/main.cpp
)

# gtest

enable_testing()

add_executable("${PROJECT_NAME}-test"
    # Source files
    test/smoke_tests.cpp
)

target_link_libraries("${PROJECT_NAME}-test"
    gtest_main
    "${PROJECT_NAME}"
)

include(GoogleTest)
gtest_discover_tests("${PROJECT_NAME}-test")