class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap; // Frequency map
        for (char c : s) {
            freqMap[c]++; // Count frequency
        }
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end()); // Vector of pairs
        sort(freqVec.begin(), freqVec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second; // Sort by frequency
        });
        string result;
        for (auto& p : freqVec) {
            result += string(p.second, p.first); // Build result string
        }
        return result;
    }
};