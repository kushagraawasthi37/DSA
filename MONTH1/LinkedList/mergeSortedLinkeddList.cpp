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

struct ListNode
{
    int val;
    ListNode *next;
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

class List
{
    node *head;
    node *tail;

public:
    List()
    {
        tail = head = NULL;
    }
    void pushFront(int val)
    {
        // TC->O(1)

        // Creating new node
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            // Connecting to head
            newnode->next = head;
            // Update head
            head = newnode;
        }
    }

public:
    node *mergeSortedLL(node *h1, node *h2)

    // TC->O(m+n)
    // SC->O(m+n)
    {
        if (h1->data <= h2->data)
        {
            h1->next = mergeSortedLL(h1->next, h2);
            return h1;
        }
        else
        {
            h2->next = mergeSortedLL(h1, h2->next);
            return h2;
        }
        if (h1 == NULL)
        {
            return h2;
        }
        else
        {
            return h1;
        }
        // return h1==NULL? h2:h1; //Ternary operator
    }

    ListNode *mergeTwoListsIterative(ListNode *list1, ListNode *list2)
    {
        if (!list2 && !list1)
        {
            return nullptr;
        }
        if (!list2)
        {
            return list1;
        }
        if (!list1)
        {
            return list2;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                ListNode *newNode = new ListNode(temp1->val);
                if (dummy->next == nullptr)
                {
                    dummy->next = newNode;
                }
                temp->next = newNode;
                temp1 = temp1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(temp2->val);
                if (dummy->next == nullptr)
                {
                    dummy->next = newNode;
                }
                temp->next = newNode;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        while (temp1)
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while (temp2)
        {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    // Function to merge two sorted linked lists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Create a dummy node to serve as
        // the head of the merged list
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr)
        {
            /*Compare elements of both lists
            and link the smaller node
            to the merged list*/
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer
            // to the next node
            temp = temp->next;
        }

        /*If any list still
        has remaining elements,
        append them to the merged list*/
        if (list1 != nullptr)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }

        // Return merged list
        return dummyNode->next;
    }
};
int main()
{
    return 0;
}