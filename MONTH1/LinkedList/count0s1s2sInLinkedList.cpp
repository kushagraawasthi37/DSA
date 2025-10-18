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
    ListNode *sortList(ListNode *head)
    {
        ListNode *temp = head;
        int zeroCnt = 0;
        int onesCnt = 0;
        int twoCnt = 0;

        while (temp != nullptr)
        {
            if (temp->val == 0)
            {
                zeroCnt++;
            }
            else if (temp->val == 1)
            {
                onesCnt++;
            }
            else
            {
                twoCnt++;
            }
            temp = temp->next;
        }

        temp = head;

        while (zeroCnt > 0 && temp)
        {
            temp->val = 0;
            zeroCnt--;
            temp = temp->next;
        }
        while (onesCnt > 0 && temp)
        {
            temp->val = 1;
            onesCnt--;
            temp = temp->next;
        }
        while (twoCnt > 0 && temp)
        {
            temp->val = 2;
            twoCnt--;
            temp = temp->next;
        }

        return head;
    }
};

int main()
{

    return 0;
}