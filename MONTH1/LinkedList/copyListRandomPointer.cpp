#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *random;

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

    node *copyListWithRandomPointer()
    {
        if (head == NULL)
        {
            return NULL;
        }
        unordered_map<node *, node *> m;

        // Create a Copy of List
        node *newHead = new node(head->data);
        node *oldTemp = head->next;
        node *newTemp = newHead;

        m[head] = newHead;

        while (oldTemp != NULL)
        {
            node *copyNode = new node(oldTemp->data);
            // Map mai bhi Insert kr rhe hai
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Copy Linked List ban gyi aab random par point karna hai

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL)
        {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};
int main()
{
    return 0;
}