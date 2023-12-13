#pragma once

#include "listNode.h"
#include <memory>
#include <string>

class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList() = default;
    LinkedList& operator=(LinkedList& other) {return *this;};
    LinkedList(LinkedList& other) {};

    void add(std::string);
    std::string get(std::string);
    std::string remove(std::string);
    void addToNodeCount() { m_nodeCount++ ;} ;
    void subtractFromNodeCount() { m_nodeCount-- ;} ;
    int getNodeCount() { return m_nodeCount ;} ;

private:
    pListNode m_head {nullptr};
    int m_nodeCount {0};
};
