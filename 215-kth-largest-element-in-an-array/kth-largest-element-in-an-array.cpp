class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max_heap
        priority_queue<int> heap(nums.begin(), nums.end());
        for (int i = 0;  i < k-1; i++) {
            heap.pop();
        }
        return heap.top();
    }
};