
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
        pListNode curr = m_head;
        while(curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(newItem);
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
                // its the head we are removing
                if(curr->getNext() != nullptr)
                {
                    m_head->setNext(curr->getNext());
                }
                else
                {
                    m_head = nullptr;
                }
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

