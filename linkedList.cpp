#include <stdarg.h>
#include <stdio.h>

#include "linkedList.h"

ListNode *
generateIntLinkedList(int count, ...)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    va_list args;

    va_start(args, count);
    while(count--) {
        ListNode *tmp = new ListNode(va_arg(args, int));
        if (head == NULL) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    va_end(args);

    return head;
}

void
printIntLinkedList(ListNode *head)
{
    ListNode *p = head;

    while (p != NULL) {
        printf("%d  ", p->val);
        p = p->next;
    }
    printf("\n");
}

void
test_linkedList()
{
    printIntLinkedList(generateIntLinkedList(6, 1, 2, 3, 6, 5, 4));
}
