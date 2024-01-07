#pragma once

#define NODE_DATA_SIZE 256

typedef struct ListNode {
    char *m_data;
    struct ListNode *m_prev;
    struct ListNode *m_next;
} ListNode, *pListNode;
