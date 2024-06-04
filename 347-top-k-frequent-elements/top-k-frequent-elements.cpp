class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> m;
       int max_count = 1;
       for (auto &i : nums) max_count = max(max_count, ++m[i]);
       vector<vector<int>> bucket(max_count + 1); // Corrected here
       
       for (auto &i : m) {
           bucket[i.second].push_back(i.first);
       }
       
       vector<int> res;
       for (int i = max_count; i > -1 && res.size() < k; i--) { // Corrected here
           for (const int &num : bucket[i]) {
               res.push_back(num);
               if (res.size() == k) break;
           }
       }
       
       return res;
    }
};
