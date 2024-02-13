class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map; // Map sorted string to vector of anagrams
        for (auto& str : strs) {
            string sortedStr = str; // Copy the original string
            sort(sortedStr.begin(), sortedStr.end()); // Sort the copy
            map[sortedStr].push_back(str); // Group anagrams together in the map
        }
        
        vector<vector<string>> res;
        for (auto& pair : map) {
            res.push_back(pair.second); // Each value in map is already a vector of grouped anagrams
        }
        return res;
    }
};
