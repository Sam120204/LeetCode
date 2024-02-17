class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid;
                } else { start = mid + 1; }

            } else {
                if (nums[mid] < target && target <= nums[end - 1]) {
                    start = mid + 1;
                } else { end = mid; }
            }
        }
        return -1;
    }
};