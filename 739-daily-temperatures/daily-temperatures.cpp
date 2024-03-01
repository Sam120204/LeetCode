class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> nums;
        nums.push({temperatures[0], 0});
        int n = 1;
        while (n < days) {
            while ((!nums.empty()) and (temperatures[n] > nums.top().first)) {
                res[nums.top().second] = n - nums.top().second;
                nums.pop();
            }
            nums.push({temperatures[n], n});
            n++;
        }

        return res;
    }
};