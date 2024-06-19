class Solution {
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, map<vector<int>, int>& dict, vector<bool>& seen) {
        if (temp.size() == nums.size()) {
            if (dict.find(temp) == dict.end()) {
                dict[temp]++;
                res.push_back(temp);
            }
        }
        for (int i = 0; i < seen.size(); i++) {
            if (!seen[i]) {
                //can use
                seen[i] = true;
                temp.push_back(nums[i]);
                backtrack(nums, res, temp, dict, seen);
                temp.pop_back();
                seen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = {};
        map<vector<int>, int> dict{};
        vector<bool> seen(nums.size(), false);
        backtrack(nums, res, temp, dict,seen);
        return res;
    }
};