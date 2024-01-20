#pragma once

#include "graphVertex.h"
#include <list>
#include <string>
#include <deque>
#include <vector>
#include <memory>

typedef std::pair<int,unsigned long long> PII;
typedef std::vector<PII> VPII;
typedef std::vector<VPII> VVPII;

class Graph {
  public:
    Graph();
    //Graph(int vtx);
    ~Graph();
    Graph &operator=(Graph &other) { return *this; };
    Graph(Graph &other){};

    void addEdge(int, int, int);
    void addDirectedEdge(int, int, int);
    void bfs(int, std::list<int> &);
    void shortestPathUnweighted(int, int);
    void shortestPathWeighted(int);
    // things to learn from
    // g4g
    void bfs_g4g(int);
    // g4g
    int main();
    void printShortestDistance(std::vector<int>[], int, int, int);
    bool shortestPath(std::vector<int>[], int, int, int, int[], int[]);
    void add_edge(std::vector<int>[], int, int);
    // algotree
    void DijkstrasShortestPath (int source_node, int node_count, VVPII& graph);
    int main_algotree();
    ///////////////
    
    int getAdjListCount() { return m_adjLists.size(); } ;
    bool getPathFound() { return m_pathFound; };
    int getPathCost(GraphVertex v) { return v.getWeight(); };
    int getPathCost() { return m_pathCost; };
    std::list<int> getPathResult() { return m_pathResult; };

  private:
    void _addEdge(int, int, int);
    void _initUnvisited(std::list<int>&);
    int _findMinUnvisited(std::deque<int>& ul, std::deque<int>&  cl);
    void _showSp(int, int, std::deque<int>, std::deque<int>);
    bool m_pathFound{false};
    int m_pathCost{0};
    int _minDistance(std::deque<int>&, std::deque<bool>&);

    void _printPath(int, std::deque<int>);
    void _printSolution(int, std::deque<int>, std::deque<int>);

    std::list<int> m_pathResult;
    std::vector<std::list<GraphVertex>> m_adjLists;
    std::deque<int> m_dist;
    std::deque<int> m_prevList;
};


