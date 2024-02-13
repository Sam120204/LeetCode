class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (m.count(complement) && m[complement] != i) return {i, m[complement]};
        }
        return {};
    }
};