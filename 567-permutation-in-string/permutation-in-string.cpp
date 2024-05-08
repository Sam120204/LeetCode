class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;

        std::vector<int> s1Count(26, 0);
        std::vector<int> s2Count(26, 0);

        // Initialize the count for the characters in s1 and the first window in s2
        for (int i = 0; i < s1.size(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        if (s1Count == s2Count) {
            return true;
        }

        // Slide the window over the rest of s2 and update counts
        for (int i = s1.size(); i < s2.size(); ++i) {
            // Increment the count of the new character in the window
            s2Count[s2[i] - 'a']++;
            // Decrement the count of the character that is now outside the window
            s2Count[s2[i - s1.size()] - 'a']--;

            // Check if the current window matches the character counts of s1
            if (s1Count == s2Count) {
                return true;
            }
        }

        return false;
    }
};
