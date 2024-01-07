
#include "../include/linkedList.h"
#include "../include/listInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void _clearLinkedList(pLinkedList pll, pListNode pln);
static void _addListNode(pLinkedList pll, pListNode curr, pListNode newItem);
static const char* _getListNodeData(pListNode pln, const char* data);

void addListNode(pLinkedList pll, const char *data) {
    pListNode newItem = createListNode();
    setNodeData(newItem, data);
    if (pll->m_head == NULL) {
        pll->m_head = newItem;
        addToNodeCount(pll);
    } else {
        _addListNode(pll, pll->m_head, newItem);
    }
}

void _addListNode(pLinkedList pll, pListNode curr, pListNode newItem) {
    if(curr->m_next == NULL) {
        curr->m_next = newItem;
        newItem->m_prev = curr;
        addToNodeCount(pll);
        return;
    }
    _addListNode(pll, curr->m_next, newItem);
}

bool removeListNode(pLinkedList pll, const char *data) {
    bool rVal = false;
    pListNode curr = pll->m_head;
    pListNode prev = NULL;
    pListNode next = NULL;
    while (curr != NULL) {
        if ((strcmp(data, getNodeData(curr))) == 0) {
            setNext(prev, getNext(curr));
            setPrev(next, getPrev(curr));

            subtractFromNodeCount(pll);
            clearListNode(curr);
            rVal = true;
            break;
        } else {
            prev = curr;
            next = getNext(curr);
            curr = next;
        }
    }
    return (rVal);
}

const char* getListNodeData(pLinkedList pll, const char* data) {
    return(pll->m_head == NULL ? NULL : _getListNodeData(pll->m_head, data));
}

const char* _getListNodeData(pListNode pln, const char* data) {
    const char* rVal = NULL;
    if ((strcmp(data, getNodeData(pln))) == 0) {
        return(getNodeData(pln));
    }

    if(pln->m_next != NULL) {
        _getListNodeData(pln->m_next, data);   
    }
    return(rVal);
}


pLinkedList createLinkedList() {
    pLinkedList pll = (pLinkedList)malloc(sizeof(LinkedList));
    pll->m_head = NULL;
    pll->m_nodeCount = 0;
    return (pll);
}

void clearLinkedList(pLinkedList pll) {
    _clearLinkedList(pll, pll->m_head);
    pll->m_head = NULL;
}

void _clearLinkedList(pLinkedList pll, pListNode pln) {
    if (pln == NULL) {
        return;
    }

    pListNode next = pln->m_next;
    clearListNode(pln);
    subtractFromNodeCount(pll);
    _clearLinkedList(pll, next);
}

void addToNodeCount(pLinkedList pll) { pll->m_nodeCount++; }

void subtractFromNodeCount(pLinkedList pll) { pll->m_nodeCount--; }

int getNodeCount(pLinkedList pll) {
    return (pll->m_head == NULL ? 0 : pll->m_nodeCount);
}

pListNode createListNode() {
    char *nodeData = (char *)malloc(NODE_DATA_SIZE);
    nodeData[0] = '\0';
    pListNode pln = (pListNode)malloc(sizeof(ListNode));
    pln->m_data = nodeData;
    pln->m_prev = NULL;
    pln->m_next = NULL;
    return (pln);
}

void clearListNode(pListNode pln) {
    if (pln->m_data != NULL) {
        free(pln->m_data);
        pln->m_data = NULL;
    }

    setNext(pln, NULL);
    setPrev(pln, NULL);

    if (pln != NULL) {
        free(pln);
        pln = NULL;
    }
}

const char *getNodeData(pListNode pln) { return pln->m_data; }

void setNodeData(pListNode pln, const char *data) { strcpy(pln->m_data, data); }

pListNode getNext(pListNode pln) { return pln->m_next; }

void setNext(pListNode pln, pListNode next) {
    if (pln != NULL) {
        pln->m_next = next;
    }
}

pListNode getPrev(pListNode pln) { return pln->m_prev; }

void setPrev(pListNode pln, pListNode prev) {
    if (pln != NULL) {
        pln->m_prev = prev;
    }
}
