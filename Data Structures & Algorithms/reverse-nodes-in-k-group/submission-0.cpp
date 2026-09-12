class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp)
                return head;
            temp = temp->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};