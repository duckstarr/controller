/**
 * @file dfs.cpp
 * @brief A recursive implementation of DFS
 * 
 */

#include "depth_first_search.h"
#include <vector>
#include <iostream>

using namespace path_planning;

int main()
{
    DFS DFS(4);

    DFS.addEdge(0, 1);
    DFS.addEdge(0, 2);
    DFS.addEdge(1, 2);
    DFS.addEdge(1, 3);
    DFS.addEdge(2, 0);
    DFS.addEdge(3, 3);

    auto path = DFS.startDFS(2);

    for(unsigned int i = 0; i < path->size(); i++)
    {
        std::cout << "Path: " << path->at(i) << std::endl;
    }

    /**
     * @brief !Output.
     * Path: 2
     * Path: 0
     * Path: 1
     * Path: 3
     */

    return EXIT_SUCCESS;
}