#include <bits/stdc++.h>
using namespace std;

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
private:
    ListNode *reverseLinkedList(ListNode *head)
    {
        // 0 Node case
        if (!head)
        {
            return nullptr;
        }

        // 1 Node case
        if (!head->next)
        {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode *addOne(ListNode *head)
    {
        if (!head)
        {
            ListNode *newNode = new ListNode(1);
            return newNode;
        }

        head = reverseLinkedList(head);

        // ListNode *dummy = new ListNode();
        // dummy->next = head;
        ListNode *temp = head;
        ListNode *prev = head;
        int carry = 1;

        while (temp)
        {
            int sum = 0;
            sum = temp->val + carry;

            temp->val = sum % 10;
            carry = sum / 10;

            if (carry == 0)
            {
                return reverseLinkedList(head);
            }
            prev = temp;
            temp = temp->next;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }

        return reverseLinkedList(head);
    }

    int addHelperRecc(ListNode *head)
    {
        if (!head)
        {
            return 1;
        }

        int carry = addHelperRecc(head->next);

        head->val += carry;

        if (head->val < 0)
        {
            return 0;
        }

        head->val = 0;
        return 1;
    }

    ListNode *addOne(ListNode *head)
    {

        int carry = addHelperRecc(head);
        /*If there is a carry left
        after processing all nodes
        add a new node at the head */
        if (carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            /*Link the new node to the current head*/
            newNode->next = head;
            /*Update the head to the new node*/
            head = newNode;
        }
        // Return the head
        return head;
    }
};
int main()
{

    return 0;
}