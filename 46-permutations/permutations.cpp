class Solution {
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<vector<int>>& res, vector<bool>& is_seen) {
        if (permutation.size() == nums.size()) res.push_back(permutation);
        for (int i = 0; i < nums.size(); i++) {
            if (!is_seen[i]) { // we have not use it
                is_seen[i] = true;
                permutation.push_back(nums[i]);
                backtrack(nums, permutation, res, is_seen);
                permutation.pop_back();
                is_seen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> is_seen(nums.size(), false);
        vector<vector<int>> res;
        vector<int> permutation = {};
        backtrack(nums, permutation, res, is_seen);
        return res;
    }
};