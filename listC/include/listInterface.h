#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void addListNode(pLinkedList, const char *);
bool removeListNode(pLinkedList, const char *);
const char *getListNodeData(pLinkedList, const char *);
void addToNodeCount(pLinkedList);
void subtractFromNodeCount(pLinkedList);
int getNodeCount(pLinkedList);

const char *getNodeData(pListNode);
void setNodeData(pListNode, const char*);
pListNode getNext(pListNode);
void setNext(pListNode, pListNode);
pListNode getPrev(pListNode);
void setPrev(pListNode, pListNode);

pLinkedList createLinkedList();
void clearLinkedList(pLinkedList);
pListNode createListNode();
void clearListNode(pListNode);

void displayList(pLinkedList, char*);

#ifdef __cplusplus
}
#endif
