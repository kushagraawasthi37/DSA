#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
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
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head || head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        ListNode *oddptr = head;
        ListNode *evenptr = head->next;

        while (oddptr)
        {
            ListNode *newNode = new ListNode(oddptr->val);

            if (oddptr->next)
            {
                oddptr = oddptr->next->next;
            }
            else
            {
                oddptr = oddptr->next;
            }

            temp->next = newNode;
            temp = newNode;
        }

        while (evenptr)
        {
            ListNode *newNode = new ListNode(evenptr->val);

            if (evenptr->next)
            {
                evenptr = evenptr->next->next;
            }
            else
            {
                evenptr = evenptr->next;
            }
            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
};
int main()
{

    return 0;
}