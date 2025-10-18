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
        head = tail = NULL;
    }

    // Reverse a Linked List
    void *reverseLinkedlist()
    {
        node *prev = NULL;
        node *current = head;
        node *nex = NULL;

        while (current != NULL)
        {
            nex = current->next;
            current->next = prev;

            prev = current;
            current = nex;
        }


        //For this question only
        head=prev;
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
    void traverseLinkedlist()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    List li;
    li.pushFront(10);
    li.pushFront(20);
    li.pushFront(30);
    li.reverseLinkedlist();
    li.traverseLinkedlist();

    return 0;
}