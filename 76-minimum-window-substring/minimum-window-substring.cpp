class Solution {
public:
    string minWindow(string s, string t) {
    if (t.empty() || s.empty()) {
        return "";
    }

    // Count characters in t
    unordered_map<char, int> t_count;
    for (char c : t) {
        t_count[c]++;
    }

    // Two pointers for the sliding window
    int left = 0, right = 0;
    int required = t_count.size(); // Number of unique characters in t
    int formed = 0; // Number of unique characters in the current window that match t

    // Track characters in the current window
    unordered_map<char, int> window_count;

    // Variables to track the minimum window
    int min_len = INT_MAX;
    int start_index = 0;

    while (right < s.size()) {
        // Include the current character in the window
        char c = s[right];
        window_count[c]++;

        // If this character is in t and its count matches the required count
        if (t_count.count(c) && window_count[c] == t_count[c]) {
            formed++;
        }

        // Try to contract the window
        while (left <= right && formed == required) {
            char char_left = s[left];

            // Update the minimum window
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_index = left;
            }

            // Remove the leftmost character from the window
            window_count[char_left]--;
            if (t_count.count(char_left) && window_count[char_left] < t_count[char_left]) {
                formed--;
            }

            left++; // Shrink the window
        }

        right++; // Expand the window
    }

    // Return the minimum window substring
    return min_len == INT_MAX ? "" : s.substr(start_index, min_len);
}
};