class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int prev_j = -1;
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < min(prefix.length(), strs[i].length())) {
                if (prefix[j] != strs[i][j]) {
                    break;
                }
                j++;
            }
            if (j != prev_j) {
                prefix = prefix.substr(0, j);
                prev_j = j;
            } else {
                continue;
            }
        }
        return prefix;
    }
};