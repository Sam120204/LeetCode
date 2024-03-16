class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        deque<ListNode*> dq;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* node = head;

        while (node != nullptr) {
            dq.push_back(node);
            node = node->next;
            if (dq.size() == k) {
                while (!dq.empty()) {
                    cur->next = dq.back();
                    dq.pop_back();
                    cur = cur->next;
                }
                cur->next = nullptr; // Important to avoid a cycle
            }
        }

        // If there are nodes left in dq (less than k), append them in original order
        if (!dq.empty()) {
            // To maintain the original order, nodes should be appended from the front of the deque
            while (!dq.empty()) {
                cur->next = dq.front();
                dq.pop_front();
                cur = cur->next;
            }
        }

        ListNode* toReturn = dummy->next;
        delete dummy; // Clean up the dummy head node
        return toReturn;
    }
};
