cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(LC)

include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE PROBLEM_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "problems/*.cpp")
file(GLOB_RECURSE COMMON_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "common/*.cpp")
add_executable(LC
    ${PROBLEM_SOURCES}
    ${COMMON_SOURCES}
)

# Enable warnings
if(MSVC)
    target_compile_options(LC PRIVATE /W4 /WX)
else()
    target_compile_options(LC PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

enable_testing()

### GoogleTest Config from https://github.com/google/googletest/tree/master/googletest
    include(FetchContent)
    FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    # [20241230 Andy] 86add13493e5c881d7e4ba77fb91c1f57752b3a4 = release-1.12.1
    URL https://github.com/google/googletest/archive/86add13493e5c881d7e4ba77fb91c1f57752b3a4.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    include(GoogleTest)
### END GoogleTest Config

# Link our exe's main to google test runner.
target_link_libraries(LC gtest_main)

# Instead of GoogleTest's recommendation use the option provided on CMake
# https://cmake.org/cmake/help/latest/module/GoogleTest.html
# This allows running tests and seeing results via CMake. However, it requires
# a process launch for each test, adding overhead.
#gtest_discover_tests(LC DISCOVERY_MODE PRE_TEST)
add_test(NAME LCTTest COMMAND LC)
