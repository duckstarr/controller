/**
 * @file dijkstra.h
 * @brief Dijkstra shortest path algorithm.
 * 
 */

#ifndef DIJSTRA_H
#define DIJSTRA_H

#include <list>
#include <utility>
#include <vector>
#include <set>

namespace path_planning
{

class dijkstra
{
    public:
        /**
         * @brief Pseudocode
         * 1  function Dijkstra(Graph, source):
         * 2
         * 3      create vertex set Q
         * 4
         * 5      for each vertex v in Graph:            
         * 6          dist[v] ← INFINITY                 
         * 7          prev[v] ← UNDEFINED                
         * 8          add v to Q                     
         * 9      dist[source] ← 0                       
         * 10     
         * 11      while Q is not empty:
         * 12          u ← vertex in Q with min dist[u]   
         * 13                                             
         * 14          remove u from Q
         * 15         
         * 16          for each neighbor v of u:           // only v that are still in Q
         * 17              alt ← dist[u] + length(u, v)
         * 18              if alt < dist[v]:              
         * 19                  dist[v] ← alt
         * 20                  prev[v] ← u
         * 21
         * 22      return dist[], prev[]
         * 
         * @param V number of vertex.
         */
        dijkstra(int V);
        ~dijkstra();

        /**
         * @brief Create an stl graph based on the number of verticies and distances between them.
         * 
         * @param u source vertex
         * @param v adjacent vertex
         * @param w distance between source and adjacent vertex
         */
        void addEdge(const int u, const int v, const double w);

        /**
         * @brief Compute the shortest path from existing verticies.
         * 
         * @param src A datum used to compute the shortest path from src.
         * @return std::vector<double> shortest path.
         */
        std::vector<double> getShortestDistance(const int src); 

        std::vector<int> getShortestPath(const int source, const int target);

    private:
        // A weighted graph that holds the number of nodes and the distance between them.
        std::list<std::pair<int, double>> * adjacent; // adjacency list.

        std::vector<int> previous;
        std::vector<double> distance;

        // number of vertex.
        int V;
};

} // namespace path_planner

#endif /* DIJSTRA_H */