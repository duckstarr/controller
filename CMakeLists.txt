cmake_minimum_required( VERSION 3.2 )
project(controller LANGUAGES CXX C)

option(BUILD_TESTS "Test controllers and state estimators" OFF)
option(BUILD_EXAMPLES "Build controller and state estimator examples" OFF)

# Set C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( GTest REQUIRED )
find_package( Eigen3 REQUIRED )
find_package( Threads REQUIRED )

add_subdirectory(src)