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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        if (!list1 and !list2) {
            return list1;
        } else if (!list1) {
            return list2;
        } else if (!list2) { return list1; }
        ListNode* res = new  ListNode(0);
        ListNode* cur = res;

        while (head1 and head2) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
  
            } else if (head1->val > head2->val) {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;

            }
        }
        if (head1) cur->next = head1;
        if (head2) cur->next = head2;
        return res->next;
    }
};