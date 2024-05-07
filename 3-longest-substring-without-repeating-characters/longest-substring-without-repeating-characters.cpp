class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int longest_sub_string = 1;
        for (int i = 0; i < s.size(); i++) {
            map<int, int> dict;
            for (int j = i; j < s.size(); j++) {
                if (dict.find(s[j]) != dict.end()) {
                    break;
                } else {
                    dict[s[j]] = 1;
                    longest_sub_string = max(longest_sub_string, j-i+1);
                }
            }
        }
        return longest_sub_string;
    }
};