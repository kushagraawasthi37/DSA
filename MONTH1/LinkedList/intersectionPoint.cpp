#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNodeBetter(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        int m = 0;
        int n = 0;

        while (temp1)
        {
            temp1 = temp1->next;
            m++;
        }

        while (temp2)
        {
            temp2 = temp2->next;
            n++;
        }
        temp1 = headA;
        temp2 = headB;
        int diff = abs(m - n);

        if (m > n)
        {
            while (diff > 0)
            {
                if (temp1)
                    temp1 = temp1->next;
                diff--;
            }
        }
        else
        {
            while (diff > 0)
            {
                if (temp2)
                    temp2 = temp2->next;
                diff--;
            }
        }

        while (temp1 && temp2)
        {
            if (temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNodeOptimal(ListNode *headA, ListNode *headB)
    {
        // Edge case
        if (!headA || !headB)
        {
            return nullptr;
        }

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        // Not checking the value it is checking the full node
        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            // Intersection exist
            if (temp1 == temp2)
            {
                return temp1;
            }

            if (!temp2)
                temp2 = headA;
            if (!temp1)
                temp1 = headB;
        }
    }
};

Node *intersectPoint(Node *head1, Node *head2)
{

    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    unordered_map<Node *, bool> map;
    Node *temp1 = head1;
    Node *temp2 = head2;

    // Storing the One list in unordere_map
    while (temp1)
    {
        map[temp1] = true;
        temp1 = temp1->next;
    }

    temp1 = head1;

    while (temp2)
    {
        if (map.find(temp2) != map.end())
            return temp2;

        temp2 = temp2->next;
    }

    return NULL;
}

int main()
{
    return 0;
}