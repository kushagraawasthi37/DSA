#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode(int val)
    {
        next = bottom = NULL;
        this->val = val;
    }
};

bool isPalindrome(ListNode *head)
{
    //  code here

    ListNode *temp = head;
    stack<ListNode *> s;

    // Adding element in stack
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }

    ListNode *temp1 = head;

    while (!s.empty())
    {
        temp = s.top();
        if (temp1->val != temp->val)
        {
            return false;
        }
        temp1 = temp1->next;
        s.pop();
    }

    return true;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr; // Pehle koi previous node nahi hai
    ListNode *curr = head;    // Current node head se start

    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next; // Next node temporarily store karo
        curr->next = prev;               // Reverse pointer
        prev = curr;                     // Move prev aage
        curr = nextNode;                 // Move current aage
    }

    return prev; // prev will be new head
}

// Function to check if linked list is palindrome
bool isPalindromeOpti(ListNode *head)
{
    if (!head || !head->next)
        return true; // Ek ya zero node ho to true

    // 1️⃣ Find middle of the linked list using slow-fast pointer
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Slow moves 1 step
        fast = fast->next->next; // Fast moves 2 steps
    }
    // Ab slow second half ke start pe hai

    // 2️⃣ Reverse second half of the list
    ListNode *secondHalf = reverseList(slow);

    // 3️⃣ Compare first half and reversed second half
    ListNode *firstHalf = head;
    ListNode *check = secondHalf;
    while (check != nullptr)
    {
        if (firstHalf->val != check->val)
        {
            return false; // Agar koi mismatch, return false
        }
        firstHalf = firstHalf->next;
        check = check->next;
    }

    // 4️⃣ (Optional) Restore the list by reversing second half again
    // reverseList(secondHalf);

    return true; // Sab match ho gaye, palindrome hai
}

// Helper function to print linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val;
        if (curr->next != nullptr)
            std::cout << " -> ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    return 0;
}