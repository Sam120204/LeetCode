#include <vector>
#include <algorithm> // For using standard algorithms if needed

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> vec(ratings.size(), 1);
        
        // First pass: left to right
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                vec[i] = vec[i - 1] + 1;
            }
        }
        
        // Second pass: right to left
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                vec[i] = std::max(vec[i], vec[i + 1] + 1);
            }
        }
        
        // Calculate the sum
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) {
            sum += vec[i];
        }
        
        return sum;
    }
};
