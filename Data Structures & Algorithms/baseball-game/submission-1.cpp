class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string s : operations) {
            char c = s[0];
            if (isdigit(c) || s.size() > 1) {
                int num = stoi(s);
                st.push(num);
            } else if (c == '+') {
                int c1 = st.top();
                st.pop();
                int c2 = st.top();
                int c3 = c1 + c2;
                st.push(c1);
                st.push(c3);
            } else if (c == 'D') {
                int c1 = st.top() * 2;
                st.push(c1);
            } else if (c == 'C') {
                st.pop();
            }
        }

        int result = 0;
        while (!st.empty()) {
            int c = st.top();
            result += c;
            st.pop();
        }

        return result;
    }
};