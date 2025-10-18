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

    // Floyd's Cycle-Finding Algorithm (Tortoise and Hare algorithm)
    bool hasCycle()
    {
        node *slow = head;
        node *fast = head;

        // Detect Cycle in LinkedList

        while (fast != NULL /*even List end*/ && fast->next != NULL /*Odd list*/)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    // Remove cycle in Linked List
    int detectCycleStartPoint()
    {
        node *slow;
        node *fast;
        node *fastprev;

        bool isCycle = false;
        while (fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        slow = head;
        // After second step ye mathimatical proved hai ki ye dono same point ko point krenge jo repeating hoga
        if (isCycle)
        {
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
                // slow and fast point to cycle starting point
            }
            return slow->data;
        }
        else
        {
            return -1;
        }
    }
    int cycleRemove()
    {
        node *slow;
        node *fast;
        node *fastprev;

        bool isCycle = false;
        while (fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        slow = head;
        // After second step ye mathimatical proved hai ki ye dono same point ko point krenge jo repeating hoga
        if (isCycle)
        {
            while (slow != fast)
            {
                slow = slow->next;
                fastprev = fast;
                fast = fast->next;
            }
            // slow and fast point to cycle starting point

            //Remove hogyi cycle
            fastprev->next = NULL;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    return 0;
}