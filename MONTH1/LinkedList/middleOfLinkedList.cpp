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

    // Middle of LinkedList

    int middleOfLinkedList()
    {

        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        int count = 0;
        node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        int midIndex = count / 2; // Find the middle index

        // Handle odd and even length lists
        // Traverse to the middle element
        if (count % 2 == 0)
        {
            while (midIndex > 1)
            {
                temp = temp->next;
                midIndex--;
            }
            cout << "Middle Elements: " << temp->data << " and " << temp->next->data << endl;
        }
        //  1 2 3 4 5
        // 1 2 3
        else
        {
            while (midIndex > 0)
            {
                temp = temp->next;
                midIndex--;
            }
            cout << "Middle Element: " << temp->data << endl;
        }
        return count;
    }

    void betMiddleElement()
    {
        // TC->O(n)
        // SC->O(1)

        
        node *slow = head;
        node *fast = head;

        // For Even size Linked-List

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element data " << slow->data << endl;
    }
};
int main()
{
    List li;
    li.pushFront(5);
    li.pushFront(4);
    li.pushFront(3);

    cout << "Total element " << li.middleOfLinkedList();
    li.betMiddleElement();
    return 0;
}