#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int val)
    {
        next = bottom = NULL;
        data = val;
    }
};
Node *merge(Node *a, Node *b)
{
    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    Node *result;

    if (a->data < b->data)
    {
        result = a;
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        b->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

// Function which returns the  root of the flattened linked list.
Node *flatten(Node *root)
{
    // Your code
       if(!root){
        return root;
       }

       //End se start kro
       root->next=flatten(root->next);
       
       root=merge(root,root->next);
       
       return root;
}

int main()
{
    return 0;
}