class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> main_stack;
        for (const string& s : tokens) {
            if (s == "+") {
                int x2 = main_stack.top();
                main_stack.pop();
                int x1 = main_stack.top();
                main_stack.pop();
                main_stack.push(x1 + x2);
            } else if (s == "-") {
                int x2 = main_stack.top();
                main_stack.pop();
                int x1 = main_stack.top();
                main_stack.pop();
                main_stack.push(x1 - x2);
            } else if (s == "*") {
                int x2 = main_stack.top();
                main_stack.pop();
                int x1 = main_stack.top();
                main_stack.pop();
                main_stack.push(x1*x2);
            } else if (s == "/") {
                int x2 = main_stack.top();
                main_stack.pop();
                int x1 = main_stack.top();
                main_stack.pop();
                main_stack.push(x1/x2);
            } else {
                size_t pos;
                int c = stoi(s,&pos);
                main_stack.push(c);
            }
        }

        return main_stack.top();
    }
};
