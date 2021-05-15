cmake_minimum_required( VERSION 3.2 )
project( model_predictive_controller  )

find_package( Eigen3 REQUIRED )

# Build.
include_directories(
    include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_lib
  src/model_predictive_controller.cpp
)

add_executable(${PROJECT_NAME}
  src/model_predictive_controller.cpp
  example/mpc.cpp
)

target_link_libraries(${PROJECT_NAME}_lib
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}
  ${PROJECT_NAME}_lib
)

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)