#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};

class Solution
{
public:
    // Function to clone the linked list
    ListNode *copyRandomList(ListNode *head)
    {
        // If the original list is empty, return null
        if (!head)
            return nullptr;

        // Insert nodes in between
        ListNode *temp = head;
        while (temp != NULL)
        {
            ListNode *nextElement = temp->next;
            // Create a new node with the same data
            ListNode *copy = new ListNode(temp->val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }

        temp = head;
        // Linking the random pointer
        while (temp != NULL)
        {
            // Access the copied node
            ListNode *copyNode = temp->next;

            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = NULL;
            }

            // Move to next original node
            temp = temp->next->next;
        }

        temp = head;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *res = dummyNode;

        while (temp != NULL)
        {

            res->next = temp->next;
            res = res->next;

            // Relinking the original and copied list
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
    ListNode *copyRandomListMap(ListNode *head)
    {

        unordered_map<ListNode *, ListNode *> mpp;
        ListNode *temp = head;

        // creating the node with cpy node mapping
        while (temp)
        {
            ListNode *newNode = new ListNode(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            ListNode *copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }
};

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};
*/

// Function to print the cloned linked list
void printClonedLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->val;
        if (head->random != nullptr)
        {
            cout << ", Random: " << head->random->val;
        }
        else
        {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}

int main()
{
    // Example linked list: 7 -> 14 -> 21 -> 28
    ListNode *head = new ListNode(7);
    head->next = new ListNode(14);
    head->next->next = new ListNode(21);
    head->next->next->next = new ListNode(28);

    // Assigning random pointers
    head->random = head->next->next;                   // 7 -> 21
    head->next->random = head;                         // 14 -> 7
    head->next->next->random = head->next->next->next; // 21 -> 28
    head->next->next->next->random = head->next;       // 28 -> 14

    // Print the original linked list
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Solution solution;
    ListNode *clonedList = solution.copyRandomList(head);

    // Print the cloned linked list
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
