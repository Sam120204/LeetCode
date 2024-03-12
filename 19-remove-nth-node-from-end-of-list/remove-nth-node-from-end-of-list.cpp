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
        ListNode* cpy = head;
        int num = 0;
        vector<int> lst;
        while (cpy) {
            lst.push_back(cpy->val);
            num++;
            cpy = cpy -> next;
        }

        int len = num - n;
        lst[len] = -1;
      
        ListNode* res = new ListNode(0);
        ListNode* front = res;
        for (int i = 0; i < lst.size(); i++) {
            if (lst[i] >= 0) {
                ListNode* cur = new ListNode(lst[i]);
                res->next = cur;
                res = res->next;
            }
        }
        return front->next;
    }
};