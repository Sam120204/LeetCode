class MyStack {
    deque<int> q;
    int size;
public:
    MyStack() : q{}, size{0} {
    }
    
    void push(int x) {
        q.push_front(x);
        size++;
    }
    
    int pop() {
        int i = q[0];
        q.pop_front();
        size--;
        return i;
    }
    
    int top() {
        return q[0];
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */