class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int width = books[i-1][0], height = books[i-1][1];
            dp[i] = dp[i-1] + height;
            for (int j = i-1; j>0; j--) {
                int prev_w = books[j- 1][0], prev_h = books[j- 1][1];
                width += prev_w;
                if (width > shelfWidth) break;
                height = max(height, prev_h);
                dp[i] = min(dp[i], dp[j-1]+height);
            }
        }
        return dp[n];
    }
};