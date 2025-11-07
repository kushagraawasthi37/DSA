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
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode *getKthNode(ListNode *temp, int k)
    {
        while (temp != NULL && k > 1)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // Function to reverse nodes in groups of K
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevNode = nullptr;

        while (temp)
        {
            ListNode *kthNode = getKthNode(temp, k);

            if (!kthNode)
            {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            else
            {
                ListNode *nextNode = kthNode->next;
                kthNode->next = nullptr;
                reverseLinkedList(temp);

                if (temp == head)
                {
                    head = kthNode;
                }
                else
                {
                    prevNode->next = kthNode;
                }

                prevNode = temp;
                temp = nextNode;
            }
        }
        return head;
    }
};
int main()
{

    return 0;
}