class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;  // Handle edge case where x = 0
        int left = 1, right = x;  // Start at 1 to avoid division by zero
        int ans = 0;  // Store the result
        while (left <= right) {  // Use `<=` to include all possibilities
            int mid = left + (right - left) / 2;  // Prevent overflow
            if (mid <= x / mid) {  // Avoid overflow by using division instead of `mid * mid`
                ans = mid;  // Update potential answer
                left = mid + 1;  // Move to the right half
            } else {
                right = mid - 1;  // Move to the left half
            }
        }
        return ans;  // Return the largest `mid` such that `mid * mid <= x`
    }
};
