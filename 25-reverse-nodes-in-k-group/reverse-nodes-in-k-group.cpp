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
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;

    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (head != nullptr) {
        // Stack to store k nodes
        stack<ListNode*> stk;
        ListNode* temp = head;
        // Push up to k nodes onto the stack
        for (int i = 0; i < k && temp != nullptr; i++) {
            stk.push(temp);
            temp = temp->next;
        }

        // Only reverse if we have k nodes
        if (stk.size() == k) {
            while (!stk.empty()) {
                cur->next = stk.top();
                stk.pop();
                cur = cur->next;
            }
            cur->next = temp; // Important to link the current list with the remaining part
            head = temp; // Move head to the start of the next group of nodes
        } else {
            // If we have less than k nodes, just link them directly without reversing
            cur->next = head;
            break; // Exit the loop as this is the last group
        }
    }
    return dummy.next;
}

};