/**
 * @file dijkstra_node.cpp
 * @brief 
 * 
 */

#include "dijkstra.h"
#include <iostream>

using namespace path_planning;

int main()
{
    dijkstra dijkstra(9);

    dijkstra.addEdge(0, 1, 4);
    dijkstra.addEdge(0, 7, 8);
    dijkstra.addEdge(1, 2, 8);
    dijkstra.addEdge(1, 7, 11);
    dijkstra.addEdge(2, 3, 7);
    dijkstra.addEdge(2, 8, 2);
    dijkstra.addEdge(2, 5, 4);
    dijkstra.addEdge(3, 4, 9);
    dijkstra.addEdge(3, 5, 14);
    dijkstra.addEdge(4, 5, 10);
    dijkstra.addEdge(5, 6, 2);
    dijkstra.addEdge(6, 7, 1);
    dijkstra.addEdge(6, 8, 6);
    dijkstra.addEdge(7, 8, 7);

    int source = 0;
    int target = 5;

    std::vector<double> distance = dijkstra.getShortestDistance(source);
    std::vector<int> path = dijkstra.getShortestPath(source, target);

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