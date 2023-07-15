#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
};
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    int n = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        n += 1;
        temp = temp->next;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    k = k % n;
    if (k == 0)
    {
        return head;
    }
    k = n - k - 1;
    temp->next = head;
    temp = head;
    while (k)
    {
        temp = temp->next;
        k -= 1;
    }

    head = temp->next;
    temp->next = NULL;
    return head;
}