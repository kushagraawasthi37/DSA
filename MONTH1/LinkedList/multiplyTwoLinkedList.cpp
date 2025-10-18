/* Multiply contents of two linked lists */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    const int MOD = 1000000007;

    long long multiplyTwoLists(Node *first, Node *second)
    {
        if (!first || !second)
            return 0;

        long long num1 = 0, num2 = 0;

        Node *temp = first;
        while (temp != NULL)
        {
            num1 = (num1 * 10 + temp->data) % MOD;
            temp = temp->next;
        }

        Node *temp1 = second;
        while (temp1 != NULL)
        {
            num2 = (num2 * 10 + temp1->data) % MOD;
            temp1 = temp1->next;
        }

        return (num1 * num2) % MOD;
    }
};
