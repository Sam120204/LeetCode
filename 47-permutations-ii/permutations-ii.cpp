class Solution {
    string encode(vector<int>& vec) {
        string s;
        for (int num : vec) {
            s += to_string(num) + ",";
        }
        return s;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sorting helps handle duplicates
        vector<vector<int>> res;
        queue<vector<int>> q;
        unordered_set<string> seen;
        
        q.push({});
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            if (curr.size() == nums.size()) {
                res.push_back(curr);
                continue;
            }
            
            for (int i = 0; i < nums.size(); i++) {
                if (count(curr.begin(), curr.end(), nums[i]) < count(nums.begin(), nums.end(), nums[i])) {
                    vector<int> next = curr;
                    next.push_back(nums[i]);
                    
                    string key = encode(next);  // Encode permutation
                    if (!seen.count(key)) {
                        seen.insert(key);
                        q.push(next);
                    }
                }
            }
        }
        return res;
    }
};