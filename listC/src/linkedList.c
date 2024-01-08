
#include "../include/linkedList.h"
#include "../include/listInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void _clearLinkedList(pLinkedList, pListNode);
static void _addListNode(pLinkedList, pListNode, pListNode);
static const char* _getListNodeData(pListNode, const char*);
static bool _removeListNode(pListNode, pListNode, pListNode, const char*);

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
    if((getNext(curr)) == NULL) {
        setNext(curr, newItem);
        setPrev(newItem, curr);
        addToNodeCount(pll);
        return;
    }
    _addListNode(pll, getNext(curr), newItem);
}

bool removeListNode(pLinkedList pll, const char *data) {
    bool ret = _removeListNode(pll->m_head, NULL, NULL, data);
    if(ret) {
        subtractFromNodeCount(pll);
    }
    return(ret);
}

bool _removeListNode(pListNode curr, pListNode next, pListNode prev, const char* data) {
    if(curr == NULL) {
        return(false);
    }

    if ((strcmp(data, getNodeData(curr))) == 0) {
        setNext(prev, getNext(curr));
        setPrev(next, getPrev(curr));
        clearListNode(curr);
        return(true);
    }
    prev = curr;
    next = getNext(curr);
    curr = next;
    return  _removeListNode(curr, next, prev,  data);
}

const char* getListNodeData(pLinkedList pll, const char* data) {
    if(pll->m_head == NULL) {
        return(NULL);
    }
    return(pll->m_head == NULL ? NULL : _getListNodeData(pll->m_head, data));
}

const char* _getListNodeData(pListNode pln, const char* data) {
    if ((strcmp(data, getNodeData(pln))) == 0) {
        const char* rVal = getNodeData(pln);
        return(rVal);
    } 

    if((getNext(pln)) != NULL) {
        return _getListNodeData(getNext(pln), data);   
    } else {
        return(NULL);
    }
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
    setNext(pln, NULL);
    setPrev(pln, NULL);
    return (pln);
}

void clearListNode(pListNode pln) {
    if ((getNodeData(pln)) != NULL) {
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
