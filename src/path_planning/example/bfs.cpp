/**
 * @file bfs.cpp
 * @brief Find the shortest path from a source to other vertices in an unweighted graph.
 * 
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