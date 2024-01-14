#include "graph.h"

void Graph::bfsSay(int vtx, std::list<int> &result) {
    std::list<int> queue;
    std::vector<bool> visited;
    visited.resize(m_adjLists.size(), false);

    visited[vtx] = true;
    queue.push_back(vtx);

    while (!queue.empty()) {
        vtx = queue.front();
        queue.pop_front();
        result.push_back(vtx);
        for (auto adjacent : m_adjLists[vtx]) {
            if (!visited[adjacent.getVtx()]) {
                queue.push_back(adjacent.getVtx());
                visited[adjacent.getVtx()] = true;
            }
        }
    }
}
