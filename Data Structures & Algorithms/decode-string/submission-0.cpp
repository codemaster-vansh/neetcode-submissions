class Solution {
public:
    string decodeString(string s) {
        string curr_str = "";
        int curr_num = 0;
        stack<pair<string,int>> st1;

        for (char c : s) {
            if (std::isdigit(c)) {
                int num1 = c - '0';
                curr_num = curr_num * 10 + num1;
            } else if (c == '[') {
                st1.push({curr_str,curr_num});
                curr_str = "";
                curr_num = 0;
            } else if (c == ']') {
                auto [a,b] = st1.top();
                st1.pop();
                string reps = "";
                for (int i = 0;i < b;i++) {
                    reps += curr_str;
                }

                curr_str = a + reps;
            } else {
                curr_str += c;
            }
        }

        return curr_str;
    }
};