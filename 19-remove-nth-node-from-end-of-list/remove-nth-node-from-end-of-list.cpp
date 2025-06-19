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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        int count = 0;
        dummy->next = cur;
        while (cur) {
            cur = cur->next;
            count += 1;
        }
        ListNode* prev = dummy;
        for (int i = 0; i < count - n; i++) {
            prev = prev->next;
        }
        prev->next = prev->next ? prev->next->next : nullptr;
        return dummy->next;
    }
};