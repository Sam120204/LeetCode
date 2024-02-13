class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> v;
        for (auto& i : strs) {
            string cpy = i;
            sort(cpy.begin(), cpy.end());
            v.emplace_back(cpy);
        }
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < v.size(); i++) {
            if (map.count(v[i])) map[v[i]].emplace_back(i);
            else map[v[i]] = {i};
        }
        vector<vector<string>> res;
        for (auto& pair:map) {
            vector<string> temp;
            for (auto& i : pair.second) {
                temp.emplace_back(strs[i]);
            }
            res.emplace_back(temp);
        }
        return res;

    }
};