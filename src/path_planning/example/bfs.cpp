/**
 * @file bfs.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/path_planning/path_planning_bfs_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 22 allocs, 22 frees, 74,756 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

#include <breadth_first_search.hpp>
#include <memory>
#include <iostream>
#include <vector>

using namespace path_planning;

int main()
{
    int V = 8; // number of vertercies.
    int source = 0;
    int destination = 7;

    auto ptr = std::unique_ptr<BFS>(new BFS(V, source));

    ptr->addEdge(0, 1);
    ptr->addEdge(0, 3);
    ptr->addEdge(1, 2);
    ptr->addEdge(3, 4);
    ptr->addEdge(3, 7);
    ptr->addEdge(4, 5);
    ptr->addEdge(4, 6);
    ptr->addEdge(4, 7);
    ptr->addEdge(5, 6);
    ptr->addEdge(6, 7);

    ptr->startBFS(source);
    std::vector<int> path = ptr->getShortestPath(destination);

    std::cout << "Shortest path from node 0 - 7" << std::endl;
    for(unsigned int i = 0; i < path.size(); i++)
    {
        std::cout << path.at(i) << std::endl;
    }

    /**
     * @brief !Output
     * Shortest path from node 0 - 7
     * 7
     * 3
     * 0
     */

    return EXIT_SUCCESS;
}