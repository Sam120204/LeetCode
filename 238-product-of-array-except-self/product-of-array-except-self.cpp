class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = {1}, suffix = {1};
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            prefix.emplace_back(prefix[i] * nums[i]);
        }

        for (int i = len - 1; i >= 1; i--) {
            suffix.emplace_back(suffix[len - 1 - i] * nums[i]);
        }

        for (int i = 0; i < len; i++) {
            prefix[i] *= suffix[len-i-1];
        }
        return prefix;
    }
};