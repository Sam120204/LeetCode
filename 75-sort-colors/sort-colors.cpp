class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3);
        for (auto & i : nums) bucket[i]++;
        int i = 0;
        int j = 0;

        while (i < 3) {
            if (bucket[i] > 0) {
                int m = bucket[i];
                while (m > 0) {
                    nums[j] = i;
                    j++;
                    m--;
                }
            }
            i++;
        }
    }
};