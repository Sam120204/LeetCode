class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        graph(n, n-1, n, res, "(");
       
        return res;
    }

    void graph(int n, int num_left, int num_right, vector<string>& res, string temp) {
        if (num_left == 0) {
            temp += string(num_right, ')');
            res.emplace_back(temp);
            return;
        }

        graph(n, num_left-1, num_right, res, temp + "(");
        if (num_right > num_left) graph(n, num_left, num_right-1, res, temp + ")");
    }
};