cmake_minimum_required( VERSION 3.2 )
project( pid_controller )

# Build.
include_directories(
  include
)

add_library(${PROJECT_NAME}_lib SHARED
  src/pid_controller.cpp
)

if(BUILD_EXAMPLES)
  # PID Example.
  add_executable(${PROJECT_NAME}_example src/pid.cpp)
  target_link_libraries(${PROJECT_NAME}_example ${PROJECT_NAME}_lib)
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