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


class Solution
{

public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if (!head || !head->next)
        {
            return head;
        }

       head= reverse(head);

        Node *curr = head;
        Node *next = head->next;

        while (next != NULL)
        {
            bool nodedelete = false;
            if (curr->data > next->data)
            {
                Node *prev = curr;
                Node *temp = next;

                prev->next = temp->next;
                delete temp;
                nodedelete = true;
                next = curr->next;
            }

            if (!nodedelete)
            {
                curr = curr->next;
                next = next->next;
            }
        }

       head= reverse(head);
       return head;
    }
};
int main()
{
    return 0;
}