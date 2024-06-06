class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3,0);
        for (const auto & i : nums) {
            bucket[i]++;
        }
        nums = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < bucket[i];j++) {
                nums.push_back(i);
            }
        }
    }
};