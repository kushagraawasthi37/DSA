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
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
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
    int lengthOfList(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int n = lengthOfList(head);

        if (!head || !head->next)
        {
            return head;
        }
        k = k % n;
        k = n - k;

        if (k == 0)
        {
            return head;
        }
        ListNode *temp = head;

        while (k > 1)
        {
            temp = temp->next;
            k--;
        }

        ListNode *next = temp->next;
        temp->next = nullptr;
        temp = head;
        ListNode *tempHead = reverse(temp);
        ListNode *newNext = reverse(next);
        temp->next = newNext;
        head = reverse(tempHead);
        return head;
    }

    ListNode *rotateRightTUF(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Calculating length
        ListNode *temp = head;
        int length = 1;
        while (temp->next != nullptr)
        {
            ++length;
            temp = temp->next;
        }

        // Link last node to first node
        temp->next = head;
        // When k is more than length of list
        k = k % length;
        // To get end of the list
        int end = length - k;
        while (end-- > 0)
            temp = temp->next;

        // Breaking last node link and pointing to NULL
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

int main()
{

    return 0;
}