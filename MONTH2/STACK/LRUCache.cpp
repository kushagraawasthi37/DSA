#include <bits/stdc++.h>
using namespace std;

/* Class to implement Nodes
of a doubly linked list */
class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    // Constructors
    Node()
    {
        key = val = -1;
        next = prev = NULL;
    }

    Node(int k, int value)
    {
        key = k;
        val = value;
        next = prev = NULL;
    }
};

// Class implementing LRU cache
class LRUCache
{
private:
    map<int, Node *> mpp; // Map data structure
    int cap;              // Capacity
    Node *head;           // Dummy head pointer
    Node *tail;           // Dummy tail pointer

    /* Private method to delete node
    from doubly linked list */
    void deleteNode(Node *node)
    {

        // Get the previous and next pointers
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        // Remove pointers to node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Private method to insert node after head
    void insertAfterHead(Node *node)
    {

        Node *nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }

public:
    // Method to initialise cache with given capacity
    LRUCache(int capacity)
    {
        cap = capacity; // Set the capacity
        mpp.clear();    // Clear the cache

        head = new Node();
        tail = new Node();

        // Make the connections
        head->next = tail;
        tail->prev = head;
    }

    // Method to get the key from cache
    int get(int key_)
    {
        // Return -1 if it is not present in cache
        if (mpp.find(key_) == mpp.end())
            return -1;

        Node *node = mpp[key_]; // Get the node
        int val = node->val;    // Get the value

        // Delete the node
        deleteNode(node);
        /* Insert this node to front
        as it was recently used */
        insertAfterHead(node);

        // Return the stored value
        return val;
    }

    /* Method to update value is key exists,
    otherwise insert the key-value pair */
    void put(int key_, int value)
    {

        // Update the value if key is already present
        if (mpp.find(key_) != mpp.end())
        {

            Node *node = mpp[key_]; // Get the node
            node->val = value;      // Update the value

            // Delete the node
            deleteNode(node);

            /* Insert this node to front
            as it was recently used */
            insertAfterHead(node);

            return;
        }

        // Check if the capacity limit has reached
        if (mpp.size() == cap)
        {

            // Get the least recently used node
            Node *node = tail->prev;

            
            // Delete node from map
            mpp.erase(node->key);

            // Delete node from doubly linked list
            deleteNode(node);
        }

        // Create a new node
        Node *newNode = new Node(key_, value);

        // Insert it in map
        mpp[key_] = newNode;

        // Insert in doubly linked list
        insertAfterHead(newNode);
    }
};

int main()
{
    // LRU Cache
    LRUCache cache(2);

    // Queries
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cache.put(4, 4);
    cout << cache.get(1) << " ";
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";

    return 0;
}