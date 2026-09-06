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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // 8 3  13 2 5
public:
    ListNode* removeNodes(ListNode* head) {
        int maxVal = 0;

        head = reverse(head);
        ListNode* prev = head;
        ListNode* temp = head;

        while (temp) {
            maxVal = max(maxVal, temp->val);
            if (temp->val >= maxVal) {
                prev = temp;
            } else {
                prev->next = temp->next;
            }

            temp = temp->next;
        }

        head=reverse(head);

        return head;
    }
};