class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<double> dp(target+1, 0);
        dp[0] = 1; // theres only one way to choose to get sum of 0
        for (int i = 1; i < target+1; i++) {
            for (auto num : nums) {
                if (i-num >= 0) {
                    dp[i] = dp[i-num] + dp[i];
                }
            }
        }
        return dp[target];
    }
};