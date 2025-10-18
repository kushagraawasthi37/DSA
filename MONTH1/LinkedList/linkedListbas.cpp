#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Implementation of LL
class node
{
    // Creating the structure of node
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

    // Adding Node in Begining
    void pushFront(int val)
    {
        //TC->O(1)

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

    // Adding in last of linked list
    void pushBack(int val)
    {
        //TC->O(1) because of tail otherwise O(n)

        // Creating new node
        node *newnode = new node(val);
        if (tail == NULL)
        {
            tail = newnode;
        }
        else
        {
            // Connecting to tail
            tail->next = newnode;
            // Update head
            tail = newnode;
        }
    }
    // Adding in Between of linked list
    void pushBetween(int val, int pos)
    {
        //TC->O(pos)

        // Creating new node
        node *newnode = new node(val);
        node *temp = head;
        if (pos < 0)
        {
            return;
        }
        // condtion of Add node at start
        if (pos == 0)
        {
            // Connecting to head
            newnode->next = head;
            // Update head
            head = newnode;
        }
        while (pos > 0)
        {
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // deleting First node
    void popFront()
    {
        //TC->O(1)

        if (head == NULL)
        {
            cout << "Already Linked List empty " << endl;
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    // deleting last node
    void popBack()
    {
        //TC->O(n)

        node *temp = head;
        if (head == NULL)
        {
            cout << "Empty LL" << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = NULL;
        }

        // End se 1 pos pahele tak leke ja rhe hai
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void popBetween(int pos)
    {
        //TC->O(pos)

        node *p = head;
        node *q = head->next;
        while (pos > 1)
        {
            p = p->next;
            q = q->next;
            pos--;
        }

        p->next = q->next;
    }

    // Printing Linked List
    void traverseLinkedlist()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int searchLinkedList(int key)
    {
        //TC->O(n)

        int idx = -1;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
        }

        return idx;
    }
};

int main()
{
    List li;
    li.pushFront(10);
    li.pushFront(20);
    li.pushFront(30);
    li.pushBack(0);
    li.pushBack(-10);
    li.popFront();
    li.popBack();
    li.pushBetween(-10, 2);
    li.popBetween(2);
    cout<<li.searchLinkedList(10);

    li.traverseLinkedlist();

    return 0;
}