class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr=head;

        while(curr!=NULL)
        {
            Node *temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        curr=head;

        while(curr!=NULL)
        {
            if (curr->random!=NULL)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        curr=head;
        Node *dummy=new Node(-1);
        Node *ans=dummy;
        while(curr!=NULL)
        {
            ans->next=curr->next;
            curr->next=curr->next->next;

            ans=ans->next;
            curr=curr->next;
        }
        return dummy->next;

    }
};