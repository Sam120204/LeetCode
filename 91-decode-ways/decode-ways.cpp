class Solution {
public:
    int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;  // No valid decoding if starts with '0'

    int prev2 = 1, prev1 = 1;  // Equivalent to dp[i-2] and dp[i-1]
    
    for (int i = 1; i < s.size(); i++) {
        int curr = 0;
        
        // Single-digit valid decoding (1-9)
        if (s[i] >= '1' && s[i] <= '9') {
            curr += prev1;
        }

        // Two-digit valid decoding (10-26)
        int twoDigit = stoi(s.substr(i-1, 2)); // Convert "s[i-1]s[i]" to integer
        if (twoDigit >= 10 && twoDigit <= 26) {
            curr += prev2;
        }

        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
};