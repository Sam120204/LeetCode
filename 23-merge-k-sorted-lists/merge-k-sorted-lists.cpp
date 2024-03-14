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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

    // Helper function to merge lists from start to end
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid + 1, end);
        return merge_sort(left, right); // Assuming merge_sort correctly merges two lists
    }


    ListNode* merge_sort(ListNode* lst1, ListNode* lst2) {
        ListNode* prehead = new ListNode(0);
        ListNode* cur = prehead;
        while (lst1 and lst2) {
            if (lst1->val < lst2->val) {
                cur->next = lst1;
                cur = cur->next;
                lst1 = lst1->next;
            } else {
                cur->next = lst2;
                cur = cur->next;
                lst2 = lst2->next;
            }
        }
        if (lst1) {
            cur->next = lst1;
        }
        if (lst2) {
            cur->next = lst2;
        }
        return prehead->next;

    }
};