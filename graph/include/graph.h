#pragma once

#include "graphVertex.h"
#include <list>
#include <string>
#include <deque>
#include <vector>

#define ADJ_LIST_SIZE_INCREMENT 16
typedef std::pair<int,unsigned long long> PII;
typedef std::vector<PII> VPII;
typedef std::vector<VPII> VVPII;

class Graph {
  public:
    Graph();
    Graph(int vtx);
    ~Graph();
    Graph &operator=(Graph &other) { return *this; };
    Graph(Graph &other){};

    void addEdge(int, int, int);
    void BFS(int);
    void bfsSay(int, std::list<int> &);

    // g4g
    int main();
    void printShortestDistance(std::vector<int>[], int, int, int);
    bool shortestPath(std::vector<int>[], int, int, int, int[], int[]);
    void add_edge(std::vector<int>[], int, int);
    // algotree
    void DijkstrasShortestPath (int source_node, int node_count, VVPII& graph);
    int main_algotree();
    //

    void shortestPathUnweighted(int, int);
    
    int getAdjListCount();
    bool getPathFound() { return m_pathFound; };
    int getPathCost(GraphVertex v) { return v.getWeight(); };
    int getPathCost() { return m_pathCost; };
    std::list<int> getPathResult() { return m_pathResult; };

  private:
    void _showSp(int, int, std::deque<int>, std::deque<int>);
    bool m_pathFound{false};
    int m_pathCost{0};
    std::list<int> m_pathResult;
    std::deque<std::list<GraphVertex>> m_adjLists;
};
