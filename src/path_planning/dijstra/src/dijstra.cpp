#include "dijstra.h"
#include <utility>

using namespace path_planning;

dijstra::dijstra(int N) : N(N)
{
    adjacent = new std::list<std::pair<int, double>> [N]; 
}

void dijstra::addEdge(int u, int v, int w)
{
    adjacent[u].push_back(std::make_pair(v, w));
    adjacent[v].push_back(std::make_pair(u, w));
}

void dijstra::getShortestPath(int s)
{

}