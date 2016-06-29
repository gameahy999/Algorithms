#include <stdarg.h>
#include <stdio.h>

#include "linkedList.h"

/*
 *------------------------------------------------------------------------------
 *
 * Generate a int linked list with the given parameters.
 * The first parameter is the number of ints.
 *
 *------------------------------------------------------------------------------
 */

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


/*
 *------------------------------------------------------------------------------
 *
 * Reverse a linked list.
 *
 *------------------------------------------------------------------------------
 */

ListNode *
reverseList(ListNode *pHead)
{
    ListNode *pReversedHead = NULL;
    ListNode *pNode = pHead;
    ListNode *pPrev = NULL;

    while (pNode != NULL) {
        ListNode *pNext = pNode->next;
        if (pNext == NULL) {
            pReversedHead = pNode;
        }

        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}


/*
 *------------------------------------------------------------------------------
 *
 * Merge two (small to large) linked list to one.
 *
 *------------------------------------------------------------------------------
 */

ListNode *
mergeList(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == NULL)
        return pHead2;
    else if (pHead2 == NULL)
        return pHead1;

    ListNode *pMergedHead = NULL;
    if (pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = mergeList(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = mergeList(pHead1, pHead2->next);
    }

    return pMergedHead;
}


/*
 *------------------------------------------------------------------------------
 *
 * Print a linked list.
 *
 *------------------------------------------------------------------------------
 */

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


/*
 *------------------------------------------------------------------------------
 *
 * Reversingly print a linked list.
 *
 *------------------------------------------------------------------------------
 */

void
printIntLinkedListReversingly_Recursively(ListNode *head)
{
    if (head == NULL) {
        return;
    }

    printIntLinkedListReversingly_Recursively(head->next);
    printf("%d  ", head->val);
}

void
printIntLinkedListReversingly_Iteratively(ListNode *head)
{
}


/*
 *------------------------------------------------------------------------------
 *
 * Test entry.
 *
 *------------------------------------------------------------------------------
 */

void
test_linkedList()
{
    ListNode *head = generateIntLinkedList(6, 1, 2, 3, 6, 5, 4);
    printIntLinkedList(head);
    printIntLinkedListReversingly_Recursively(head);

    printf("\n");
    printIntLinkedList(reverseList(head));

    ListNode *head1 = generateIntLinkedList(6, 1, 3, 5, 7, 9, 11);
    ListNode *head2 = generateIntLinkedList(5, 2, 4, 6, 8, 10);
    printIntLinkedList(mergeList(head1, head2));
}
