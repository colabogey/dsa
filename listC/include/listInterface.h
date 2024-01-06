#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void addListNode(pLinkedList, const char *);
bool removeListNode(pLinkedList, const char *);
const char* getListNodeData(pLinkedList, const char *);
void addToNodeCount(pLinkedList pll);
void subtractFromNodeCount(pLinkedList pll);
int getNodeCount(pLinkedList pll);

const char *getNodeData(pListNode pln);
void setNodeData(pListNode pln, const char *data);
pListNode getNext(pListNode pln);
void setNext(pListNode pln, pListNode next);

pLinkedList createLinkedList();
void clearLinkedList(pLinkedList pll);
pListNode createListNode();
void clearListNode(pListNode pln);

#ifdef __cplusplus
}
#endif
