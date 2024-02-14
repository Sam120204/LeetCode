class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for (auto& i : nums) { dict[i] += 1; }
       
        vector<pair<int, int>> res;

        for (auto& p : dict) {
            res.emplace_back(p);
        }

        sort(res.begin(), res.end(), [](const auto& a, const auto& b) { return a.second > b.second; } );
        vector<int> r;
        int i = 0;
        while (k > 0) {
            r.emplace_back(res[i].first);
            k--;
            i++;
        }
        return r;

    }
};