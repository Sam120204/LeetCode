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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        stack<ListNode*> lst;
        lst.push(head);
        head = head->next;
        while (head) {
            lst.push(head);
            head = head->next;
        }
        
        ListNode* t = lst.top();
        lst.pop();
        ListNode* res = t;
        
        while (!lst.empty()) {
            res->next = lst.top();
            lst.pop();
            res = res->next;
        }
        res->next = nullptr;
        return t;
    }
};