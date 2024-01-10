
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
        _add(m_head, newItem);
    }
    addToNodeCount();
}

void LinkedList::_add(pListNode curr, pListNode newItem) {
    if(curr->getNext() == nullptr) {
        curr->setNext(newItem);
        newItem->setPrev(curr);
        return;
    }
    return(_add(curr->getNext(), newItem));
}

std::string LinkedList::remove(std::string data)
{
    pListNode curr = nullptr;
    if((curr = _find(data, m_head)) != nullptr) {
        _remove(curr);
        curr->setNext(nullptr);
        curr->setPrev(nullptr);
        subtractFromNodeCount();
        return(curr->getData());
    }
    return("");
}

pListNode LinkedList::_find(std::string data, pListNode curr) {
    if(curr == nullptr) {
        return(nullptr);
    } else if(data == curr->getData()) {
        return(curr);
    } else {
        return(_find(data, curr->getNext()));
    };
}

std::string LinkedList::_remove(pListNode curr) {
    if(curr->getPrev() == nullptr && curr->getNext() == nullptr) {
        // its the only node
        m_head = nullptr;
        return(curr->getData());
    }

    if(curr->getPrev() != nullptr) {
        curr->getPrev()->setNext(curr->getNext());
    } else {
        m_head = curr->getNext();
        curr->getNext()->setPrev(nullptr);
    }

    if(curr->getNext() != nullptr) {
        curr->getNext()->setPrev(curr->getPrev());
    }

    return(curr->getData());
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

