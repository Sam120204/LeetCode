class Solution {
public:
    int rob(vector<int>& nums) {
        // [1, 2, 4, 4]
        // [2, 7, 11, 11, 12]
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
        
    }
};