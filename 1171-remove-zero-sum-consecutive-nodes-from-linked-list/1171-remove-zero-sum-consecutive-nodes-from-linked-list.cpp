class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> m;

        int sum = 0;
        ListNode* temp = &dummy;

        // Pass 1: store the LAST node for every prefix sum
        while (temp) {
            sum += temp->val;
            m[sum] = temp;
            temp = temp->next;
        }

        // Pass 2: remove zero-sum sequences
        sum = 0;
        temp = &dummy;

        while (temp) {
            sum += temp->val;

            temp->next = m[sum]->next;

            temp = temp->next;
        }

        return dummy.next;
    }
};