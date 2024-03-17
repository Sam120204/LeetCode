class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size()+1, 0);
        dp[0] = nums[0], dp[1] = nums[1];
        for (int i = 2; i < dp.size(); i++) {
            if (i == dp.size()-1) dp[i] = max(dp[i-1],dp[i-2]);
            else {
                for (int j=0; j < i-1; j++) {
                    if (j < i) dp[i] = max(dp[j]+ nums[i], dp[i]);
                }
                
            }
        }
        return dp[len];
    }
};