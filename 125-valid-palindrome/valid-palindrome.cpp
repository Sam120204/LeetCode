class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> modify;
        for (const auto& ch : s) {
            if (ch >= 'a' and ch <= 'z' or ch >= 'A' and ch <= 'Z' or ch >= '0' and ch <= '9') {
                modify.emplace_back(tolower(ch));
            }
        }
        int len = modify.size();
        for (int i = 0; i < len / 2; i++) {
            if (modify[i] != modify[len-i-1]) return false;
        }
        return true;
    }
};