#include <bits/stdc++.h>

using namespace std;

// Definition of doubly linked list
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
    // Function to delete all occurrences of a target value
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->val == target)
            {
                // Update head if needed
                if (temp == head)
                {
                    head = temp->next;
                }

                ListNode *nextNode = temp->next;
                ListNode *prevNode = temp->prev;

                // Update next node's previous
                if (nextNode != NULL)
                {
                    nextNode->prev = prevNode;
                }

                // Update previous node's next
                if (prevNode != NULL)
                {
                    prevNode->next = nextNode;
                }

                // Delete the current node
                delete temp;
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
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
    // Creating doubly linked list
    ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Delete all occurrences of 2
    Solution sol;
    head = sol.deleteAllOccurrences(head, 2);

    // Print modified list
    cout << "Modified list: ";
    printList(head);

    return 0;
}