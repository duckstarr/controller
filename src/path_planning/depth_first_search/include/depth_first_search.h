/**
 * @file depth_first_search.h
 * @brief A recursive implementation of DFS
 * 
 */

#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include <map>
#include <list>
#include <vector>

namespace path_planning
{

class DFS
{
    public:
        /**
         * @brief Pseuodcode
         * procedure DFS(G, v) is
         *     label v as discovered
         *     for all directed edges from v to w that are in G.adjacentEdges(v) do
         *         if vertex w is not labeled as discovered then
         *             recursively call DFS(G, w)
         * 
         * @param V number of vertex.
         */
        DFS(int V);
        ~DFS() {};

        /**
         * @brief Create a graph.
         * @param u source vertex
         * @param w adjacent vertex
         */
        void addEdge(int v, int w);

        /**
         * @brief Start the DFS searching algorithm on graph.
         * @param v Start vertex.
         * @return std::vector<int>* 
         */
        std::vector<int> * startDFS(int v);

    private:
        int V; // number of vertex.
        std::map<int, bool> label;
        std::list<int> * adjacent;
        std::vector<int> * output;
};

} // namespace path_planning

#endif /* DEPTH_FIRST_SEARCH_H */