#include <list>
#include <tuple>
#include <stdio.h>
#include "sptData.h"

void SptData::addSptItem(SPT_PATH_ITEM pi) {
    m_spt_path_items.push_back(pi);
}

void SptData::show() {
    printf("Vertex\t    Distance\tPath\n");
    for(auto item : m_spt_path_items) {
        int vtx = std::get<0>(item);
        int dist = std::get<1>(item);
        std::deque<int> path = std::get<2>(item);
        printf("%d -> %d\t\t%d\t", m_src, vtx, dist); 
        for(auto p : path) {
            printf("%d ", p); 
        }
        printf("\n"); 
    }
}


// add operator ==
// add show
