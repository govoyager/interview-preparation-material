#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int n1 = 0;
    int n2 = 0;
    ListNode *temp = headA;
    while (temp != NULL)
    {
        n1 += 1;
        temp = temp->next;
    }
    temp = headB;
    while (temp != NULL)
    {
        n2 += 1;
        temp = temp->next;
    }
    ListNode *a = headA;
    ListNode *b = headB;
    int diff = abs(n1 - n2);
    if (n1 > n2)
    {
        temp = headA;
        while (diff)
        {
            temp = temp->next;
            diff -= 1;
        }
        a = temp;
    }
    else if (n2 > n1)
    {
        temp = headB;
        while (diff)
        {
            temp = temp->next;
            diff -= 1;
        }
        b = temp;
    }
    while (a != b)
    {
        a = a->next;
        b = b->next;
    }
    return a;
}