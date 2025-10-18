#include <bits/stdc++.h>
#include <queue>
#include <deque>
using namespace std;

// QUEUE FIRST IN FIRST OUT (FIFO) PUSH->REAR,POP-> FRONT,FRONT ALL TC->O(1)

// Queue using Linked-List

// We can also create the linkedlist by c++ STL but here we create by own
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

class Queue
{
    node *head;
    node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    // ALL IN TC->O(1)

    void enqueue(int val)
    {
        // PUSH ALWAYS FROM THE REAR END (TAIL END)
        node *newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue Already empty ";
            return;
        }
        node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete temp;
    }
    int front()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;

    // QUEUE USING C++ STL

    queue<int> q1;
    q1.push(1);
    q1.push(1);
    q1.push(1);
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    // DEQUE(DOUBLE ENDED QUEUE)
    // PUSH(FRONT/REAR)
    // POP(FRONT/REAR)

    deque<int> dq;

    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    return 0;
}