/**
 * @file dfs.cpp
 * @brief A recursive implementation of DFS
 * 
 */

#include <depth_first_search.hpp>
#include <memory>
#include <vector>
#include <iostream>

using namespace path_planning;

int main()
{
    auto ptr = std::unique_ptr<DFS>(new DFS(4));

    ptr->addEdge(0, 1);
    ptr->addEdge(0, 2);
    ptr->addEdge(1, 2);
    ptr->addEdge(1, 3);
    ptr->addEdge(2, 0);
    ptr->addEdge(3, 3);

    auto path = ptr->startDFS(2);

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