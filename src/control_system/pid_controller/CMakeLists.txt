cmake_minimum_required( VERSION 3.2 )
project( pid_controller )

# Build.
include_directories(
  include
)

add_library(${PROJECT_NAME}_lib
  src/pid_controller.cpp
)

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)