
#include "graph.h"

void Graph::shortestPathUnweighted(int vtxSrc, int vtxDest) {
    // Mark all the vertices as not visited
    std::deque<bool> visited(m_adjLists.size(), false);

    // Create a queue for BFS
    std::list<int> queue;
    std::deque<int> predList(m_adjLists.size(), -1);
    std::deque<int> costList(m_adjLists.size(), 0);

    // Mark the current node as visited and enqueue it
    m_pathFound = false;
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
                costList[adjacent.getVtx()] = 
                    costList[vtx] + adjacent.getWeight();
                queue.push_back(adjacent.getVtx());
                if(adjacent.getVtx() == vtxDest) {
                    m_pathFound = true;
                    break;
                }
            }
        }
    }
    _showSp(vtxSrc, vtxDest, predList, costList);
}

void Graph::_showSp(int vtxSrc, int vtxDest, 
                    std::deque<int> predList, std::deque<int> costList) {
    if(m_pathFound == false) {
        return;
    }
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
    m_pathCost = costList[vtxDest];
    m_pathResult.clear();
    m_pathResult.push_back(vtxSrc);
    for(int v : path) {
        m_pathResult.push_back(v);
    }
    m_pathResult.push_back(vtxDest);
}
