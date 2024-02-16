class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        set<int> s(nums.begin(), nums.end());
        vector<int> s2(s.begin(), s.end());
        int max = 1, cur = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s2[i] - 1 == s2[i-1]) cur++;
            else {
                max = cur > max ? cur : max;
                cur = 1;
            }
        }
        max = cur > max ? cur : max;
        return max;
    }
};