class Solution {
    void backtrack(vector<int>& nums, int level, vector<vector<int>>& res) {
        if (level == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]);
            backtrack(nums, level + 1, res);
            swap(nums[i], nums[level]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};