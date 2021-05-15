cmake_minimum_required( VERSION 3.2 )
project( low_pass_filter )

# Build.
include_directories(
  include
)

add_library(${PROJECT_NAME}_lib
  src/low_pass_filter.cpp
)

add_executable(${PROJECT_NAME}
  src/low_pass_filter.cpp
  example/lpf.cpp
)

target_link_libraries(${PROJECT_NAME}_lib
  ${CMAKE_THREAD_LIBS_INIT}
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