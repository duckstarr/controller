cmake_minimum_required( VERSION 3.2 )
project( control_system )

find_package( Eigen3 REQUIRED )

# Build.
include_directories(
    include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_lib SHARED
  src/lqr_controller.cpp
  src/model_predictive_controller.cpp
  src/pid_controller.cpp
)

target_link_libraries(${PROJECT_NAME}_lib Eigen3::Eigen)

if(BUILD_EXAMPLES)
  # PID example.
  add_executable(${PROJECT_NAME}_pid_example example/pid.cpp)
  target_link_libraries(${PROJECT_NAME}_pid_example ${PROJECT_NAME}_lib)

  # LQR Example..
  add_executable(${PROJECT_NAME}_lqr_example example/lqr.cpp)
  target_link_libraries(${PROJECT_NAME}_lqr_example ${PROJECT_NAME}_lib)

  # MPC Example..
  add_executable(${PROJECT_NAME}_mpc_example example/mpc.cpp)
  target_link_libraries(${PROJECT_NAME}_mpc_example ${PROJECT_NAME}_lib)
endif()

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

INSTALL (DIRECTORY include/
  DESTINATION /usr/local/include
  FILES_MATCHING PATTERN "*.h*"
)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()