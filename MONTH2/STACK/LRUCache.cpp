#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    // USING DOUBLY LINKEDLIST AND UNORDERED MAP
    // LRU AT END OF DLL(TAIL SIDE)
    // LRU AT START OF DLL(HEAD SIDE)

    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> m;
    int limit;

    // Adding the node at head->next
    void *addNode(Node *newNode)
    {
        Node *oldnext = head->next;

        head->next = newNode;
        oldnext->prev = newNode;
        newNode->next = oldnext;
        newNode->prev = head;
    };
    void *deleteNode(Node *oldNode)
    {
        Node *oldnext = oldNode->next;
        Node *oldprev = oldNode->prev;

        oldnext->prev = oldprev;
        oldprev->next = oldnext;
    };

    LRUCache(int capacity)
    {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    { // tc->O(1)
    }

    void put(int key, int val)
    { // tc->O(1)

        // SUPPOSE NODE ALREADY EXIST
        if (m.find(key) != m.end())
        {
            Node *oldNode = m[key];
            delete (oldNode);
            m.erase(key);
        }

        // CAPACITY REACHED
        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node *newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};
int main()
{
    return 0;
}