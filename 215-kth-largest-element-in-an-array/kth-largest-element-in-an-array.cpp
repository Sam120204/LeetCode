class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for (int j = k-1; j > 0; j--) {
            pq.pop();
        }
        return pq.top();
    }
};