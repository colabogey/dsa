
#include "graph.h"

Graph::Graph() { m_adjLists.resize(ADJ_LIST_SIZE_INCREMENT); }
Graph::Graph(int vtx) { m_adjLists.resize(vtx); }
Graph::~Graph() { 
    for(auto l : m_adjLists) {
        l.clear();
    }
    m_adjLists.clear();
}

void Graph::addEdge(int source, int dest, int weight) {
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

int Graph::getAdjListCount() {
    int count = 0;
    for(auto l : m_adjLists) {
        count += l.size();
    }
    return(count);
}

