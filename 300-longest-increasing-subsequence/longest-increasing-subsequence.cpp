class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int res = 0;
    //     if (nums.size() == 1) return 1;
    //     vector<int> dp(nums.size(), 1);
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j]+1);
    //             }
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return dp.size();
    }
};