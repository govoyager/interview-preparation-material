#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char key;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;

    temp->key = data;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *insert(Node *root, char key)
{
    Node *newnode = newNode(key);
    Node *x = root;
    Node *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = newnode;
    else if (key < y->key)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}


struct Node *search(struct Node *root, char key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{

    Node *root = NULL;
    cout << "\nEnter a char element for root: ";
    char e;
    cin >> e;
    root = insert(root, e);


    while (1)
    {
        
        cout << "\nEnter 1 to insert a char element: ";
        cout << "\nEnter 2 to search an element";
        cout << "\nEnter 3 to show inorder traversal";
        cout << "\nEnter 4 to quit";
        cout << "\n-->";
        int option;
        cin >> option;
        if (option == 1)
        {
            cout << "Enter the char to insert: ";
            char element;
            cin >> element;
            insert(root, element);
        
        }
        else if (option == 2)
        {
            cout << "\nEnter the char to search: ";
            char a;
            cin >> a;
            cout << "\nlocation of the element: " << search(root, a);
             
        }
        else if (option == 3)
        {
        
        }
    
    }
    return 0;
}