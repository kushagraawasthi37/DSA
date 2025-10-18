#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* segregateEvenOdd(Node* head) {
  
    // Result list to hold even nodes
    Node* resStart = nullptr;
    Node* resEnd = nullptr;

    // Pointers for the original list
    Node* curr = head;
    Node* prev = nullptr;

    // Move all even nodes from original
    // to result
    while (curr != nullptr) {
      
        // If current node is even
        if (curr->data % 2 == 0) {
          
            // Remove the current even node  from the original list
            if (prev != nullptr) {
                prev->next = curr->next;
            } else {
                // If the even node is at the head 
                head = curr->next; 
            }

            // Add the current even node to the result list
            if (resStart == nullptr) {
                resStart = curr;
                resEnd = resStart;
            } else {
                resEnd->next = curr;
                resEnd = resEnd->next;
            }

            curr = curr->next;
        } 
      
        // If the node is odd, just move to the next
        else {            
            prev = curr;
            curr = curr->next;
        }
    }

    // If there are no even nodes, return
    // the original list
    if (resStart == nullptr)
        return head;

    // Append the remaining original list
    // (odd nodes) to the result list
    resEnd->next = head;

    // Return the result list (starting with even nodes)
    return resStart;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    // Let us create a sample linked list as following
    // 0->1->4->6->9->10->11
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);

    cout << "Original Linked list: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "\nModified Linked list: ";
    printList(head);

    return 0;
}