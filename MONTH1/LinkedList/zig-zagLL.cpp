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


// At odd positions (1st, 3rd, 5th, …) → value should be less than the next node

// At even positions (2nd, 4th, 6th, …) → value should be greater than the next node

class Zig_Zag
{
public:
   void swap(int &a, int &b)
   {
      int temp = a;
      a = b;
      b = temp;
   }

   Node *zigZag(Node *head)
   {
      if (!head || !head->next)
         return head;

      Node *curr = head;
      bool odd = true; // at odd index we want curr < next

      while (curr->next != NULL)
      { // ✅ fix: stop at second-last node
         if (odd)
         {
            // enforce curr < next
            if (curr->data > curr->next->data)
            {
               swap(curr->data, curr->next->data);
            }
         }
         else
         {
            // enforce curr > next
            if (curr->data < curr->next->data)
            {
               swap(curr->data, curr->next->data);
            }
         }

         odd = !odd;
         curr = curr->next;
      }
      return head;
   }
};

class Solution
{
public:
   Node *zigZag(Node *head)
   {
      // your code goes here
      if (!head)
      {
         return head;
      }

      Node *curr = head;            // 11
      Node *firstnext = curr->next; // 15
      Node *secondnext = firstnext->next;
      Node *thirdnext = secondnext->next; // 5

      while (thirdnext != NULL)
      {
         curr->next = secondnext;
         firstnext->next = thirdnext;
         secondnext->next = firstnext;

         curr = curr->next;
         firstnext = curr->next; // 15
         secondnext = firstnext->next;
         thirdnext = secondnext->next; // 5
      }

      return head;
   }
};

// 🔹 Function to print linked list
void printList(Node *head)
{
   Node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}

int main()
{
   Node *head = new Node(89);
   head->next = new Node(19);
   head->next->next = new Node(59);
   head->next->next->next = new Node(32);
   head->next->next->next->next = new Node(92);

   cout << "Original list: ";
   printList(head);

   Solution obj;
   head = obj.zigZag(head);

   cout << "After zigZag: ";
   printList(head);
   return 0;
}