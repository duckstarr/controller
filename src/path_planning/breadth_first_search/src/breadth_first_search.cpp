/**
 * @file breadth_first_search.cpp
 * @brief Find the shortest path from a source to other vertices in an unweighted graph.
 * 
 */

#include "breadth_first_search.h"
#include <list>
#include <queue>
#include <vector>

using namespace path_planning;

BFS::BFS(int V, int source) : V(V)
{
    adjacent = new std::list<int> [V];
    label = new bool[V];
    predecessor.resize(V, -1);
}

void BFS::addEdge(const int v, const int w)
{
    adjacent[v].push_back(w);
}

void BFS::startBFS(const int s)
{
    std::queue<int> Q;
    std::vector<int> distance(V);

    label[s] = true;
    Q.push(s); // Q.enqueue(root)

    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for(auto it = adjacent[v].begin(); it != adjacent[v].end(); it++)
        {
            if(!label[*it])
            {
                label[*it] = true;
                Q.push(*it); // Q.enqueue(w)
                distance[*it] = distance[v] + 1;
                predecessor[*it] = v;
            }
        }
    }
}

std::vector<int> BFS::getShortestPath(int dest)
{
    std::vector<int> path;
    path.push_back(dest);

    while(predecessor[dest] != -1)
    {
        path.push_back(predecessor[dest]);
        dest = predecessor[dest];
    }

    return path;
}