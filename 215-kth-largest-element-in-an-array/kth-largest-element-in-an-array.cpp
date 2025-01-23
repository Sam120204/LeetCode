
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k); // Looking for the (n-k)th smallest element
    }

private:
    int quickselect(vector<int>& nums, int left, int right, int k) {
        // Use the last element as the pivot
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k) {
            // Found the k-th smallest element
            return nums[pivotIndex];
        } else if (pivotIndex < k) {
            // Recur on the right side
            return quickselect(nums, pivotIndex + 1, right, k);
        } else {
            // Recur on the left side
            return quickselect(nums, left, pivotIndex - 1, k);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        // Pivot is the last element
        int pivot = nums[right];
        int storeIndex = left; // Tracks the position for the next smaller element

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[storeIndex]);
                ++storeIndex;
            }
        }

        // Place pivot in its correct position
        swap(nums[storeIndex], nums[right]);

        return storeIndex; // Return the final pivot position
    }
};
