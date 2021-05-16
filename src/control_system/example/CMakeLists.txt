cmake_minimum_required( VERSION 3.2 )
project( control_system_example )

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ../pid_controller/include
    ../lqr_controller/include
    ../mpc/include
)

# PID Example.
add_executable(${PROJECT_NAME}_pid_example pid.cpp)
target_link_libraries(${PROJECT_NAME}_pid_example pid_controller_lib)

# LQR Example.
add_executable(${PROJECT_NAME}_lqr_example lqr.cpp)
target_link_libraries(${PROJECT_NAME}_lqr_example lqr_controller_lib)

# MPC Example.
add_executable(${PROJECT_NAME}_mpc_example mpc.cpp)
target_link_libraries(${PROJECT_NAME}_mpc_example model_predictive_controller_lib)