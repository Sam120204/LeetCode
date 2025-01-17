class Solution {
    int findmin(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, res= -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                res=mid;
                r=mid-1;
            } else if (nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return res;
    }

    int findmax(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, res= -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) {
                res=mid;
                l=mid+1;
            } else if (nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findmin(nums, target);
        int r = findmax(nums, target);
        return {l, r};
    }
};