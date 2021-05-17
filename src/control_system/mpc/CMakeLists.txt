cmake_minimum_required( VERSION 3.2 )
project( model_predictive_controller  )

# Build.
include_directories(
    include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_lib SHARED
  src/model_predictive_controller.cpp
)

target_link_libraries(${PROJECT_NAME}_lib Eigen3::Eigen)

if(BUILD_EXAMPLES)
  # MPC Example.
  add_executable(${PROJECT_NAME}_example src/mpc.cpp)
  target_link_libraries(${PROJECT_NAME}_example ${PROJECT_NAME}_lib)
endif()

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  EXPORT  ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

INSTALL (DIRECTORY include/
  DESTINATION /usr/local/include
  FILES_MATCHING PATTERN "*.h*"
)