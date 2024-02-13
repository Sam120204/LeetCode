class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map; 
        for (auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].emplace_back(str); 
        }
        
        vector<vector<string>> res;
        for (auto& pair : map) {
            res.emplace_back(pair.second); 
        }
        return res;
    }
};
