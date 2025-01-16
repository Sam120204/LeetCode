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
        if (!head || !head->next) {
            return nullptr; // No cycle if the list is empty or has only one node.
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;            // Move slow pointer by one step
            fast = fast->next->next;      // Move fast pointer by two steps

            if (slow == fast) {           // Cycle detected
                // Step 2: Find the cycle start
                ListNode *entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry; // Cycle start node
            }
        }

        return nullptr; // No cycle detected
    }
};

// Helper function to create a cycle in the linked list for testing
void createCycle(ListNode *head, int pos) {
    if (pos == -1) return;

    ListNode *cycleNode = nullptr;
    ListNode *tail = head;
    int index = 0;

    while (tail->next) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create the cycle
}
