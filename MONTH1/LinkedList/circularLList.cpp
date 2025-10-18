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
class CLL
{
    node *head;
    node *tail;

public:
    CLL()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        node *newnode = new node(val);
        if (head == NULL && tail == NULL)
        {
            newnode->next = newnode;
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }
    }
    void insertAtTail(int val)
    {
        node *newnode = new node(val);
        if (head == NULL || tail == NULL)
        {
            newnode->next = newnode;
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }
    void deleteAtTail()
    {
        if (head == NULL || tail == NULL)
        {
            cout << "Empty Linked List " << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *prev = head;
            node *temp = tail;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void deleteAtStart()
    {
        if (head == NULL || tail == NULL)
        {
            cout << "Empty Linked List " << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void printCirLL()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List " << endl;
            return;
        }
        node *temp = head;
        do
        {
            cout << temp->data << " => ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }
};
int main()
{
    CLL cl;
    cl.insertAtHead(10);
    cl.insertAtHead(20);
    cl.insertAtHead(30);
    cl.insertAtTail(00);
    cl.insertAtTail(-10);
    cl.deleteAtStart();
    cl.deleteAtTail();
    cl.printCirLL();
    return 0;
}