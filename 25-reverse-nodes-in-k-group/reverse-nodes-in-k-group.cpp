
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }

        while (count >= k) {
            cur = reverseNextKNodesDeque(cur, k);
            count -= k;
        }

        return dummy.next;
    }

private:
    // Helper function to reverse the next k nodes in the list using a deque
    // Returns the new 'cur' pointer, pointing to the last node of the reversed group
    ListNode* reverseNextKNodesDeque(ListNode* cur, int k) {
        std::deque<ListNode*> dq;
        
        ListNode* node = cur->next; // The first node of the group to be reversed
        for (int i = 0; i < k; ++i) {
            dq.push_back(node);
            node = node->next;
        }

        // Reverse process using the deque
        cur->next = dq.back();
        dq.pop_back();
        ListNode* last = cur->next;
        
        while (!dq.empty()) {
            last->next = dq.back();
            dq.pop_back();
            last = last->next;
        }

        last->next = node; // Connect the reversed part with the next part of the list
        
        return last;
    }
};
