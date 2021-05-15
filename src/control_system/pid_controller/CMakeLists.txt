cmake_minimum_required( VERSION 3.2 )
project( pid_controller )

# Build.
include_directories(
  include
)

add_library(${PROJECT_NAME}_lib
  src/pid_controller.cpp
)

add_executable(${PROJECT_NAME}
  src/pid_controller.cpp
  example/pid.cpp
)

add_executable(${PROJECT_NAME}_test 
  test/test.cpp
)

target_link_libraries(${PROJECT_NAME}_lib
  ${CMAKE_THREAD_LIBS_INIT}
)

target_link_libraries(${PROJECT_NAME}
  ${PROJECT_NAME}_lib
)

target_link_libraries(${PROJECT_NAME}_test 
  ${GTEST_LIBRARIES}
  ${PROJECT_NAME}_lib
)

# Install.
install(TARGETS ${PROJECT_NAME}_lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)