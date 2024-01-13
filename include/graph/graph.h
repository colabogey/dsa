#pragma once

#include "graphVertex.h"
#include <list>
#include <vector>
#include <string>

class Graph
{
public:
    Graph() = default;
    Graph(int vtx);
    ~Graph() = default;
    Graph& operator=(Graph& other) {return *this;};
    Graph(Graph& other) {};

    void addEdge(int, int, int);
    void BFS(int);

private:
    std::vector<std::list<GraphVertex>> m_adjLists;
};

