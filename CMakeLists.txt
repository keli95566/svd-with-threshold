cmake_minimum_required(VERSION 3.9)
project(self_svd_implementation)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(catch)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

set(eigen_dir "/usr/include/eigen3/Eigen/")

add_executable(tests tests.cpp power_method.cpp power_method.h catch_main.cpp)
#add_executable(tests tests.cpp catch_main.cpp )
add_executable(self_svd_implementation)
target_sources(self_svd_implementation PRIVATE main.cpp power_method.cpp power_method.h)
target_include_directories(self_svd_implementation PUBLIC eigen_dir )
add_executable(power_method power_method.cpp power_method.h)
target_link_libraries (power_method PUBLIC Eigen3::Eigen)
target_link_libraries (self_svd_implementation PUBLIC Eigen3::Eigen)
target_link_libraries(tests PUBLIC catch PUBLIC Eigen3::Eigen)
