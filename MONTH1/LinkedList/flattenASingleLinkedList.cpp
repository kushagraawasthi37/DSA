
#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution
{

public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        ListNode *dummy = new ListNode();
        ListNode *res = dummy;

        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                res->child = temp1;
                res = temp1;
                temp1 = temp1->child;
            }
            else
            {
                res->child = temp2;
                res = res->child;
                temp2 = temp2->child;
            }
        }

        if (temp1)
        {
            res->child = temp1;
        }
        if (temp2)
        {
            res->child = temp2;
        }

        return dummy->child;
    }

    ListNode *solve(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *mergehead = solve(head->next);

        return merge(mergehead, head);
    }

    ListNode *flattenLinkedList(ListNode *&head)
    {
        return solve(head);
    }

    ListNode *convertArrToLinkedList(vector<int> &arr)
    {
        /* Create a dummy node to serve as
         the head of the linked list */
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        /* Iterate through the vector and
         create nodes with vector elements */
        for (int i = 0; i < arr.size(); i++)
        {
            // Create a new node with the vector element
            temp->child = new ListNode(arr[i]);

            // Update the temporary pointer
            temp = temp->child;
        }

        /* Return the linked list starting
         from the next of the dummy node */
        return dummyNode->child;
    }

    // Function to flatten a linked list with child pointers
    ListNode *flattenLinkedListBr(ListNode *head)
    {
        vector<int> arr;

        // Traverse through the linked list
        while (head != nullptr)
        {
            /* Traverse through the child
             nodes of each head node */
            ListNode *t2 = head;

            while (t2 != nullptr)
            {
                // Store each node's data in the array
                arr.push_back(t2->val);

                // Move to the next child node
                t2 = t2->child;
            }
            // Move to the next head node
            head = head->next;
        }

        // Sort the array containing node values
        sort(arr.begin(), arr.end());

        // Convert the sorted array back to a linked list
        return convertArrToLinkedList(arr);
    }
};

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    // Create a linked list with child pointers
    ListNode *head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Creating an instance of Solution class
    Solution sol;

    // Function call to flatten the linked list
    ListNode *flattened = sol.flattenLinkedList(head);

    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}