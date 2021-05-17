add_subdirectory(pid_controller)
add_subdirectory(lqr_controller)
add_subdirectory(mpc)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()