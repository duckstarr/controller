cmake_minimum_required( VERSION 3.2 )
project( signal_processing_example )

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ../kalman_filter/include
    ../low_pass_filter/include
)

# Kalman Filter example.
add_executable(${PROJECT_NAME}_kf_example kalman.cpp)
target_link_libraries(${PROJECT_NAME}_kf_example kalman_filter_lib)

# Low-Pass filter example.
add_executable(${PROJECT_NAME}_lpf_example lpf.cpp)
target_link_libraries(${PROJECT_NAME}_lpf_example low_pass_filter_lib)