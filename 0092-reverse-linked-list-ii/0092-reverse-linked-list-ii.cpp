/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> findNode(ListNode* head, int data) {
        if (data == 1)
            return {nullptr, head};
        ListNode* temp = head;

        while (data-- > 2) {
            temp = temp->next;
        }

        return {temp, temp->next};
    }

    ListNode* reverse(ListNode* head) {
        if (!head)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || !head->next || left == right)
            return head;

        auto leftAns = findNode(head, left);
        auto rightAns = findNode(leftAns[1], right - left + 1);
        if (leftAns[0])
            leftAns[0]->next = nullptr;
        auto rightNodeNext = rightAns[1]->next;
        rightAns[1]->next = nullptr;

        // cout << leftAns[1]->val << " " << rightAns[1]->val << endl;

        ListNode* newHead = reverse(leftAns[1]);

        if (leftAns[0]) {
            cout << leftAns[0]->val << endl;
            leftAns[0]->next = newHead;
            newHead = head;
        }

        leftAns[1]->next = rightNodeNext;

        return newHead;
    }
};