#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *reverseListIteratively(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    ListNode *prev = head;
    head = head->next;
    prev->next = NULL;
    while (head != NULL)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
