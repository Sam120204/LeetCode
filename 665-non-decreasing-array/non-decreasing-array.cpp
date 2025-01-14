class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;  // Count of violations
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {  // Found a violation
                count++;
                if (count > 1) return false;  // More than one violation
                
                // Fix the violation
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];  // Modify nums[i-1]
                } else {
                    nums[i] = nums[i - 1];  // Modify nums[i]
                }
            }
        }
        
        return true;
    }
};
