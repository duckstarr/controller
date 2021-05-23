/**
 * @file bfs.cpp
 * @brief Find the shortest path from a source to other vertices in an unweighted graph.
 * 
 */

#include "breadth_first_search.h"
#include <iostream>
#include <vector>

using namespace path_planning;

int main()
{
    int V = 8; // number of vertercies.
    int source = 0;
    int destination = 7;

    BFS BFS(V, source);

    BFS.addEdge(0, 1);
    BFS.addEdge(0, 3);
    BFS.addEdge(1, 2);
    BFS.addEdge(3, 4);
    BFS.addEdge(3, 7);
    BFS.addEdge(4, 5);
    BFS.addEdge(4, 6);
    BFS.addEdge(4, 7);
    BFS.addEdge(5, 6);
    BFS.addEdge(6, 7);

    BFS.startBFS(source);
    std::vector<int> path = BFS.getShortestPath(destination);

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