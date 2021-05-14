cmake_minimum_required( VERSION 3.2 )
project(controller LANGUAGES CXX C)

# Set C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( GTest REQUIRED )
find_package( Threads REQUIRED )


find_package( Eigen3 REQUIRED ) #TODO: Add this to better controller.

# Build.
include_directories(${PROJECT_NAME}
    {EIGEN3_INCLUDE_DIR}
) #TODO: Add this to better controller.

add_subdirectory(src)