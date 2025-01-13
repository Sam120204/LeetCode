class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current spot is empty
            if (flowerbed[i] == 0) {
                // Check if the previous and next spots are empty or out of bounds
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Place a flower here
                    count++;
                }
            }
            
            // If we've placed enough flowers, return true
            if (count >= n) return true;
        }
        
        // If we finish the loop and haven't placed enough flowers
        return count >= n;
    }
};
