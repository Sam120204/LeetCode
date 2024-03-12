class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> dict;
        for (const auto & i : nums) {
            if (dict.find(i) == dict.end()) {
                dict[i]++;
            } else {
                return i;
            }
        }
        return 0;
    }
};