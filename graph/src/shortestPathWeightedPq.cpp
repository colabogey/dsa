
#include "graph.h"
#include <algorithm>
#include <limits>
#include <format>
#include <queue>

/*
adapted from 
geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
*/

void Graph::shortestPathWeightedPq(int src)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair> > pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INT_MAX)
	std::deque<int> dist(m_adjLists.size(), INT_MAX);
    std::deque<int> parents(m_adjLists.size(), -1);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(std::make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty()) {
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

        std::list<GraphVertex>::iterator it;
		for (it = m_adjLists[u].begin(); it != m_adjLists[u].end(); ++it) {
			// Get vertex label and weight of current
			// adjacent of u.
			int v = it->getVtx();
			int weight = it->getWeight();

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(std::make_pair(dist[v], v));
                parents[it->getVtx()] = u;
			}
		}
	}
    _printSolution(src, dist, parents);
}

