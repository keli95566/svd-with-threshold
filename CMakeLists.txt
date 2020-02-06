cmake_minimum_required(VERSION 3.9)
project(self_svd_implementation)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(catch)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)


add_executable(tests tests/tests.cpp cylib/power_method.cpp cylib/power_method.h tests/catch_main.cpp)

add_executable(self_svd_implementation)
target_sources(self_svd_implementation PRIVATE main.cpp cylib/power_method.cpp cylib/power_method.h)

target_link_libraries (self_svd_implementation PUBLIC Eigen3::Eigen)
target_link_libraries(tests PUBLIC catch PUBLIC Eigen3::Eigen)
