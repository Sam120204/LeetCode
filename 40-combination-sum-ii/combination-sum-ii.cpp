#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& results, int& currentSum, vector<bool>& used, map<vector<bool>, int>& seen) {
        if (currentSum == target) {
            if (seen.find(used) == seen.end()) {
                results.push_back(current);
                seen[used] = 1;
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
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> results;
        vector<int> current;
        int currentSum = 0;
        vector<bool> used(candidates.size(), false);
        map<vector<bool>, int> seen;
        
        backtrack(candidates, target, current, results, currentSum, used, seen);
        
        return results;
    }
};
