#include <stdarg.h>
#include <stdio.h>
#include <stack>

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
 * Free the memory of linked list nodes.
 *
 *------------------------------------------------------------------------------
 */

void
freeLinkedList(ListNode *pHead)
{
    while (pHead != NULL) {
        ListNode *pNode = pHead;
        pHead = pHead->next;
        delete pNode;
    }
}


/*
 *------------------------------------------------------------------------------
 *
 * Usually used operations.
 *
 *------------------------------------------------------------------------------
 */

ListNode *
getLinkedListTail(ListNode *pHead)
{
    if (pHead == NULL)
        return NULL;
    ListNode *pTail = pHead;
    while (pTail->next != NULL) {
        pTail = pTail->next;
    }

    return pTail;
}

int
getLinkedListLength(ListNode *pHead)
{
    int length = 0;
    while (pHead != NULL) {
        pHead = pHead->next;
        length++;
    }

    return length;
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
printIntLinkedList(ListNode *pHead)
{
    ListNode *p = pHead;

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
printIntLinkedListReversingly_Recursively(ListNode *pHead)
{
    if (pHead == NULL) {
        return;
    }

    printIntLinkedListReversingly_Recursively(pHead->next);
    printf("%d  ", pHead->val);
}

void
printIntLinkedListReversingly_Iteratively(ListNode *pHead)
{
    std::stack<ListNode *> nodes;
    ListNode *pNode = pHead;

    while (pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d  ", pNode->val);
        nodes.pop();
    }
}


/*
 *------------------------------------------------------------------------------
 *
 * Judge a linked list has a loop or not;
 * Find the entry node of the loop if any.
 *
 *------------------------------------------------------------------------------
 */

ListNode *
meetingNode(ListNode *pHead)
{
    ListNode *pFast = pHead;
    ListNode *pSlow = pHead;

    while (pFast && pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast) {
            return pFast;
        }
    }

    return NULL;
}

bool
hasLoopInLinkedList(ListNode *pHead)
{
    return meetingNode(pHead) != NULL;
}

ListNode *
entryNodeOfLoop(ListNode *pHead)
{
    ListNode *pAhead = meetingNode(pHead);
    if (pAhead == NULL)
        return NULL;
    ListNode *pBehind = pHead;

    while (pBehind != pAhead) {
        pBehind = pBehind->next;
        pAhead = pAhead->next;
    }

    return pBehind;
}


/*
 *------------------------------------------------------------------------------
 *
 * Test cases.
 *
 *------------------------------------------------------------------------------
 */

void
test_printLinkedListReversingly()
{
    ListNode *head = generateIntLinkedList(6, 1, 2, 3, 6, 5, 4);
    printIntLinkedList(head);
    printIntLinkedListReversingly_Recursively(head);
    printf("\n");
    printIntLinkedListReversingly_Iteratively(head);
    printf("\n");

    printIntLinkedList(reverseList(head));
    freeLinkedList(head);
}

void
test_mergeLinkedList()
{
    ListNode *head1 = generateIntLinkedList(6, 1, 3, 5, 7, 9, 11);
    ListNode *head2 = generateIntLinkedList(5, 2, 4, 6, 8, 10);
    ListNode *mergedHead = mergeList(head1, head2);
    printIntLinkedList(mergedHead);
    freeLinkedList(mergedHead);
}

void
test_loopInLinkedList()
{
    ListNode *head = generateIntLinkedList(6, 1, 2, 3, 4, 5, 6);
    ListNode *node3 = head->next->next;
    ListNode *tail = getLinkedListTail(head);
    tail->next = node3;

    printf("meeting node: %d\n", meetingNode(head)->val);
    printf("entry node: %d\n", entryNodeOfLoop(head)->val);

    tail->next = NULL; // must make it a real tail and then use freeLinkedList
    freeLinkedList(head);
}

void
test_getLength()
{
    ListNode *head = generateIntLinkedList(6, 1, 2, 3, 4, 5, 6);
    printf("length: %d\n", getLinkedListLength(head));
    freeLinkedList(head);
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
    test_printLinkedListReversingly();
    test_mergeLinkedList();
    test_loopInLinkedList();
    test_getLength();
}
