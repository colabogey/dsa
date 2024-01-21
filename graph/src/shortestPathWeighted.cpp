
#include "graph.h"
#include <algorithm>
#include <limits>
#include <iostream>

int Graph::_minDistance(std::deque<int>& dist, std::deque<bool>& sptSet)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < m_adjLists.size(); v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void Graph::shortestPathWeighted(int vtxSrc) {
    // Mark all the vertices as not visited
    int items = m_adjLists.size();
    std::deque<bool> sptSet(items, false);
    std::deque<int> dist(items, INT_MAX);
    dist[vtxSrc] = 0;

    std::deque<int> parents(items, -1);

    for(int i = 0; i < (items - 1); i++) {
        // u is the vertex that
        // is not in the spt set and
        //``has the minimum dist value
        int u = _minDistance(dist, sptSet);
        sptSet[u] = true;
        
        // look through vtx adjacent to u
        std::list<GraphVertex>::iterator it;
        for(it = m_adjLists[u].begin(); it != m_adjLists[u].end(); it++) {
            // For every adjacent vertex v, 
            // if the sum of the distance value of u (from source) 
            // and weight of edge u-v, 
            // is less than the distance value of v, 
            // then update the distance value of v.
            bool inSptSet = sptSet[it->getVtx()];
            int du = dist[u];               // distance value of u from the source
            int itw = it->getWeight();      // weight of the edge
            int ditv = dist[it->getVtx()];  // distsnce value of v
            if (!inSptSet && dist[u] != INT_MAX && 
                dist[u] + itw < ditv) {
                dist[it->getVtx()] = du + itw;
                parents[it->getVtx()] = u;
            }
        }
    }
    _printSolution(vtxSrc, dist, parents);
    //m_dist = dist;
}

void Graph::_printPath(int currentVertex, std::deque<int> parents, std::deque<int>& paths)
{
    // Base case : Source node has
    // been processed
    if (currentVertex == -1) {
        return;
    }
    paths.push_front(currentVertex);
    _printPath(parents[currentVertex], parents, paths);
    //std::cout << currentVertex << " ";
}

void Graph::_printSolution(int startVtx, std::deque<int> distances, std::deque<int> parents)
{
    m_pSptData->setSrc(startVtx);
    int nVertices = distances.size();
    //std::cout << "Vertex\t    Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
        if (vertexIndex != startVtx) {
            if(distances[vertexIndex] == INT_MAX) {
                continue;
            }
            //std::cout << "\n" << startVtx << " -> ";
            //std::cout << vertexIndex << "\t\t";
            //std::cout << distances[vertexIndex] << "\t";
            std::deque<int> path;
            _printPath(vertexIndex, parents, path);
            SPT_PATH_ITEM pi = 
                 std::make_tuple(vertexIndex, distances[vertexIndex], path);
            m_pSptData->addSptItem(pi);
        }
    }
    //std::cout << "\n";
}

