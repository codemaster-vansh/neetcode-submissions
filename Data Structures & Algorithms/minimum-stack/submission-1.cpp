class MinStack {
    stack<int> st1, min_tracker;
public:
    MinStack() {}
    
    void push(int val) {
        if (st1.empty()) {
            st1.push(val);
            min_tracker.push(val);
            return;
        }
        int min1 = min(min_tracker.top(),val);
        st1.push(val);
        min_tracker.push(min1);
    }
    
    void pop() {
        if (st1.empty() && min_tracker.empty()) return;
        st1.pop();
        min_tracker.pop();
    }
    
    int top() {
        if (st1.empty()) {
            return -1;
        }
        return st1.top();
    }
    
    int getMin() {
        if (st1.empty()) {
            return -1;
        }
        return min_tracker.top();
    }
};
