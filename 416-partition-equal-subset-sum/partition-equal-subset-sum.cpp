#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();
        std::vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: a subset sum of 0 is always possible

        for (int i = 0; i < n; i++) { // Loop over each number in the input array
            for (int j = target; j >= nums[i]; j--) { // Traverse dp array backwards
                dp[j] = dp[j] || dp[j - nums[i]]; // Update the dp array
            }
        }
        
        return dp[target]; // Check if a subset with sum equal to target is possible
    }
};
