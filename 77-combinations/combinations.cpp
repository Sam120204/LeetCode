class Solution {
    void backtracking(int n, int k, vector<vector<int>>& res, vector<int> combination, int start) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }
        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            backtracking(n, k, res, combination, i + 1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination;
        backtracking(n, k, res, combination, 1);
        return res;
    }
};
