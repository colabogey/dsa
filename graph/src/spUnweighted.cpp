
#include "graph.h"

void Graph::spUnweighted(int vtxSrc, int vtxDest) {
    // Mark all the vertices as not visited
    std::deque<bool> visited(m_adjLists.size(), false);

    // Create a queue for BFS
    std::list<int> queue;
    std::deque<int> predList(m_adjLists.size(), -1);
    std::deque<int> costList(m_adjLists.size(), 0);

    // Mark the current node as visited and enqueue it
    int vtx = vtxSrc;
    visited[vtx] = true;
    costList[vtx] = 0;
    queue.push_back(vtx);
    while (!queue.empty()) {
        vtx = queue.front();
        queue.pop_front();
        for (auto adjacent : m_adjLists[vtx]) {
            if (!visited[adjacent.getVtx()]) {
                visited[adjacent.getVtx()] = true;
                predList[adjacent.getVtx()] = vtx;
                costList[adjacent.getVtx()] = costList[vtx] + 1;
                queue.push_back(adjacent.getVtx());
                if(adjacent.getVtx() == vtxDest) {
                    break;
                }
            }
        }
    }
    _showSp(vtxSrc, vtxDest, predList, costList);
}

void Graph::_showSp(int vtxSrc, int vtxDest, 
                    std::deque<int> predList, std::deque<int> costList) {
    // find dest 
    std::list<int> path;
    int currVtx = vtxDest;
    int predVtx;
    while(true) {
        predVtx = predList[currVtx];
        if(predVtx == vtxSrc) {
            break;
        }
        path.push_front(predVtx);
        currVtx = predVtx;
    }
    printf("Shortest path length (%d)-->(%d): (%d)\n", 
                vtxSrc, vtxDest, costList[vtxDest]);
    printf("Path: (%d) ", vtxSrc);
    for(int v : path) {
        printf("(%d) ", v);
    }
    printf("(%d)\n", vtxDest);
}
