class MinStack {
    stack<int> s;
    stack<int> s2;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (s2.empty() || val <= s2.top()) {
            s2.push(val);
        }
    }
    
    void pop() {
        if (!s.empty()) {
            int topVal = s.top();
            s.pop();
            if (!s2.empty() && topVal == s2.top()) {
                s2.pop();
            }
        }
    }
    
    int top() {
        if (s.empty()) return 0;
        return s.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */