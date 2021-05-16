cmake_minimum_required( VERSION 3.2 )
project( low_pass_filter )

# Build.
include_directories(
  include
)

add_library(${PROJECT_NAME}_lib
  src/low_pass_filter.cpp
)

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)