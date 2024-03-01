class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for (const auto& i : tokens) {
            if (!isoperator(i)) {
                int num = std::stoi(i);
                res.push(num);
            } else {
                int num1 = res.top();
                res.pop();
                int num2 = res.top();
                res.pop();
                res.push(compute(num2, num1, i));
            }
        }
        return res.top();
    }
    bool isoperator(const std::string& s) {
        return s == "+" or s == "-" or s == "*" or s == "/";
    }
    int compute(int x, int y, string op) {
        if (op == "+") {
            return x + y;
        } else if (op == "-") {
            return x - y;
        } else if (op == "*") {
            return x * y;
        } else {
            return x / y;
        }
        return 0;
    }
};