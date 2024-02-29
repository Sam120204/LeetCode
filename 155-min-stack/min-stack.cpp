class MinStack {
    stack<int> s;
public:
    MinStack() {}
    
    void push(int val) {
        // if (s.empty()) {
        //     s.push(val);
            
        // } else {
        //     minn = min(minn, val);
        //     s.push(val);
        // }
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        if (s.empty()) return 0;
        return s.top();
    }
    
    int getMin() {
        stack<int> s2(s);
        int minn = INT_MAX;
        while (!s2.empty()) {
            minn = min(minn, s2.top());
            s2.pop();
        }
        return minn;
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