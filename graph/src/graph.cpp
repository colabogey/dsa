
#include "graph.h"

Graph::Graph(int vtx) { m_adjLists.resize(vtx); }

void Graph::addEdge(int source, int dest, int weight) {
    //int sz = m_adjLists.size();
    //m_adjLists.resize(sz + 1);
    if (source >= m_adjLists.size() || dest >= m_adjLists.size()) {
        // TODO: indicate some error or just resize ?
        printf(" **************** TOO BIG **************** \n");
        return;
    }

    GraphVertex v(dest, weight);
    m_adjLists[source].push_back(v);
    // undirected - both ways
    GraphVertex v2(source, weight);
    m_adjLists[dest].push_back(v2);
}

void Graph::BFS(int vtx) {
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(m_adjLists.size(), false);

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vtx] = true;
    queue.push_back(vtx);

    while (!queue.empty()) {

        // Dequeue a vertex from queue and print it
        vtx = queue.front();
        printf("(%d) ", vtx);
        // cout << vtx << " ";
        queue.pop_front();
        if (queue.size() == 0) {
            printf("\n");
        }

        // Get all adjacent vertices of the dequeued
        // vertex vtx.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent : m_adjLists[vtx]) {
            if (!visited[adjacent.getVtx()]) {
                visited[adjacent.getVtx()] = true;
                queue.push_back(adjacent.getVtx());
            }
        }
    }
    printf("\n");
}
