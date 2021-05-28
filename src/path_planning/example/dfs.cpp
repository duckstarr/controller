/**
 * @file dfs.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/path_planning/path_planning_dfs_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 21 allocs, 21 frees, 74,212 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

    for(unsigned int i = 0; i < path.size(); i++)
    {
        std::cout << "Path: " << path.at(i) << std::endl;
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