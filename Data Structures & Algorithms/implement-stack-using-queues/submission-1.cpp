class MyStack {
    deque<int> queue1;
    int n;
public:
    MyStack() : queue1() {
        n = 0;
    }
    
    void push(int x) {
        queue1.push_back(x);
        int n1 = n;
        while (n1 != 0) {
            queue1.push_back(queue1.front());
            queue1.pop_front();
            n1--;
        }
        n++;
    }
    
    int pop() {
        int x = queue1.front();
        queue1.pop_front();
        n--;
        return x;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return (n == 0);
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