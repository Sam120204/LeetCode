class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m1, m2;

        for (auto& i : s) {
            m1[i] += 1;
        }

        for (auto& i : t) {
            m2[i] += 1;
        }

        return m1 == m2;
    }
};