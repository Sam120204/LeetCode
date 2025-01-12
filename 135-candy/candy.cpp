#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 1); // Initialize all elements with 1 candy

        // Left-to-right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // Right-to-left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                arr[i] = max(arr[i], arr[i + 1] + 1);
            }
        }

        // Calculate the total candies
        return accumulate(arr.begin(), arr.end(), 0);
    }
};
