cmake_minimum_required( VERSION 3.2 )
project( control_system_test )

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ../pid_controller/include
)

# PID Test.
add_executable(${PROJECT_NAME}_pid_test pid_test.cpp)
target_link_libraries(${PROJECT_NAME}_pid_test
    ${GTEST_LIBRARIES}
    pid_controller_lib
    pthread
)