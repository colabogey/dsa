
#include "graph.h"

void Graph::addEdge(int source, int dest, int weight)
{
    GraphVertex v(dest, weight);
    m_adjLists[source].push_back(v);
}
