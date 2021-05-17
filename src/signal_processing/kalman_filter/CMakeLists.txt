cmake_minimum_required( VERSION 3.2 )
project( kalman_filter )

find_package( Eigen3 REQUIRED )

# Build.
include_directories(
    include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_lib SHARED
  src/kalman_filter.cpp
)

target_link_libraries(${PROJECT_NAME}_lib Eigen3::Eigen)

if(BUILD_EXAMPLES)
  # Kalman Filter example.
  add_executable(${PROJECT_NAME}_example src/kalman.cpp)
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