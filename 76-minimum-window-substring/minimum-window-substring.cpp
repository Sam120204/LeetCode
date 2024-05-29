#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return ""; // If t is larger than s, no solution exists

        std::unordered_map<char, int> dict;
        std::unordered_map<char, int> tracking;
        for (const auto& i : t) dict[i]++;
        
        int l = 0, r = 0, minLength = INT_MAX, minStart = 0;
        int required = dict.size(); // Number of unique characters in t to be matched
        int formed = 0; // Number of unique characters in the current window that match the requirement
        
        // Expand the right end of the window
        while (r < s.size()) {
            char c = s[r];
            tracking[c]++;
            
            // If the current character's frequency in the window matches its frequency in t
            if (dict.find(c) != dict.end() && tracking[c] == dict[c]) {
                formed++;
            }
            
            // Contract the window from the left as much as possible while it's valid
            while (l <= r && formed == required) {
                c = s[l];
                
                // Update the result if this window is smaller
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    minStart = l;
                }
                
                tracking[c]--;
                if (dict.find(c) != dict.end() && tracking[c] < dict[c]) {
                    formed--;
                }
                
                l++;
            }
            
            r++;
        }
        
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
