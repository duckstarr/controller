cmake_minimum_required( VERSION 3.2 )
project( path_planning )

# Build.
include_directories(
    include
)

add_library(${PROJECT_NAME}_lib SHARED
  src/breadth_first_search.cpp
  src/depth_first_search.cpp
  src/dijkstra.cpp
)

if(BUILD_EXAMPLES)
  # BFS Example.
  add_executable(${PROJECT_NAME}_bfs_example example/bfs.cpp)
  target_link_libraries(${PROJECT_NAME}_bfs_example ${PROJECT_NAME}_lib)

  # DFS Example.
  add_executable(${PROJECT_NAME}_dfs_example example/dfs.cpp)
  target_link_libraries(${PROJECT_NAME}_dfs_example ${PROJECT_NAME}_lib)

  # Dijkstra Example.
  add_executable(${PROJECT_NAME}_dijkstra_example example/dijkstra_node.cpp)
  target_link_libraries(${PROJECT_NAME}_dijkstra_example ${PROJECT_NAME}_lib)
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