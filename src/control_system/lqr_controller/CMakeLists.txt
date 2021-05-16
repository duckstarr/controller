cmake_minimum_required( VERSION 3.2 )
project( lqr_controller )

# Build.
include_directories(
    include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_lib
  src/lqr_controller.cpp
)

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)