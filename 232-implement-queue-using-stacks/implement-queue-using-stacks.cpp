class MyQueue {
    stack<int> leftend;
    stack<int> rightend;
public:
    MyQueue() : leftend{}, rightend{} {
        
    }
    
    void push(int x) {
        rightend.push(x);
    }
    
    int pop() {
        peek();
        int top = leftend.top();
        leftend.pop();
        return top;
    }
    
    int peek() {
        if (leftend.empty()) {
            while (!rightend.empty()) {
                leftend.push(rightend.top());
                rightend.pop();
            }
        }
        return leftend.top();
    }
    
    bool empty() {
        return leftend.empty() and rightend.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */