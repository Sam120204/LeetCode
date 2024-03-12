class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* h = head;
        
        while (h){
            nodes[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while (h){
            Node* newNode = nodes[h];
            newNode->next = nodes[h->next];
            newNode->random = nodes[h->random];
            h = h->next;
        }
        return nodes[head];
    }
};