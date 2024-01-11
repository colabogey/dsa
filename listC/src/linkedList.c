
#include "../include/linkedList.h"
#include "../include/listInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void _clearLinkedList(pLinkedList, pListNode);
static void _addListNode(pLinkedList, pListNode, pListNode);
static const char* _getListNodeData(pListNode, const char*);
static void _removeListNode(pLinkedList, pListNode);
static pListNode _findListNode(pListNode, const char*);
static void _displayList(pListNode, char*);

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
    pListNode curr = _findListNode(pll->m_head, data);
    if(curr == NULL) {
        return(false);
    }
    _removeListNode(pll, curr);
    clearListNode(curr);
    subtractFromNodeCount(pll);
    return(true);
}

pListNode _findListNode(pListNode curr, const char* data) {
    if(curr == NULL) {
        return(NULL);
    }

    if ((strcmp(data, getNodeData(curr))) == 0) {
        return(curr);
    }

    return(_findListNode(getNext(curr), data));
}

void _removeListNode(pLinkedList pll, pListNode curr) {

    if(getNext(curr) == NULL && getPrev(curr) == NULL) {
        pll->m_head = NULL;
        return;
    }

    pListNode next = getNext(curr) == NULL ? NULL : getNext(curr);
    pListNode prev = getPrev(curr) == NULL ? NULL : getPrev(curr);

    if(prev != NULL) {
        prev->m_next = curr->m_next;
    } else {
        pll->m_head = curr->m_next;
    }

    if(next != NULL) {
        next->m_prev = curr->m_prev;
    }

    return;
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

void displayList(pLinkedList pll, char* content) {
    if (pll->m_head != NULL) {
        _displayList(pll->m_head, content);
        int len = strlen(content);
        sprintf(&content[len], "\n");
    }
}

void _displayList(pListNode curr, char* content) {
    if(curr == NULL) {
        return;
    }
    int len = strlen(content);
    sprintf(&content[len], "\t(%s)  ", curr->m_data);
    _displayList(curr->m_next, content);
}

