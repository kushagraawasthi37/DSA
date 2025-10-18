#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLList
{
    node *head;
    node *tail;

public:
    DLList()
    {
        head = tail = NULL;
    }

    void *pushFront(int val)
    {
        node *newNode = new node(val);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        return newNode;
    }
    void *pushBack(int val)
    {
        node *newNode = new node(val);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "Empty LL";
            return;
        }
        else
        {
            if (head == tail)
            {
                head = tail = NULL;
            }

            node *temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        return;
    }
    void popBack()
    {
        if (tail == NULL)
        {
            cout << "Empty LL";
            return;
        }
        else
        {
            if (head == tail)
            {
                head = tail = NULL;
            }

            node *temp = tail;
            tail =tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        return;
    }

    // Print Doubly LinkedList

    void traverseLinkedList()
    {
        node *temp = head;
        if (head == NULL)
        {
            cout << "Linked List Empty " << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    DLList dl;
    // dl.pushFront(10);
    // dl.pushFront(20);
    // dl.pushFront(30);
    // dl.pushBack(0);
    dl.pushBack(-10);
    dl.popFront();
    dl.popBack();

    dl.traverseLinkedList();
    return 0;
}