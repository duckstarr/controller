/**
 * @file dijkstra_node.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/path_planning/path_planning_dijkstra_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 49 allocs, 49 frees, 75,648 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

#include <dijkstra.hpp>
#include <memory>
#include <iostream>

using namespace path_planning;

int main()
{
    auto ptr = std::unique_ptr<dijkstra>(new dijkstra(9));

    ptr->addEdge(0, 1, 4);
    ptr->addEdge(0, 7, 8);
    ptr->addEdge(1, 2, 8);
    ptr->addEdge(1, 7, 11);
    ptr->addEdge(2, 3, 7);
    ptr->addEdge(2, 8, 2);
    ptr->addEdge(2, 5, 4);
    ptr->addEdge(3, 4, 9);
    ptr->addEdge(3, 5, 14);
    ptr->addEdge(4, 5, 10);
    ptr->addEdge(5, 6, 2);
    ptr->addEdge(6, 7, 1);
    ptr->addEdge(6, 8, 6);
    ptr->addEdge(7, 8, 7);

    int source = 0;
    int target = 5;

    std::vector<double> distance = ptr->getShortestDistance(source);
    std::vector<int> path = ptr->getShortestPath(source, target);

    std::cout << "Shortest distance from source to target: " << std::endl;
    for(auto i = distance.begin(); i != distance.end(); i++)
    {
        std::cout << "target: " << i - distance.begin() << "\tdistance: " << *i << std::endl;
    }

    std::cout << "Shortest path to take from source to target: " << std::endl;
    std::cout << "source: " << source << "\ttarget: " << target << std::endl;
    for(auto it = path.begin(); it != path.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    /**
     * @brief !Output
     * Shortest distance from source to target: 
     * target: 0       distance: 0
     * target: 1       distance: 4
     * target: 2       distance: 12
     * target: 3       distance: 19
     * target: 4       distance: 21
     * target: 5       distance: 11
     * target: 6       distance: 9
     * target: 7       distance: 8
     * target: 8       distance: 14
     * Shortest path to take from source to target: 
     * source: 0       target: 5
     * 5
     * 6
     * 7
     */

    return EXIT_SUCCESS;
}