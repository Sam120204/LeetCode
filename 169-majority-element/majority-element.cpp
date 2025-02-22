class Solution {
public:
    int countInRange(const vector<int>& nums, int num, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == num) count++;
        }
        return count;
    }

    // Divide and conquer function to find the majority element
    int majorityElementRec(const vector<int>& nums, int left, int right) {
        // Base case: only one element
        if (left == right) return nums[left];

        // Divide step
        int mid = left + (right - left) / 2;
        int leftMajor = majorityElementRec(nums, left, mid);
        int rightMajor = majorityElementRec(nums, mid + 1, right);

        // If both halves agree on the majority element, return it
        if (leftMajor == rightMajor) return leftMajor;

        // Count occurrences of both candidates
        int leftCount = countInRange(nums, leftMajor, left, right);
        int rightCount = countInRange(nums, rightMajor, left, right);

        // Return the one that appears more than n/2 times
        return (leftCount > rightCount) ? leftMajor : rightMajor;
    }

    // Main function to find majority element
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};