class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        map<char, char> m = {{')', '('}, {'}','{'}, {']','['}};
        for (const auto& ch : s) {
            if (m.find(ch) == m.end()) par.push(ch);
            else { 
                if (par.empty()) return false;
                if (m[ch] == par.top()) par.pop();
                else return false;
            }
        }
        return par.empty();
    }
};

