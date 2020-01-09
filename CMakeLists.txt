cmake_minimum_required(VERSION 3.13)
project(self_svd_implementation)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(catch)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(tests tests.cpp power_method.cpp power_method.h catch_main.cpp)
#add_executable(tests tests.cpp catch_main.cpp )
add_executable(self_svd_implementation main.cpp power_method.cpp power_method.h)
add_executable(power_method power_method.cpp power_method.h)
target_link_libraries (power_method PUBLIC Eigen3::Eigen)
target_link_libraries (self_svd_implementation PUBLIC Eigen3::Eigen)
target_link_libraries(tests PUBLIC catch PUBLIC Eigen3::Eigen)
