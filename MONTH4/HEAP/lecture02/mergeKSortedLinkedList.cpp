#include <bits/stdc++.h>
using namespace std;

class node
{
    // Creating the structure of node
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

node *mergeKLinkedList(vector<node *> &listArr)
{
    priority_queue<node *, vector<node *>, compare> minheap;

    int k = listArr.size();

    if (k == 0)
    {
        return NULL;
    }

    // step1 :
    for (int i = 0; i < k; i++)
    {
        if (listArr[i] != NULL)
        {
            minheap.push(listArr[i]);
        }
    }

    node *head = NULL;
    node *tail = NULL;

    while (minheap.size() > 0)
    {

        node *top = minheap.top();
        minheap.pop();

        // Update the answer

        // First Node in Answer LinkedList
        if (head == NULL)
        {

            // Answer LinkedList Empty
            head = top;
            tail = top;
        }
        else
        {
            // Insert at linked list
            tail->next = top;
            tail = top;
        }

        // Uss list ke aage ke node check kro agar ho to add kro
        if (top->next != NULL)
        {
            minheap.push(top->next);
        }
    }

    return head;
}

int main()
{
    // Creating k sorted linked lists
    node *list1 = new node(1);
    list1->next = new node(4);
    list1->next->next = new node(5);

    node *list2 = new node(1);
    list2->next = new node(3);
    list2->next->next = new node(4);

    node *list3 = new node(2);
    list3->next = new node(6);

    // Store them in a vector
    vector<node *> listArr = {list1, list2, list3};

    // Merge all lists
    node *mergedHead = mergeKLinkedList(listArr);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    while (mergedHead != NULL)
    {
        cout << mergedHead->data << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}
