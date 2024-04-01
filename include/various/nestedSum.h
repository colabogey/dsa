#pragma once
#include <vector>

class NestedNode {
public:
    NestedNode() = default;
    NestedNode(int);
    ~NestedNode() = default;
    void addData(std::vector<NestedNode*>&);

    std::vector<NestedNode*> m_data;
    int m_val;
};

class NestedSumer {
public:
    NestedSumer() = default;
    ~NestedSumer() = default;
    int calculateSum(NestedNode*);
};
