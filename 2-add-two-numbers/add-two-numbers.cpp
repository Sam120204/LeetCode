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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* front = res;
        int dividend = 0;
        while (l1 and l2) {
            int summ = l1->val+dividend + l2->val;
            int remainder = summ%10;
            res->next = new ListNode(remainder);
            dividend = summ/10;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int summ = l1->val + dividend;
            int remainder = summ%10;
            res->next = new ListNode(remainder);
            dividend = summ/10;
            res = res->next;
            l1 = l1->next;
        }
        while (l2) {
            int summ = l2->val + dividend;
            int remainder = summ%10;
            res->next = new ListNode(remainder);
            dividend = summ/10;
            res = res->next;
            l2 = l2->next;
        }
        if (dividend > 0) res->next = new ListNode(dividend);
        return front->next;
    }


};