#include <vector>
#include <algorithm>

class Solution {
public:
    bool if_ok(std::vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Ensures proper rounding up without using ceil
        }
        return hours <= h; // You want to check if Koko can finish within h hours, not more
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); // Directly use max_element to find the maximum in piles

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (if_ok(piles, mid, h)) {
                high = mid; // If Koko can finish at this rate, try a slower rate
            } else {
                low = mid + 1; // If Koko cannot finish, increase the rate
            }
        }
        return low; // The lowest feasible rate at which Koko can eat all bananas within h hours
    }
};
