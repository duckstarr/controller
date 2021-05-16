cmake_minimum_required( VERSION 3.2 )
project( control_system )

add_subdirectory(pid_controller)
add_subdirectory(lqr_controller)
add_subdirectory(mpc)

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    pid_controller/include
    lqr_controller/include
    mpc/include
)

if(BUILD_TESTS)
    # PID Test.
    add_executable(${PROJECT_NAME}_pid_test test/pid_test.cpp)
    target_link_libraries(${PROJECT_NAME}_pid_test
        ${GTEST_LIBRARIES}
        pid_controller_lib
        pthread
    )
endif()

if(BUILD_EXAMPLES)
    # PID Example.
    add_executable(${PROJECT_NAME}_pid_example example/pid.cpp)
    target_link_libraries(${PROJECT_NAME}_pid_example pid_controller_lib)

    # LQR Example.
    add_executable(${PROJECT_NAME}_lqr_example example/lqr.cpp)
    target_link_libraries(${PROJECT_NAME}_lqr_example lqr_controller_lib)

    # MPC Example.
    add_executable(${PROJECT_NAME}_mpc_example example/mpc.cpp)
    target_link_libraries(${PROJECT_NAME}_mpc_example model_predictive_controller_lib)
endif()