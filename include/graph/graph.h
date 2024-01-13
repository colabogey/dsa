#pragma once

#include "graphVertex.h"
#include <list>
#include <vector>
#include <string>

#define ADJ_SIZE 10

class Graph
{
public:
    Graph() { m_adjLists.resize(ADJ_SIZE) ; } ;
    ~Graph() = default;
    Graph& operator=(Graph& other) {return *this;};
    Graph(Graph& other) {};

    void addEdge(int, int, int);

private:
    std::vector<std::list<GraphVertex>> m_adjLists;
};
