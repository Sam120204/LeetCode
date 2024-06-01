class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, res;
        while (l <= r) {
            int mid = l + (r-l)/2;
            cout << "mid is " << mid << endl;
            if (mid-1 >= 0 and nums[mid-1] == nums[mid]) {
                if ((mid-1-l) % 2 == 1) r = mid-2;
                else l = mid+1;
            } else if (mid+1 < nums.size() and nums[mid+1] == nums[mid]) {
                if ((r - mid-1) % 2 == 1) l = mid+2;
                else r = mid-1;
            } else { return nums[mid]; }
        }
        return res;
    }
};