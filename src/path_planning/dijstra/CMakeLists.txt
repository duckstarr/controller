cmake_minimum_required( VERSION 3.2 )
project( dijstra )

# Build.
include_directories(
    include
)

add_library(${PROJECT_NAME}_lib SHARED
  src/dijstra.cpp
)

if(BUILD_EXAMPLES)
  # MPC Example.
  add_executable(${PROJECT_NAME}_example src/dijstra_node.cpp)
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