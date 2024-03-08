class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (target == sum) return {start+1, end+1};
            if (sum < target) start++;
            else end--;
        }
        return {};
    }
};