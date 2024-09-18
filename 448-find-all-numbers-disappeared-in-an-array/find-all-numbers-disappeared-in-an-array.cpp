class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            res[nums[i]-1] = 1;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == -1) {
                output.emplace_back(i+1);
            }
        }
        return output;
    }
};