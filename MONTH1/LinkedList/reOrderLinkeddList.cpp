#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};
class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution
{
public:
    int nodeCount(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }

    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        int total = nodeCount(head);
        int flist = total / 2; // ✅ correct split index

        // move to second half
        ListNode *temp = head;
        for (int i = 0; i < flist; i++)
        {
            temp = temp->next;
        }

        // push second half into stack
        stack<ListNode *> s;
        while (temp)
        {
            s.push(temp);
            temp = temp->next;
        }

        ListNode *curr = head;
        ListNode *nextNode = head->next;

        // interleave
        while (!s.empty() && nextNode)
        {
            ListNode *lastNode = s.top();
            s.pop();

            ListNode *tmpNext = nextNode->next; // ✅ safe store

            curr->next = lastNode;
            lastNode->next = nextNode;

            curr = nextNode;
            nextNode = tmpNext;
        }

        // if odd length, one middle node may remain
        if (!s.empty())
        {
            curr->next = s.top();
            s.pop();
            curr = curr->next;
        }

        curr->next = nullptr; // ✅ terminate
    }

    /****************************************Method 2 TC->O(N) AND SC->O(1)************************/
    void reorderList2(Node *head)
    {
        if (!head || !head->next)
            return;

        // 1. Find middle using slow-fast pointer
        Node *slow = head;
        Node *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        Node *prev = nullptr;
        Node *curr = slow->next;
        while (curr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = nullptr; // cut first half

        // 3. Merge two halves
        Node *first = head;
        Node *second = prev; // head of reversed second half
        while (second)
        {
            Node *tmp1 = first->next;
            Node *tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }


    void reorderListStack(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        stack<ListNode*> st;
        // Middle element found successfully
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Stack Store

        // Even no of node
        if (fast == nullptr) {
            while (slow) {
                st.push(slow);
                slow = slow->next;
            }
        }
        // Odd number of node
        else {
            while (slow->next) {
                slow = slow->next;
                st.push(slow);
            }
        }

        while (!st.empty()) {
            ListNode* nextNode = temp->next;
            ListNode* topNode = st.top();
            temp->next = topNode;
            topNode->next = nextNode;
            temp = nextNode;
            st.pop();
        }

        temp->next = nullptr;
    }

};
