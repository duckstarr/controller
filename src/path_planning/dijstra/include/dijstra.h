#ifndef DIJSTRA_H
#define DIJSTRA_H

#include <list>
#include <utility>

namespace path_planning
{

class dijstra
{
    public:
        dijstra(int N);
        ~dijstra() {};

        void addEdge(int u, int v, int w); // w is in mag
        void getShortestPath(int s);

    private:
        // A weighted graph that holds the number of nodes and the distance between them.
        std::list<std::pair<int, double>> * adjacent;

        // number of nodes.
        int N;
};

} // namespace path_planner

#endif DIJSTRA_H