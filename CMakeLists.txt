project(tls_test)
cmake_minimum_required(VERSION 3.16)
add_library(ut INTERFACE)
target_include_directories(ut INTERFACE include/)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} my_test.cpp ${SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED gmpxx)
include_directories(${gmp_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${gmp_LIBRARIES} ut)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
