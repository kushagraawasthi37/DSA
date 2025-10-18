#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node *child;

    node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
        child = NULL;
        prev = NULL;
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

    node *flaten(node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        node *currentNode = head;

        while (currentNode != NULL)
        {

            // IF child exist
            if (currentNode->child != NULL)
            {
                // FLATEN THE CHILD NODE

                // Initial next ko store karega
                node *nextNode = currentNode->next;

                // LINKING NODES
                currentNode->next = flaten(currentNode->child);
                currentNode->next->prev = currentNode;

                // SETTING CHILD NODE NULL
                currentNode->child = NULL;

                // FIND TAIL OF CHILD NODES
                while (currentNode->next != NULL)
                {
                    currentNode = currentNode->next;
                }

                // ATTACH TAIL WITH NEXT POINTER
                if (nextNode != NULL)
                {
                    currentNode->next = nextNode;
                    nextNode->prev = currentNode;
                }
            }

            // If child is NULL
            currentNode = currentNode->next;
        }

        return head;
    }
};
int main()
{
    return 0;
}