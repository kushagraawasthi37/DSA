#include <iostream>

/**
 * Definition for singly-linked list.
 */
class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle edge cases (e.g., deleting the head)
        ListNode *dummy = new ListNode(0, head);

        // Initialize pointers
        ListNode *slow = dummy; // Will point to the node before the one to delete
        ListNode *fast = dummy; // Used to create the n-step gap

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to delete
        ListNode *del = slow->next;
        slow->next = del->next;

        // Free memory of the deleted node
        delete del;

        // Return the new head
        ListNode *newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Example usage
int main()
{
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2); // Remove 2nd node from end

    std::cout << "After removal: ";
    printList(head);

    // Free remaining nodes
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
