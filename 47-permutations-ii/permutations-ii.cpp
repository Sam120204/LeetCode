class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());  // Step 1: Sort to handle duplicates
        backtrack(nums, res, path, used);
        return res;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip used numbers
            if (used[i]) continue;
            
            // Pruning condition to avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            // Choose
            path.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, res, path, used);
            
            // Undo the choice (backtrack)
            used[i] = false;
            path.pop_back();
        }
    }
};