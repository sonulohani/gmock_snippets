cmake_minimum_required(VERSION 3.0.0)
project(gmock_snippets VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
  # By default, GTest compiles on Windows in CRT static linkage mode. We use this
  # variable to force it into using the CRT in dynamic linkage (DLL), just as CPR
  # does.
  set(gtest_force_shared_crt ON CACHE BOOL "Force gtest to use the shared c runtime")
endif()

find_package(PkgConfig)
# pkg_search_module(GTEST REQUIRED gtest_main)
pkg_search_module(GMOCK REQUIRED gmock_main)

include(CTest)
enable_testing()

#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(gmock_snippets test_1.cpp main.cpp)
target_link_libraries(gmock_snippets ${GMOCK_LDFLAGS})
target_compile_options(gmock_snippets PUBLIC ${GMOCK_CFLAGS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
