
#include "graph.h"

void Graph::bfs_g4g(int vtx) {
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
