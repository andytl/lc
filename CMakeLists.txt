cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)

# set the project name
project(LC)

include_directories("${PROJECT_SOURCE_DIR}")

### GoogleTest Config from https://github.com/google/googletest/tree/master/googletest
    # Download and unpack googletest at configure time
    configure_file(CMakeLists.txt.gtest.in ${CMAKE_CURRENT_BINARY_DIR}/googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    # Prevent overriding the parent project's compiler/linker
    # settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                    EXCLUDE_FROM_ALL)

    # The gtest/gtest_main targets carry header search path
    # dependencies automatically when using CMake 2.8.11 or
    # later. Otherwise we have to add them here ourselves.
    if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
    endif()
### END GoogleTest Config


file(GLOB_RECURSE PROBLEM_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "problems/*.cpp")
add_executable(LC
    ${PROBLEM_SOURCES}
    common/common.cpp
)
# Enable warnings for LC
if(MSVC)
    target_compile_options(LC PRIVATE /W4 /WX)
else()
    target_compile_options(LC PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Link our exe's main to google test runner.
target_link_libraries(LC gtest_main)
