#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& results, int& currentSum, vector<bool>& used, unordered_set<string>& seen) {
        if (currentSum == target) {
            string hash = createHash(used);
            if (seen.find(hash) == seen.end()) {
                results.push_back(current);
                seen.insert(hash);
            }
            return;
        }
        
        if (currentSum > target) return;
        
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) continue; // Skip duplicates
                
                used[i] = true;
                current.push_back(candidates[i]);
                currentSum += candidates[i];
                
                backtrack(candidates, target, current, results, currentSum, used, seen);
                
                currentSum -= candidates[i];
                current.pop_back();
                used[i] = false;
            }
        }
    }
    
    string createHash(const vector<bool>& used) {
        string hash;
        for (bool b : used) {
            hash += b ? '1' : '0';
        }
        return hash;
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> results;
        vector<int> current;
        int currentSum = 0;
        vector<bool> used(candidates.size(), false);
        unordered_set<string> seen;
        
        backtrack(candidates, target, current, results, currentSum, used, seen);
        
        return results;
    }
};
