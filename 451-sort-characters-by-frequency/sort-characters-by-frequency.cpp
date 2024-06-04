#include <string>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict;
        int max_count;
        for (const auto & i : s) {
            max_count = max(max_count, ++dict[i]);
        }
        vector<vector<char>> bucket(max_count+1);
        for (const auto & i : dict) {
            bucket[i.second].push_back(i.first);
        }
        string res = "";
        for (int i = max_count; i >= 0; i--) {
            for (auto & ele : bucket[i]) {
                if (ele and i >= 0) res += string(i, ele);
            }
        }
        return res;
    }
};