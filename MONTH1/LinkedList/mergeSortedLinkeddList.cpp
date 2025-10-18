#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    node *head;
    node *tail;

public:
    List()
    {
        tail = head = NULL;
    }
    void pushFront(int val)
    {
        // TC->O(1)

        // Creating new node
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            // Connecting to head
            newnode->next = head;
            // Update head
            head = newnode;
        }
    }

public:
    node *mergeSortedLL(node *h1, node *h2)

    // TC->O(m+n)
    // SC->O(m+n)
    {
        if (h1->data <= h2->data)
        {
            h1->next = mergeSortedLL(h1->next, h2);
            return h1;
        }
        else 
        {
            h2->next = mergeSortedLL(h1, h2->next);
            return h2;
        }
        if (h1 == NULL)
        {
            return h2;
        }
        else
        {
            return h1;
        }
        // return h1==NULL? h2:h1; //Ternary operator
    }
};
int main()
{
    return 0;
}