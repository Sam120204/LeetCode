class Solution {
    int quick_select(vector<int>& nums, int left, int right, int target) {
        int res = partition(nums, left, right);
        if (res == target) return nums[res];
        else if (res < target) {
            return quick_select(nums, res+1, right, target);
        } else {
            return quick_select(nums, left, res - 1, target);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int* pivot = &nums[right];
        int temp = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < *pivot) {
                swap(nums[temp], nums[i]);
                temp++;
            }
        }
        swap(*pivot, nums[temp]);

        return temp;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n-1, n-k);
    }
};