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
// pointer: nullptr
// - pointing to a memory address
// - how to get access/read to this memory?
//     int head->val
//     ListNode* head->next

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
        // stack [5,4,3,2,1]
        ListNode* res = lst.top(); // 5
        lst.pop();
        ListNode* iter = res;// iterate stack

        while (!lst.empty()) {
            iter->next = lst.top();
            lst.pop();
            iter = iter->next;
        }
        iter->next = nullptr;
        return res;
    }
};