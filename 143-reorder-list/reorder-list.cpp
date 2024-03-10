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
    void reorderList(ListNode* head) {
        vector<int> lst;
        ListNode* front = head;
        while (front) {
            lst.emplace_back(front->val);
            front = front->next;
        }
        int start = 1, end = lst.size()-1;
        while (start < end) {
            head->next = new ListNode(lst[end]);
            head = head->next;
            head->next = new ListNode(lst[start]);
            head = head->next;
            start++;
            end--;
        }
        if (start == end) head->next = new ListNode(lst[start]);
    }
};