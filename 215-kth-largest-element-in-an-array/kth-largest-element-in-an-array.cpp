class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // initialize min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            // we need to compare current ele to the min - root of minheap
            if (nums[i] > minHeap.top()) {
                // remove smallest ele
                minHeap.pop();
                // adding current ele to the minHeap
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};