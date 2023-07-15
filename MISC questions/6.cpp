//Program for reversing the linked list using recursion
//For simplicity all the elments from the input are added to the starting of linked list

#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int data; 
    Node *next, *prev; 
}; 
  

void addNode(Node **temp_head,int data) 
{ 
    Node* new_node = new Node; 
    new_node->data = data; 
    new_node->prev = NULL; 

    new_node->next = (*temp_head); 
  

    if ((*temp_head) != NULL) 
        (*temp_head)->prev = new_node; 

    (*temp_head) = new_node; 
} 

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node* reverse(Node *temp)
{
    if(temp == NULL)
    return NULL;

    Node *temp1 = temp->prev;
    temp->prev = temp->next;
    temp->next = temp1;

    if(temp->prev == NULL)
    return temp;

    return(reverse(temp->prev));

}
  
int main()
{
    int n;
    cout<<"Enter the number of data: ";
    cin>>n;
    
    Node *head = NULL;
    cout<<"Enter all the data elements: ";
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        addNode(&head,a);
    }
    cout<<"\n Before reversing: ";
    printList(head);
    head = reverse(head);
    cout<<"\n After reversing: ";
    printList(head);

}