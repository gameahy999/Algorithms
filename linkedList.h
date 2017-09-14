#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *generateIntLinkedList(int count, ...);
void printIntLinkedList(ListNode *head);

void test_linkedList();

#endif
