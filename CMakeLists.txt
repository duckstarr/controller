cmake_minimum_required( VERSION 3.2 )
project(controller LANGUAGES CXX C)

# Set C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( GTest REQUIRED )
find_package( Threads REQUIRED )

add_subdirectory(src)