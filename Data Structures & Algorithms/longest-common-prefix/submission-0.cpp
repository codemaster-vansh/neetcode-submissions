class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        //Find smallest string
        int len = INT_MAX;
        for (int i = 0;i < n;i++) {
            if (strs[i].length() < len) {
                len = strs[i].length();
            }
        }

        //Solution
        string answer = "";
        int idx = 0;
        while (idx < len) {
            bool flag = true;
            char c = strs[0][idx];

            for (int i = 0;i < n;i++) {
                if (strs[i][idx] != c) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                break;
            } else {
                idx++;
                answer.push_back(c);
            }
        }

        return answer;
    }
};