add_subdirectory(kalman_filter)
add_subdirectory(low_pass_filter)

if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif()