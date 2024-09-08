class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        // & in C++:
        // Reference: pass by reference using &
        // save time, originial element
        // const auto &: cannot modify and save time 
        for (const auto& ch : s) {
            // case of left par
            if (m.find(ch) == m.end()) par.push(ch);
            else {
                // early return
                if (par.empty()) return false;
                if (m[ch] == par.top()) par.pop();
                else return false;
            }
        }
        return par.empty();
    }
};