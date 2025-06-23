class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     int cur = nums[0], n = nums.size(), count = 1;
    //     if (n == 1) return count;
    //     auto iter = nums.begin()+1;
    //     while (iter != nums.end()) {
    //         if (*iter == *(iter-1)) {
    //             iter = nums.erase(iter);
    //         } else {
    //             iter++;
    //         }
            
    //     }
    //     return nums.size();
    // }
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];  // ✅ Overwrite in-place
            }
        }
        return i + 1;  // ✅ Return new length
    }

};