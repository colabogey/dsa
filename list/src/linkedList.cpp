
#include <string>
#include "linkedList.h"
#include "listNode.h"

void LinkedList::add(std::string data)
{
    pListNode newItem = make_shared<ListNode>(data);
    newItem->setData(data);
    if(m_head == nullptr) {
        m_head = newItem;
    } else {
        pListNode tmp = m_head;
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        tmp->setNext(newItem);
        m_tail = newItem;
    }
    addToNodeCount();
}

std::string LinkedList::remove(std::string data)
{
    std::string rVal = "";
    pListNode curr = m_head;
    pListNode prev = nullptr;
    while(curr != nullptr)
    {
        if(data == curr->getData())
        {
            rVal = curr->getData();
            if(prev != nullptr)
            {
                prev->setNext(curr->getNext());
            }
            else
            {
                m_head = nullptr;
                m_tail = nullptr;
            }
            subtractFromNodeCount();
            break;
        }
        else
        {
            prev = curr;
            curr = curr->getNext();
        }
   }
   return(rVal);
}

std::string LinkedList::get(std::string data)
{
    std::string rVal = "";
    pListNode tmp = m_head;
    while(tmp != nullptr)
    {
        if(data == tmp->getData())
        {
            rVal = tmp->getData();
            break;
        }
   }
   return(rVal);
}

