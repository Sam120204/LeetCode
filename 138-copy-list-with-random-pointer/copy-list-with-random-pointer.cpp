class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        Node* iter = head;
        
        // First pass: Make copy of each node,
        // and link them together side-by-side in a single list.
        while (iter != NULL) {
            Node* next = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }
        
        // Second pass: Assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        // Third pass: Restore the original list, and extract the copy list.
        iter = head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        
        while (iter != NULL) {
            Node* next = iter->next->next;
            
            // extract the copy
            copy->next = iter->next;
            
            // restore the original list
            iter->next = next;
            
            copy = copy -> next;
            iter = next;
        }
        
        return pseudoHead->next;
    }
};
