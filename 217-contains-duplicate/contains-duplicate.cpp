class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (const auto& i : nums) {
            if (dict.count(i)) return true;
            else dict[i] = 1;
        }

        return false;
    }
};