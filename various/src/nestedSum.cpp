#include <queue>
#include "nestedSum.h"

NestedNode::NestedNode(int val) {
    m_val = val;
    m_data.resize(0);
}

void NestedNode::addData(std::vector<NestedNode*>& data) {
    for(auto n : data) {
        m_data.push_back(n);
    }
}

int NestedSumer::calculateSum(NestedNode* n) {
    int ans = 0;
    int level = 1;
    std::queue<NestedNode*> q;
    q.push(n);
    while(!q.empty()) {
    int items = q.size();
        while(items > 0) {
            NestedNode* nn = q.front();
            q.pop();
            ans += (nn->m_val * level);
            for(int i = 0; i < nn->m_data.size(); i++) {
                q.push(nn->m_data[i]);
            }
            items--;
        }
    level++;
    }
    return ans;
}
