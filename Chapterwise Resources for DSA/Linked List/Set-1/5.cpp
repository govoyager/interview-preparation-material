#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
};

ListNode *oddEvenList(ListNode *head)
{
    ListNode *first = head;
    if (head == NULL or head->next == NULL)
        return head;
    ListNode *second = head->next;
    ListNode *curr = second->next;
    ListNode *head1 = first;
    ListNode *head2 = second;
    while (curr != NULL)
    {
        first->next = curr;
        first = curr;
        curr = curr->next;
        if (curr != NULL)
        {
            second->next = curr;
            second = curr;
            curr = curr->next;
        }
    }
    first->next = head2;
    second->next = NULL;
    return head1;
}