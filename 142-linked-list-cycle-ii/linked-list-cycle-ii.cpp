/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode * cur = head;
        map<ListNode*, int> hm;
        while (cur->next and hm.find(cur) == hm.end()) {
            
            hm[cur]=1;
            cur = cur->next;
        }
        if (hm.find(cur) != hm.end()) return cur;
        return nullptr;
    }
};