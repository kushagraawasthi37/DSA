#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    node *head;
    node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    node *reverseNodeKGroup(node *head, int k)
    {

        // CHECK IF K NODE EXIST OR NOT
        int count = 0;
        node *temp = head;
        while (count < k)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
            count++;
        }

        // RECURSIVELY FOR REST OF LINKED LIST IF K GROUP EXIST
        node *newNextNode = reverseNodeKGroup(temp, k);

        // REVERSE THE CURRENT GROUP
        temp = head;
        count = 0;

        while (count < k)
        {
            // SIMPLE LINKING OF NODE TRY ON COPY
            node *oldNextNode = temp->next;
            temp->next = newNextNode;
            newNextNode = temp;
            temp = oldNextNode;

            count++;;
        }
        return newNextNode;
    }
};

int main()
{
    return 0;
}