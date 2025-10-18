#include <bits/stdc++.h>
using namespace std;
class CircularQueue
{
public:
    int *arr;
    int curSize = 0, capacity;
    int f, r;

    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        f = 0;
        r = -1;
    }

    void push(int val)
    { // TC ->O(1)

        if (curSize != capacity)
        {
            r = (r + 1) % capacity;
            arr[r] = val;
            curSize++;
        }
        else
        {
            cout << "NO SPACE IN QUEUE";
            cout << endl;
            return;
        }
    }
    void pop()
    {
        // TC ->O(1)
        if (curSize == 0)
        {
            cout << "ALREADY EMPTY QUEUE";
            cout << endl;
        }
        else
        {
            f = (f + 1) % capacity;
            curSize--;
        }
    }

    int front()
    { // TC ->O(1)
        if (curSize == 0)
        {
            return -1;
        }

        return arr[f];
    }

    bool empty()
    {                        // TC ->O(1)
        return curSize == 0; // AGAR CURRENT SIZE 0 HOGA TO YE TRUE DEGA BARNA FALSE
    }
};

//  One function that prints and dequeues
void printAndDequeue(CircularQueue *cq)
{
    cout << "Printing and Dequeuing:\n";
    while (!cq->empty())
    {
        cout << cq->front() << " ";
        cq->pop();
    }
    cout << endl;
}

int main()
{
    CircularQueue *cq = new CircularQueue(4);
    cq->push(1);
    cq->push(2);
    cq->push(3);
    cq->push(4);

    printAndDequeue(cq);
    return 0;
}