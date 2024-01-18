
#include "graph.h"

Graph::Graph() { 
}
//Graph::Graph(int vtx) { m_pAdjLists.resize(vtx); }
Graph::~Graph() { 
    for(auto l : m_adjLists) {
        l.clear();
    }
    m_adjLists.clear();
}

void Graph::addDirectedEdge(int src, int dst, int weight) {
    _addEdge(src, dst, weight);
}

/*
void Graph::addUndirectedEdge(int source, int dest, int weight) {
    GraphVertex v(dest, weight);
    if(m_adjLists.size() < (source + 1)) {
        m_adjLists.resize(m_adjLists.size() + ADJ_LIST_SIZE_INCREMENT);
    }
    m_adjLists[source].push_back(v);
    // undirected - both ways
    GraphVertex v2(source, weight);
    if(m_adjLists.size() < (dest + 1)) {
        m_adjLists.resize(m_adjLists.size() + ADJ_LIST_SIZE_INCREMENT);
    }
    m_adjLists[dest].push_back(v2);
}
*/

void Graph::addEdge(int src, int dst, int weight) {
    _addEdge(src, dst, weight);
    _addEdge(dst, src, weight);
}

void Graph::_addEdge(int src, int dst, int weight) {
    GraphVertex v(dst, weight);
    if(m_adjLists.size() < (src + 1)) {
        m_adjLists.resize(src + 1);
    }
    m_adjLists[src].push_back(v);
}

