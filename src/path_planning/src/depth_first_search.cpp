/**
 * @file depth_first_search.cpp
 * @brief A recursive implementation of DFS
 * 
 */

#include <depth_first_search.hpp>
#include <vector>
#include <map>

using namespace path_planning;

DFS::DFS(int V) : V(V), adjacent(V)
{
}

void DFS::addEdge(int v, int w)
{
    adjacent[v].push_back(w);
}

std::vector<int> DFS::startDFS(int v)
{
    label[v] = true;
    output.push_back(v);

    for(auto u : adjacent[v])
    {
        if(!label[u]) 
        {
            this->startDFS(u);
        }
    }

    return output;
}