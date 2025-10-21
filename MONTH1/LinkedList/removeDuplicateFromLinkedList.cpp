#include <bits/stdc++.h>

using namespace std;

// Definition of Single Linked List
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    // To remove duplicates from a sorted doubly linked list
    ListNode *removeDuplicates(ListNode *head)
    {
        if (!head->next)
        {
            return head;
        }
        ListNode *temp = head->next;
        auto prev = head;
        while (temp)
        {
            if (prev->val == temp->val)
            {
                temp = temp->next;
                continue;
            }

            prev->next = temp;
            temp->prev = prev;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

// Function to print doubly linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode *newNode(int data)
{
    ListNode *node = new ListNode(data);
    return node;
}

int main()
{
    // Creating a sorted doubly linked list:
    ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(2);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    Solution sol;
    head = sol.removeDuplicates(head);

    // Print modified list
    cout << "Modified list: ";
    printList(head);

    return 0;
}