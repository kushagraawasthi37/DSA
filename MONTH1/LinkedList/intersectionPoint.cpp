#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *intersectPoint(Node *head1, Node *head2)
{

    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    unordered_map<Node *, bool> map;
    Node *temp1 = head1;
    Node *temp2 = head2;

    // Storing the One list in unordere_map
    while (temp1)
    {
        map[temp1] = true;
        temp1 = temp1->next;
    }

    temp1 = head1;

    while (temp2)
    {
        if (map.find(temp2) != map.end())
            return temp2;

        temp2 = temp2->next;
    }

    return NULL;
}

int main()
{
    return 0;
}