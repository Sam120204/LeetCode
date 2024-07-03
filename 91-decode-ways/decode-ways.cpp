class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: an empty string has one way to be decoded (doing nothing)
        dp[1] = 1; // Base case: a single character string (not '0') has one way to be decoded

        for (int i = 2; i <= n; ++i) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));
            
            // If the single digit is valid (i.e., 1-9), add the number of ways to decode the string up to the previous character
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            
            // If the two-digit number is valid (i.e., 10-26), add the number of ways to decode the string up to the character before the previous character
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
