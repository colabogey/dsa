#pragma once

#include "graphVertex.h"
#include <list>
#include <string>
#include <deque>
#include <vector>

#define ADJ_LIST_SIZE_INCREMENT 16

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

    int main();
    void printShortestDistance(std::vector<int>[], int, int, int);
    bool shortestPath(std::vector<int>[], int, int, int, int[], int[]);
    void add_edge(std::vector<int>[], int, int);

    void shortestPathUnweighted(int, int);
    
    int getAdjListCount();
    bool getPathFound() { return m_pathFound; };
    int getPathCost() { return m_pathCost; };
    std::list<int> getPathResult() { return m_pathResult; };

  private:
    void _showSp(int, int, std::deque<int>, std::deque<int>);
    bool m_pathFound{false};
    int m_pathCost{0};
    std::list<int> m_pathResult;
    std::deque<std::list<GraphVertex>> m_adjLists;
};
