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

    node *swapNode(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *prev = NULL;
        node *first = head;
        node *sec = head->next;
        while (first != NULL || first->next == NULL)
        {
            node *third = sec->next;

            sec->next = first;
            first->next = third;
            if (prev == NULL)
            {
                head=sec;
            }
            else
            {
                prev->next = sec;
            }

            // UPDATE
            prev = first;
            first = third;
            if (third != NULL)
            {
                sec = third->next;
            }
            else
            {
                sec = NULL;
            }
        }
    }
};

int main()
{
    return 0;
}