class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> dict;
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]] = i;
        }
        int end = dict[s[0]], len = 1;
        vector<int> res = {};
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] > end) {
                end = dict[s[i]];
            }
            if (i == end) {
                res.emplace_back(len);
                if (i+1 < s.size()) {
                    end = dict[s[i+1]];
                    len = 1;
                }
            } else {
                len++;
            }
        }
        return res;
    }
};