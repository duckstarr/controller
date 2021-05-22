/**
 * @file breadth_first_search.h
 * @brief Find the shortest path from a source to other vertices in an unweighted graph.
 * 
 */

#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include <list>
#include <vector>

namespace path_planning
{

class BFS
{
    public:
        /**
         * @brief Pseudocode
         * 1  procedure BFS(G, root) is
         * 2      let Q be a queue
         * 3      label root as discovered
         * 4      Q.enqueue(root)
         * 5      while Q is not empty do
         * 6          v := Q.dequeue()
         * 7          if v is the goal then
         * 8              return v
         * 9          for all edges from v to w in G.adjacentEdges(v) do
         * 10              if w is not labeled as discovered then
         * 11                  label w as discovered
         * 12                  Q.enqueue(w)
         * 
         * @param V number of vertex.
         * @param source 
         */
        BFS(int V, int source);
        ~BFS() {};

        /**
         * @brief Create a graph.
         * @param u source vertex
         * @param w adjacent vertex
         */
        void addEdge(const int v, const int w);

        /**
         * @brief Start the BFS searching algorithm on graph.
         * @param src Start vertex.
         */
        void startBFS(const int src);

        /**
         * @brief Get the shortest path from start to destination.
         * @param dest Destination vertex.
         * @return std::vector<int> shortest path.
         */
        std::vector<int> getShortestPath(int dest);

    private:
        int V; // number of vertex.
        bool * label; // visited node.

        std::list<int> * adjacent;
        std::vector<int> prediction;
};

} // namespace path_planning

#endif /* BREADTH_FIRST_SEARCH_H */