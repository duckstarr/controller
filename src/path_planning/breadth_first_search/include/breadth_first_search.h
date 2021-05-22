#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include <list>

namespace path_planning
{

class BFS
{
    public:
        BFS(int V);
        ~BFS() {};

        void addEdge(int v, int w);
        void getShortestPath(int src);

    private:
        int V;
        std::list<int> * adjacent;

};

} // namespace path_planning

#endif /* BREADTH_FIRST_SEARCH_H */