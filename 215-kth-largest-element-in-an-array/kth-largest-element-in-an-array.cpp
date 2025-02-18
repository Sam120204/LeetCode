class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end(), [](int n1, int n2){
            return n1 > n2;
        });
        return nums[k-1];
    }
};