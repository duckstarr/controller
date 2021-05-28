/**
 * @file dijkstra.cpp
 * @brief Dijkstra shortest path algorithm.
 * 
 */

#include <dijkstra.hpp>
#include <utility>
#include <vector>
#include <limits>
#include <set>

using namespace path_planning;

dijkstra::dijkstra(int V) : V(V)
{
    adjacent = new std::list<std::pair<int, double>> [V];
    distance.resize(V, std::numeric_limits<double>::infinity());
    previous.resize(V);
}

dijkstra::~dijkstra()
{
    delete [] adjacent;
}

void dijkstra::addEdge(const int u, const int v, const double w)
{
    adjacent[u].push_back(std::make_pair(v, w));
    adjacent[v].push_back(std::make_pair(u, w));
}

std::vector<double> dijkstra::getShortestDistance(const int src)
{
    std::set<std::pair<double, int>> Q;
    distance[src] = 0;

    Q.insert(std::make_pair(0, src));

    while(!Q.empty())
    {
        // u ← vertex in Q with min dist[u] starting at src.
        auto temp = * Q.begin();
        int u = temp.second;

        // remove u from Q.
        Q.erase(Q.begin());
        
        for(auto i = adjacent[u].begin(); i != adjacent[u].end(); ++i)
        {
            int v = (*i).first;
            double length = (*i).second;

            if(distance[u] + length < distance[v])
            {
                distance[v] = distance[u] + length;
                previous[v] = u;
                Q.insert(std::make_pair(distance[v], v));
            }
        }
    }

    return distance;
}

std::vector<int> dijkstra::getShortestPath(const int source, const int target)
{
    std::vector<int> sequence;
    int u = target;

    if(previous.size() > 0 || u == source)
    {
        while(u)
        {
            sequence.push_back(u);
            u = previous.at(u);
        }
    }
    
    return sequence;
}