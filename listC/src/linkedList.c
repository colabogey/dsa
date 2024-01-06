
#include <string.h>
#include "linkedList.h"
#include "listNode.h"

void addListNode(pLinkedList, const char*);
const char* removeListNode(pLinkedList, const char*);
const char* getListNodeData(pLinkedList, const char*);
void addToNodeCount(pLinkedList pll);
void subtractFromNodeCount(pLinkedList pll);
int getNodeCount(pLinkedList pll);

const char* getNodeData(pListNode pln);
void setNodeData(pListNode pln, const char* data);
pListNode getNext(pListNode pln);
void setNext(pListNode pln);

pLinkedList createLinkedList();
void clearLinkedList(pLinkedList pll);
pListNode createListNode();
void clearListNode(pListNode pln);

void addListNode(pLinkedList pll, const char* data)
{
    pListNode newItem = createListNode();
    setNodeData(newItem, data);
    if(pll->m_head == NULL) {
        pll->m_head = newItem;
    } else {
        pListNode curr = pll->m_head;
        while(curr->m_next != NULL)
        {
            pListNode next = curr->m_next;
            curr = next;
        }
        curr->m_next = newItem;
    }
    addToNodeCount(pll);
}

const char* removeListNode(pLinkedList pll, const char* data)
{
    const char* rVal;
    pListNode curr = pll->m_head;
    pListNode prev = NULL;
    while(curr != NULL)
    {
        if(data == getNodeData(curr))
        {
            rVal = getNodeData(curr);
            if(prev != NULL)
            {
                // prev->setNext(curr->getNext());
                prev->m_next = curr->m_next;
            }
            else
            {
                // its the head we are removing
                if(getNext(curr) != NULL)
                {
                    pListNode next = getNext(curr);
                    pll->m_head->m_next = next;
                }
                else
                {
                    pll->m_head = NULL;
                }
            }
            subtractFromNodeCount(pll);
            break;
        }
        else
        {
            prev = curr;
            pListNode next = getNext(curr);
            curr = next;
        }
   }
   return(rVal);
}

const char* getListNodeData(pLinkedList pll, const char* data)
{
    const char* rVal;
    pListNode tmp = pll->m_head;
    while(tmp != NULL)
    {
        if(data == getNodeData(tmp))
        {
            rVal = getNodeData(tmp);
            break;
        }
        pListNode next = getNext(tmp);
        tmp = next;
   }
   return(rVal);
}

pLinkedList createLinkedList() {
    pLinkedList pll = (pLinkedList)malloc(sizeof(LinkedList));
    pll->m_head = NULL;
    pll->m_nodeCount = 0;
    return(pll);
}

void clearLinkedList(pLinkedList pll) {
    if(pll->m_head != NULL) {
        free(pll->m_head);
        pll->m_head = NULL;
    }
}

void addToNodeCount(pLinkedList pll) { 
    pll->m_nodeCount++ ;
}

void subtractFromNodeCount(pLinkedList pll) {
    pll->m_nodeCount-- ;
}

int getNodeCount(pLinkedList pll) {
    return pll->m_nodeCount ;
}

pListNode createListNode() {
    char* nodeData = (char *)malloc(NODE_DATA_SIZE);
    nodeData[0] = '\0';
    pListNode pln = (pListNode)malloc(sizeof(ListNode));
    pln->m_data = nodeData;
    pln->m_next = NULL;
    return (pln);
}

void clearListNode(pListNode pln) {
    if(pln->m_data != NULL) {
        free(pln->m_data);
        pln->m_data = NULL;
    }

    if(pln->m_next != NULL) {
        free(pln->m_next);
        pln->m_next = NULL;
    }
}

const char* getNodeData(pListNode pln) {
    return pln->m_data;
}

void setNodeData(pListNode pln, const char* data) {
    strcpy(pln->m_data, data);
}

pListNode getNext(pListNode pln) {
    return pln->m_next;
}

void setNext(pListNode pln) {
    pln->m_next = pln;
}

