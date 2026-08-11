class StockSpanner {
    stack<int> st1, st2;
public:
    StockSpanner() : st1(), st2() {
        
    }
    
    int next(int price) {
        if (st1.empty()) {
            st1.push(price);
            return 1;
        } else {
            int count = 1;
            while (!st1.empty() && st1.top() <= price) {
                count++;
                int x = st1.top();
                st1.pop();
                st2.push(x);
            }

            while (!st2.empty()) {
                int x = st2.top();
                st2.pop();
                st1.push(x);
            }

            st1.push(price);
            return count;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */