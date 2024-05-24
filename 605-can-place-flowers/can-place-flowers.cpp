class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num =0;
        int ns = flowerbed.size();
        for (int i = 0; i < ns; i++) {
            if (i == 0) {
                if (i+1 < ns and flowerbed[i+1] == 0 and flowerbed[i] == 0) {
                    num++;
                    flowerbed[i] = 1;
                } else if (i+1>=ns and flowerbed[i] == 0) {
                    num++;
                    flowerbed[i] = 1;
                }
            } else if (i == ns-1) {
                if (flowerbed[i-1] == 0 and flowerbed[i] == 0) num++;
            
            } else {
                if (flowerbed[i-1] == 0 and flowerbed[i+1] == 0 and flowerbed[i] == 0) {
                    num++;
                    flowerbed[i] = 1;
                }
            }
            
        }
        cout << num << endl;
        return num >= n;
    }
};