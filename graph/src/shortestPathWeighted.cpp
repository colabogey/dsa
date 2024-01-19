
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

    std::vector<int> parents(items, -1);

    for(int i = 0; i < (items - 1); i++) {
        int u = _minDistance(dist, sptSet);
        sptSet[u] = true;
        
        std::list<GraphVertex>::iterator it;
        for(it = m_adjLists[u].begin(); it != m_adjLists[u].end(); it++) {
            bool inSptSet = sptSet[it->getVtx()];
            int du = dist[u];
            int guv = it->getWeight();
            int dv = dist[it->getVtx()];

            if (!inSptSet && dist[u] != INT_MAX && 
                dist[u] + guv < dv) {
                dist[it->getVtx()] = du + guv;
                parents[it->getVtx()] = u;
            }

            //if (!sptSet[v] && graph[u][v]
                //&& dist[u] != INT_MAX
                //&& dist[u] + graph[u][v] < dist[v])
        }
    }
    _printSolution(vtxSrc, dist, parents);
    m_dist = dist;
}

void Graph::_printPath(int currentVertex, std::vector<int> parents)
{

    // Base case : Source node has
    // been processed
    if (currentVertex == -1) {
        return;
    }
    _printPath(parents[currentVertex], parents);
    std::cout << currentVertex << " ";
}

void Graph::_printSolution(int startVertex, std::deque<int> distances, std::vector<int> parents)
{
    int nVertices = distances.size();
    std::cout << "Vertex\t Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
        if (vertexIndex != startVertex) {
            if(distances[vertexIndex] == INT_MAX) {
                continue;
            }
            std::cout << "\n" << startVertex << " -> ";
            std::cout << vertexIndex << " \t\t ";
            std::cout << distances[vertexIndex] << "\t";
            _printPath(vertexIndex, parents);
        }
    }
    std::cout << "\n";
}
        
void Graph::_initUnvisited(std::list<int>& unv) {
    for (int i = 0; i < m_adjLists.size(); i++) {
        unv.push_back(i);
    }
}

void Graph::showShortestPathWeighted(int vtx) {
    for(int i = 0; i < m_adjLists.size(); i++) {
        printf("%d to %d, Cost: %d\n", vtx, i, m_dist[i]);
    }

    //std::cout << "Vertex \t Distance from Source" << std::endl;
    //for (int i = 0; i < m_adjLists.size(); i++)
        //std::cout << i << " \t\t" << m_dist[i] << std::endl;
}



