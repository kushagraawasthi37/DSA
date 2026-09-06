class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode* dummy = head;

        ListNode* oddNode = head;
        ListNode* firstEven = head->next;

        ListNode* evenNode = head->next;

        while (evenNode && evenNode->next) {
            oddNode->next = oddNode->next->next;
            evenNode->next = evenNode->next->next;

            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = firstEven;

        return dummy;
    }
};